#pragma once

//
// Originally based off of StepTimer.h
//

#include "Systems/TimerSystem/Source/Public/TimerCommon.h"

#include <cmath>
#include <cstdint>
#include <exception>
#include <Windows.h>

namespace HaveBlue
{
    class GameTimer
    {
    public:
        TIMER_USAGE GameTimer();

        TIMER_USAGE UINT64 GetElapsedTicks() const;
        TIMER_USAGE double GetElapsedSeconds() const;
        TIMER_USAGE UINT64 GetTotalTicks() const;
        TIMER_USAGE double GetTotalSeconds() const;
        TIMER_USAGE UINT32 GetFrameCount() const;
        TIMER_USAGE UINT32 GetFramesPerSecond() const;

		template<typename PercisionFormat>
        PercisionFormat GetElapsedSecondsAs() const
		{
            return static_cast<PercisionFormat>(ConvertTicksToSeconds(m_elapsedTicks));
		}

		template<typename PercisionFormat>
		PercisionFormat GetTotalSecondsAs() const
		{
			return static_cast<PercisionFormat>(ConvertTicksToSeconds(m_totalTicks));
		}

		template<typename PercisionFormat>
		PercisionFormat GetElapsedTicksAs() const
		{
			return static_cast<PercisionFormat>(GetElapsedTicks());
		}

		template<typename PercisionFormat>
		PercisionFormat GetTotalTicksAs() const
		{
			return static_cast<PercisionFormat>(GetTotalTicks());
		}

        TIMER_USAGE void SetUseFixedTimeStep(bool isFixedTimestep);
        TIMER_USAGE void SetTargetElapsedTicks(UINT64 targetElapsed);
        TIMER_USAGE void SetTargetElapsedSeconds(double targetElapsed);

        TIMER_USAGE void SetMaxDelta(UINT64 maxDelta);

        static const UINT64 k_ticksPerMillisecond = 10000;

        // Integer format represents time using 10,000,000 ticks per second.
        static const UINT64 k_ticksPerSecond = 10000000;

        TIMER_USAGE static double ConvertTicksToSeconds(UINT64 ticks);
        TIMER_USAGE static UINT64 ConvertSecondsToTicks(double seconds);

        TIMER_USAGE void ResetElapsedTime();
        TIMER_USAGE void Update();

    private:
        void FixedTimeStepUpdate(UINT64 timeDelta);
        void VariableTimeUpdate(UINT64 timeDelta);

        // Source timing data uses QPC units.
        LARGE_INTEGER m_performanceFrequency;
        LARGE_INTEGER m_performanceCounterPrevious;
        UINT64 m_maxDelta;

        // Derived timing data uses a canonical tick format.
        UINT64 m_elapsedTicks;
        UINT64 m_totalTicks;
        UINT64 m_leftOverTicks;

        // Members for tracking the framerate.
        UINT32 m_frameCount;
        UINT32 m_framesPerSecond;
        UINT32 m_framesThisSecond;
        UINT64 m_performanceCounterSecondCounter;

        // Members for configuring fixed timestep mode.
        UINT64 m_targetElapsedTicks;
        bool m_useFixedTimeStep;
    };
}
