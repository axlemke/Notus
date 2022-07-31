#pragma once

#include "Libraries/Systems/MultithreadingLibrary/Source/Public/MultithreadingCommon.h"

#include "Libraries/Systems/MultithreadingLibrary/Source/Public/Spinlock.h"
#include "Libraries/Systems/MultithreadingLibrary/Source/Public/Benaphore.h"

#include "Libraries/Systems/MultithreadingLibrary/Source/Public/Jobs/Job.h"
#include "Libraries/Systems/MultithreadingLibrary/Source/Public/Jobs/JobMatrix.h"
#include "Libraries/Systems/MultithreadingLibrary/Source/Public/Jobs/JobThread.h"


#include <stack>
#include <vector>
#include <windows.h>

#include <atomic>
#include <intrin.h>
#include <thread>
#include <mutex>
#include <condition_variable>


namespace Multithreading
{
	class JobManager
	{
	public:
		MULTITHREADING_USAGE JobManager();
		MULTITHREADING_USAGE ~JobManager();

		MULTITHREADING_USAGE void Initialize();
		MULTITHREADING_USAGE void Deinitialize();

		MULTITHREADING_USAGE void ReserveThreadCount(unsigned short threadCount);
		MULTITHREADING_USAGE void ClearThreads();

		MULTITHREADING_USAGE bool IsBusy() const;

		MULTITHREADING_USAGE void Wait();

		MULTITHREADING_USAGE void ClearPendingJobs();
		MULTITHREADING_USAGE void AddPendingJob(Job& job);

		MULTITHREADING_USAGE bool HasPendingJobs();
		MULTITHREADING_USAGE Job GetPendingJob();


		MULTITHREADING_USAGE JobId GetNextJobId() const;

	private:
		void IncrementNextJobId();

		void Poll();

		std::vector<std::thread> m_threads;
		std::vector<JobThread> m_jobThreads;


		JobMatrix m_jobMatrix;


		std::condition_variable m_wakeCondition;

		std::atomic<UINT64> m_finishedLabel;

		std::mutex m_wakeMutex;

		std::mutex m_jobMutex;

		UINT64 m_currentLabel;
		JobId m_nextJobId;
	};
};
