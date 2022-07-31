#pragma once

#include "Libraries/Systems/MultithreadingLibrary/Source/Public/MultithreadingCommon.h"

#include <windows.h>
#include <intrin.h>

namespace Multithreading
{
	class Benaphore
	{
	public:
		MULTITHREADING_USAGE Benaphore();
		MULTITHREADING_USAGE ~Benaphore();

		MULTITHREADING_USAGE void Lock();
		MULTITHREADING_USAGE bool TryLock();
		MULTITHREADING_USAGE void Unlock();

	private:
		LONG m_counter;
		HANDLE m_semaphore;
	};
}
