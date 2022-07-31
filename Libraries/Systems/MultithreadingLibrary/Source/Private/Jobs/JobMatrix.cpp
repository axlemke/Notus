#include "Libraries/Systems/MultithreadingLibrary/Source/Public/Jobs/JobMatrix.h"

using namespace Multithreading;

JobMatrix::JobMatrix()
{
}

JobMatrix::~JobMatrix()
{
}

bool JobMatrix::HasPendingJobs()
{
	for (unsigned long i = 0; i < k_jobPriorityCount; ++i)
	{
		std::deque<Job>& pendingJobDeque = m_pendingJobs[i];

		if (pendingJobDeque.empty() == false)
		{
			return true;
		}
	}
	return false;
}

void JobMatrix::AddPendingJob(Job& job)
{
	JobPriority priority = job.GetPriority();

	std::deque<Job>& pendingJobDeque = GetPendingJobDeque(priority);

	pendingJobDeque.push_back(job);

}

Job JobMatrix::GetPendingJob()
{
	Job resultJob(0);

	for (unsigned long i = 0; i < k_jobPriorityCount; ++i)
	{
		std::deque<Job>& pendingJobDeque = m_pendingJobs[i];

		if (pendingJobDeque.empty() == false)
		{
			Job nextJob = pendingJobDeque.front();
			pendingJobDeque.pop_front();

			m_inprogressJobs.push_back(nextJob);
		}
	}
	return resultJob;
}

std::deque<Job>& JobMatrix::GetPendingJobDeque(JobPriority priority)
{
	unsigned long index = static_cast<unsigned long>(priority);
	return m_pendingJobs[index];
}

void JobMatrix::CheckInProgressJobs()
{
	for (Job& inProgressJob : m_inprogressJobs)
	{

	}
}

void JobMatrix::ClearPendingJobs()
{
	for (unsigned long i = 0; i < k_jobPriorityCount; ++i)
	{
		std::deque<Job>& pendingJobDeque = m_pendingJobs[i];

		if (pendingJobDeque.empty() == false)
		{
			pendingJobDeque.clear();
		}
	}
}
