#pragma once

#include "Libraries/Systems/MultithreadingLibrary/Source/Public/MultithreadingCommon.h"

#include <windows.h>
#include <intrin.h>

namespace Multithreading
{
	class Spinlock
	{
	public:
		MULTITHREADING_USAGE Spinlock();
		MULTITHREADING_USAGE ~Spinlock();

		MULTITHREADING_USAGE bool Lock();
		MULTITHREADING_USAGE bool Unlock();

	private:
		volatile unsigned int m_lockSem;
	};
}
