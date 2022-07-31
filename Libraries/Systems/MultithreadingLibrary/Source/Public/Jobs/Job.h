#pragma once
	
#include "Libraries/Systems/MultithreadingLibrary/Source/Public/MultithreadingCommon.h"
#include "Libraries/Systems/MultithreadingLibrary/Source/Public/Jobs/JobPriority.h"

namespace Multithreading
{
	enum class JobState
	{
		Pending,
		Assigned,
		InProgress,
		Complete
	};

	using JobId = unsigned long;

	class Job
	{
	public:
		MULTITHREADING_USAGE Job(JobId jobId);
		MULTITHREADING_USAGE Job(JobId jobId, void (*jobFunctionPointer)(void*, int));
		MULTITHREADING_USAGE Job(JobId jobId, JobPriority priority, void (*jobFunctionPointer)(void*, int));
		MULTITHREADING_USAGE ~Job();

		MULTITHREADING_USAGE JobId GetJobId() const;
		MULTITHREADING_USAGE JobPriority GetPriority() const;
		MULTITHREADING_USAGE JobState GetState() const;

		MULTITHREADING_USAGE void Invoke(void* data, int count);

	private:
		JobId m_jobId;
		JobPriority m_priority;
		JobState m_jobState;

		void (*m_jobFunctionPointer)(void*, int);
	};
};
