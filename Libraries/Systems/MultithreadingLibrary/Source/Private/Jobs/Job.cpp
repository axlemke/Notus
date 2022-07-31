#include "Libraries/Systems/MultithreadingLibrary/Source/Public/Jobs/Job.h"

using namespace Multithreading;

Job::Job(JobId jobId)
	: m_jobId(jobId)
	, m_priority(JobPriority::Normal)
	, m_jobState(JobState::Pending)
{
}

Job::Job(JobId jobId, void (*jobFunctionPointer)(void*, int))
	: Job(jobId, JobPriority::Normal, jobFunctionPointer)
{
}

Job::Job(JobId jobId, JobPriority priority, void (*jobFunctionPointer)(void*, int))
	: m_jobId(jobId)
	, m_priority(priority)
	, m_jobFunctionPointer(jobFunctionPointer)
	, m_jobState(JobState::Pending)
{
}

Job::~Job()
{
}

JobId Job::GetJobId() const
{
	return m_jobId;
}

JobPriority Job::GetPriority() const
{
	return m_priority;
}

JobState Job::GetState() const
{
	return m_jobState;
}

void Job::Invoke(void* data, int count)
{
	m_jobFunctionPointer(data, count);
}
