#pragma once

#include <wrl/client.h>

namespace Memory
{
	template<typename TemplatedClass>
	using ComPtr = Microsoft::WRL::ComPtr<TemplatedClass>;
}
