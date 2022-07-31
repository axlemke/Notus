#include "Libraries/Systems/MultithreadingLibrary/Source/Public/Jobs/JobThread.h"

#include "Libraries/Framework/LibraryShell/Source/Public/CustomAssert.h"
#include "Libraries/Systems/MultithreadingLibrary/Source/Public/Jobs/JobManager.h"
#include "Libraries/Systems/MultithreadingLibrary/Source/Public/Jobs/Job.h"

using namespace Multithreading;

JobThread::JobThread(JobManager* jobManager)
	: JobThread(jobManager, "JobThead")
{
}

JobThread::JobThread(JobManager* jobManager, const std::string& name)
	: m_jobManager(jobManager)
	, m_enabled(true)
	, m_executedJobs(0)
	, m_iterations(0)
	, m_name(name)
{
}

JobThread::JobThread(JobThread&& other)
	: m_jobManager(other.m_jobManager)
	, m_enabled(other.m_enabled)
	, m_executedJobs(other.m_executedJobs)
	, m_iterations(other.m_iterations)
	, m_name(other.m_name)
{
}

JobThread::JobThread(const JobThread& other)
	: m_jobManager(other.m_jobManager)
	, m_enabled(other.m_enabled)
	, m_executedJobs(other.m_executedJobs)
	, m_iterations(other.m_iterations)
	, m_name(other.m_name)
{
}

JobThread& JobThread::operator=(JobThread&& other)
{
	m_jobManager = std::move(other.m_jobManager);
	m_enabled = std::move(other.m_enabled);
	m_executedJobs = std::move(other.m_executedJobs);
	m_iterations = std::move(other.m_iterations);
	m_name = std::move(other.m_name);

	return (*this);
}

JobThread& JobThread::operator=(const JobThread& other)
{
	m_jobManager = other.m_jobManager;
	m_enabled = other.m_enabled;
	m_executedJobs = other.m_executedJobs;
	m_iterations = other.m_iterations;
	m_name = other.m_name;

	return (*this);
}

JobThread::~JobThread()
{
}

bool JobThread::IsBusy() const
{
	return false;
}

bool JobThread::IsIdle() const
{
	return !IsBusy();
}

bool JobThread::IsEnabled()
{
	std::lock_guard<std::mutex> guard(m_jobThreadMutex);
	return m_enabled;
}

void JobThread::SetEnabled(bool enabled)
{
	std::lock_guard<std::mutex> guard(m_jobThreadMutex);
	m_enabled = enabled;
}

void JobThread::operator()()
{
	HB_ASSERT(m_jobManager != nullptr);

	while (IsEnabled())
	{
		if (m_jobManager->HasPendingJobs())
		{
			Job job = m_jobManager->GetPendingJob();

			m_executedJobs++;
		}

		m_iterations++;
	}
}
