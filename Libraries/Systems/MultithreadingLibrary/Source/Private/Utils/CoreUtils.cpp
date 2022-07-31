#include "Libraries/Systems/MultithreadingLibrary/Source/Public/Utils/CoreUtils.h"

#include <thread>

unsigned int Multithreading::GetNumberOfSupportedConcurrentThreads()
{
	return std::thread::hardware_concurrency();
}
