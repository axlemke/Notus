#include "Systems/TimerSystem/Source/Public/SimpleTimer.h"

#include "Systems/TimerSystem/Source/Public/GameTimer.h"

using namespace HaveBlue;

SimpleTimer::SimpleTimer()
	: m_elapsedTime(0)
	, m_maxTime(0)
{
}

void SimpleTimer::Update(const GameTimer& gameTimer)
{
	Update(gameTimer.GetElapsedSeconds());
}

void SimpleTimer::Update(double elapsedTimeSeconds)
{
	m_elapsedTime += elapsedTimeSeconds;
}

bool SimpleTimer::HasExpired() const
{
	if ((m_maxTime != 0.0) && (m_elapsedTime > m_maxTime))
	{
		return true;
	}
	return false;
}

void SimpleTimer::Reset()
{
	m_elapsedTime = 0;
}

double SimpleTimer::GetElapsedTime() const
{
	return m_elapsedTime;
}

void SimpleTimer::SetMaxTime(double maxLifetime)
{
	m_maxTime = maxLifetime;
}
