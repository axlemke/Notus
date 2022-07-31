#pragma once

#include "Libraries/Systems/MultithreadingLibrary/Source/Public/MultithreadingCommon.h"

namespace Multithreading
{
	class ReadWriteSpinlock
	{
	public:
		MULTITHREADING_USAGE ReadWriteSpinlock();

	private:
		volatile unsigned long m_lock;
	};
}
