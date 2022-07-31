#include "Libraries/Systems/MultithreadingLibrary/Source/Public/Benaphore.h"

using namespace Multithreading;

Benaphore::Benaphore()
	: m_counter(0)
{
	m_semaphore = CreateSemaphore(NULL, 0, 1, NULL);
}

Benaphore::~Benaphore()
{
	CloseHandle(m_semaphore);
}

void Benaphore::Lock()
{
	if (_InterlockedIncrement(&m_counter) > 1)
	{
		WaitForSingleObject(m_semaphore, INFINITE);
	}
}

bool Benaphore::TryLock()
{
	LONG result = _InterlockedCompareExchange(&m_counter, 1, 0);
	return (result == 0);
}

void Benaphore::Unlock()
{
	if (_InterlockedDecrement(&m_counter) > 0)
	{
		ReleaseSemaphore(m_semaphore, 1, NULL);
	}
}
