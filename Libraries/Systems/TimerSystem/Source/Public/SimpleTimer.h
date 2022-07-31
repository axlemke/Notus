#pragma once

#include "Systems/TimerSystem/Source/Public/TimerCommon.h"

namespace HaveBlue
{
	class GameTimer;

	class SimpleTimer
	{
	public:
		TIMER_USAGE SimpleTimer();

		TIMER_USAGE void Update(const GameTimer& gameTimer);
		TIMER_USAGE void Update(double elapsedTimeSeconds);
		TIMER_USAGE bool HasExpired() const;
		TIMER_USAGE void Reset();
		TIMER_USAGE double GetElapsedTime() const;
		TIMER_USAGE void SetMaxTime(double maxLifetime);

	private:
		double m_elapsedTime;
		double m_maxTime;
	};
}
