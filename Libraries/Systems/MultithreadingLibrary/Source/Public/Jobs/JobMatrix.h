#pragma once

#include "Libraries/Systems/MultithreadingLibrary/Source/Public/MultithreadingCommon.h"
#include "Libraries/Systems/MultithreadingLibrary/Source/Public/Jobs/Job.h"

#include <deque>
#include <stack>
#include <vector>

#include "Libraries/Systems/MultithreadingLibrary/Source/Public/Jobs/JobPriority.h"

namespace Multithreading
{
	class JobMatrix
	{
	public:
		MULTITHREADING_USAGE JobMatrix();
		MULTITHREADING_USAGE ~JobMatrix();


		MULTITHREADING_USAGE bool HasPendingJobs();
		MULTITHREADING_USAGE void AddPendingJob(Job& job);
		MULTITHREADING_USAGE Job GetPendingJob();

		MULTITHREADING_USAGE void CheckInProgressJobs();

		MULTITHREADING_USAGE void ClearPendingJobs();

	private:
		std::deque<Job>& GetPendingJobDeque(JobPriority priority);
		void IncrementNextJobId();

		std::deque<Job> m_pendingJobs[k_jobPriorityCount];


		std::vector<Job> m_inprogressJobs;
		std::stack<unsigned int> m_inprogressJobsSlots;
	};
};
