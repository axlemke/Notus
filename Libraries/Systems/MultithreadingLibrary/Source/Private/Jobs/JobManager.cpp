#include "Systems/MultithreadingLibrary/Source/Public/Jobs/JobManager.h"

#include <Framework/LibraryShell/Source/Public/CustomAssert.h>
#include <Memory/MemoryLibrary/Source/Public/MemoryCommon.h>
#include "Systems/MultithreadingLibrary/Source/Public/Utils/CoreUtils.h"

using namespace Multithreading;

JobManager::JobManager()
	: m_nextJobId(0)
	, m_currentLabel(0)
{
}

JobManager::~JobManager()
{
}

void JobManager::Initialize()
{
	HB_ASSERT(m_jobThreads.empty());
	HB_ASSERT(m_threads.empty());

	if (m_jobThreads.empty())
	{
		m_finishedLabel.store(0);

		unsigned int numberOfCores = Multithreading::GetNumberOfSupportedConcurrentThreads();
		HB_ASSERT(numberOfCores > 0);

		unsigned int numberOfTargetJobTheads = numberOfCores - 1;

		if (true)
		{
			numberOfTargetJobTheads = max((numberOfTargetJobTheads / 2), 1);
		}

		m_jobThreads.reserve(numberOfTargetJobTheads);
		m_threads.reserve(numberOfTargetJobTheads);

		for (unsigned int coreIndex = 0; coreIndex < numberOfTargetJobTheads; ++coreIndex)
		{
			std::string jobThreadName = "JobThread: ";
			jobThreadName += std::to_string(coreIndex);

			JobThread jobThread(this, jobThreadName);
			m_jobThreads.push_back(jobThread);
		}

		for (unsigned int coreIndex = 0; coreIndex < numberOfTargetJobTheads; ++coreIndex)
		{
			m_threads.push_back(std::thread(std::ref(m_jobThreads[coreIndex])));
		}
	}
}

void JobManager::Deinitialize()
{
	{
		std::lock_guard<std::mutex> guard(m_jobMutex);

		for (JobThread& jobThread : m_jobThreads)
		{
			jobThread.SetEnabled(false);
		}
	}

	for (std::thread& thread : m_threads)
	{
		if (thread.joinable())
		{
			thread.join();
		}
	}

	m_jobThreads.clear();
	m_threads.clear();
}

void JobManager::ReserveThreadCount(unsigned short threadCount)
{
	m_threads.reserve(threadCount);
}

void JobManager::ClearThreads()
{
	m_threads.clear();
}

bool JobManager::IsBusy() const
{
	return false;
}

void JobManager::Wait()
{
	while (IsBusy())
	{
		Poll();
	}
}

void JobManager::Poll()
{
	m_wakeCondition.notify_one();
	std::this_thread::yield();
}

void JobManager::ClearPendingJobs()
{
	std::lock_guard<std::mutex> guard(m_jobMutex);
	m_jobMatrix.ClearPendingJobs();
}

void JobManager::AddPendingJob(Job& job)
{
	std::lock_guard<std::mutex> guard(m_jobMutex);
	m_jobMatrix.AddPendingJob(job);
}

bool JobManager::HasPendingJobs()
{
	bool locked = m_jobMutex.try_lock();

	if (locked)
	{
		bool hasJobs = m_jobMatrix.HasPendingJobs();
		m_jobMutex.unlock();
		return hasJobs;
	}
	return false;
}

JobId JobManager::GetNextJobId() const
{
	return m_nextJobId;
}

void JobManager::IncrementNextJobId()
{
	m_nextJobId++;
}

Job JobManager::GetPendingJob()
{
	std::lock_guard<std::mutex> guard(m_jobMutex);

	Job newJob(GetNextJobId());
	HB_ASSERT(m_jobMatrix.HasPendingJobs());

	IncrementNextJobId();
	//m_nextJobId++;

	return m_jobMatrix.GetPendingJob();;
}
