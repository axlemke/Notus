#pragma once

#include "Graphics/APIs/GraphicsInterfaceLibrary/Source/Public/GraphicsInterfaceCommon.h"
#include <string>


namespace Graphics
{
	class AdaptorInterface
	{
	public:
		GRAPHICS_INTERFACE_USAGE AdaptorInterface();
		GRAPHICS_INTERFACE_USAGE virtual ~AdaptorInterface();

	private:
		std::string m_name;

	};
}
