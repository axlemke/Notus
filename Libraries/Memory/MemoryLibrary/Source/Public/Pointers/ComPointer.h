#pragma once

#include <wrl/client.h>

namespace MemorySystem
{
	template<typename TemplatedClass>
	using ComPtr = Microsoft::WRL::ComPtr<TemplatedClass>;
};
