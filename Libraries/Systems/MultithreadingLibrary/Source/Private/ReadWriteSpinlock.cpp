#include "Libraries/Systems/MultithreadingLibrary/Source/Public/ReadWriteSpinlock.h"

using namespace Multithreading;

ReadWriteSpinlock::ReadWriteSpinlock()
	: m_lock(0)
{
}
