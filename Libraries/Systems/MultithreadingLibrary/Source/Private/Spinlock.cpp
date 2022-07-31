#include "Libraries/Systems/MultithreadingLibrary/Source/Public/Spinlock.h"

using namespace Multithreading;

Spinlock::Spinlock()
	: m_lockSem(0)
{
}

Spinlock::~Spinlock()
{
}

bool Spinlock::Lock()
{
	while (true)
	{
		if (!InterlockedCompareExchange(&m_lockSem, 1, 0))
		{
			// We successfully acquired the lock
			MemoryBarrier();
			return true;
		}
	}
	return false;
}

bool Spinlock::Unlock()
{
	MemoryBarrier();
	m_lockSem = 0;

	return true;
}
