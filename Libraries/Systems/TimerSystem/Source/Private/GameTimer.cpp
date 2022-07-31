#include "Libraries/Systems/TimerSystem/Source/Public/GameTimer.h"

using namespace HaveBlue;

GameTimer::GameTimer() 
:   m_elapsedTicks(0)
,   m_totalTicks(0)
,   m_leftOverTicks(0)
,   m_frameCount(0)
,   m_framesPerSecond(0)
,   m_framesThisSecond(0)
,   m_performanceCounterSecondCounter(0)
,   m_useFixedTimeStep(false)
,   m_targetElapsedTicks(k_ticksPerSecond / 60)
{
    if (!QueryPerformanceFrequency(&m_performanceFrequency))
    {
        throw std::exception("QueryPerformanceFrequency");
    }

    if (!QueryPerformanceCounter(&m_performanceCounterPrevious))
    {
        throw std::exception("QueryPerformanceCounter");
    }

    // Initialize max delta to 1 / 10th of a second.
    SetMaxDelta(static_cast<UINT64>(m_performanceFrequency.QuadPart / 10));
}

UINT64 GameTimer::GetElapsedTicks() const
{
    return m_elapsedTicks; 
}

double GameTimer::GetElapsedSeconds() const 
{ 
    return ConvertTicksToSeconds(m_elapsedTicks);
}

UINT64 GameTimer::GetTotalTicks() const
{ 
    return m_totalTicks; 
}

double GameTimer::GetTotalSeconds() const 
{ 
    return ConvertTicksToSeconds(m_totalTicks); 
}

UINT32 GameTimer::GetFrameCount() const
{ 
    return m_frameCount; 
}

UINT32 GameTimer::GetFramesPerSecond() const
{ 
    return m_framesPerSecond;
}

void GameTimer::SetUseFixedTimeStep(bool isFixedTimestep)
{ 
    m_useFixedTimeStep = isFixedTimestep; 
}

void GameTimer::SetTargetElapsedTicks(UINT64 targetElapsed)
{ 
    m_targetElapsedTicks = targetElapsed; 
}

void GameTimer::SetTargetElapsedSeconds(double targetElapsed)
{ 
    m_targetElapsedTicks = ConvertSecondsToTicks(targetElapsed); 
}

void GameTimer::SetMaxDelta(UINT64 maxDelta)
{
	m_maxDelta = maxDelta;
}

double GameTimer::ConvertTicksToSeconds(UINT64 ticks)
{ 
    return static_cast<double>(ticks) / k_ticksPerSecond; 
}
UINT64 GameTimer::ConvertSecondsToTicks(double seconds)
{ 
    return static_cast<UINT64>(seconds * k_ticksPerSecond);
}

void GameTimer::ResetElapsedTime()
{
    if (!QueryPerformanceCounter(&m_performanceCounterPrevious))
    {
        throw std::exception("QueryPerformanceCounter");
    }

    m_leftOverTicks = 0;
    m_framesPerSecond = 0;
    m_framesThisSecond = 0;
    m_performanceCounterSecondCounter = 0;
}

void GameTimer::Update()
{
	// Query the current time.
	LARGE_INTEGER performanceCounterCurrent;

	if (!QueryPerformanceCounter(&performanceCounterCurrent))
	{
		throw std::exception("QueryPerformanceCounter");
	}

	UINT64 timeDelta = static_cast<UINT64>(performanceCounterCurrent.QuadPart - m_performanceCounterPrevious.QuadPart);

	m_performanceCounterPrevious = performanceCounterCurrent;
	m_performanceCounterSecondCounter += timeDelta;

	// Clamp excessively large time deltas (e.g. after paused in the debugger).
	timeDelta = min(timeDelta, m_maxDelta);

	// Convert QPC units into a canonical tick format. This cannot overflow due to the previous clamp.
	timeDelta *= k_ticksPerSecond;
	timeDelta /= static_cast<UINT64>(m_performanceFrequency.QuadPart);

	uint32_t lastFrameCount = m_frameCount;

	if (m_useFixedTimeStep)
	{
		FixedTimeStepUpdate(timeDelta);
	}
	else
	{
		VariableTimeUpdate(timeDelta);
	}

	// Track the current framerate.
	if (m_frameCount != lastFrameCount)
	{
		m_framesThisSecond++;
	}

	if (m_performanceCounterSecondCounter >= static_cast<UINT64>(m_performanceFrequency.QuadPart))
	{
		m_framesPerSecond = m_framesThisSecond;
		m_framesThisSecond = 0;
		m_performanceCounterSecondCounter %= static_cast<UINT64>(m_performanceFrequency.QuadPart);
	}
}

void GameTimer::FixedTimeStepUpdate(UINT64 timeDelta)
{
	// If the app is running very close to the target elapsed time (within 1/4 of a millisecond) just clamp
	// the clock to exactly match the target value. This prevents tiny and irrelevant errors
	// from accumulating over time. Without this clamping, a game that requested a 60 fps
	// fixed update, running with vsync enabled on a 59.94 NTSC display, would eventually
	// accumulate enough tiny errors that it would drop a frame. It is better to just round
	// small deviations down to zero to leave things running smoothly.

	if (static_cast<UINT64>(std::abs(static_cast<int64_t>(timeDelta - m_targetElapsedTicks))) < k_ticksPerSecond / 4000)
	{
		timeDelta = m_targetElapsedTicks;
	}

	m_leftOverTicks += timeDelta;

	while (m_leftOverTicks >= m_targetElapsedTicks)
	{
		m_elapsedTicks = m_targetElapsedTicks;
		m_totalTicks += m_targetElapsedTicks;
		m_leftOverTicks -= m_targetElapsedTicks;
		m_frameCount++;
	}
}

void GameTimer::VariableTimeUpdate(UINT64 timeDelta)
{
	m_elapsedTicks = timeDelta;
	m_totalTicks += timeDelta;
	m_leftOverTicks = 0;
	m_frameCount++;
}