#pragma once

#include "Libraries/Systems/MultithreadingLibrary/Source/Public/MultithreadingCommon.h"
#include "Libraries/Systems/MultithreadingLibrary/Source/Public/Spinlock.h"
#include "Libraries/Systems/MultithreadingLibrary/Source/Public/ReadWriteSpinlock.h"
#include <string>
#include <atomic>
#include <mutex>

namespace Multithreading
{
	class JobManager;

	class JobThread
	{
	public:
		MULTITHREADING_USAGE JobThread(JobManager* jobManager);
		MULTITHREADING_USAGE JobThread(JobManager* jobManager, const std::string& name);

		MULTITHREADING_USAGE JobThread(JobThread&& other);
		MULTITHREADING_USAGE JobThread(const JobThread& other);
		MULTITHREADING_USAGE JobThread& operator=(JobThread&& other);
		MULTITHREADING_USAGE JobThread& operator=(const JobThread& other);

		MULTITHREADING_USAGE ~JobThread();

		MULTITHREADING_USAGE bool IsBusy() const;
		MULTITHREADING_USAGE bool IsIdle() const;

		MULTITHREADING_USAGE bool IsEnabled();
		MULTITHREADING_USAGE void SetEnabled(bool enabled);

		MULTITHREADING_USAGE void operator()();

	private:
		JobManager* m_jobManager;

		std::string m_name;

		bool m_enabled;

		unsigned long m_executedJobs;
		unsigned long m_iterations;

		Spinlock m_spinLock;

		std::mutex m_jobThreadMutex;
	};
};
