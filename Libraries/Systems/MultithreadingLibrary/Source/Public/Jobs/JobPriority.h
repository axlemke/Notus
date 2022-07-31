#pragma once

namespace Multithreading
{
	enum class JobPriority
	{
		Low,
		Normal,
		High,
		Urgent,
		Count
	};

	constexpr unsigned long k_jobPriorityCount = 4;
}

static_assert(Multithreading::k_jobPriorityCount == static_cast<unsigned long>(Multithreading::JobPriority::Count));
