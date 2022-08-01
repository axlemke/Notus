#pragma once

#include "Graphics\APIs\GraphicsInterfaceLibrary\Source\Public\GraphicsInterfaceCommon.h"

namespace Graphics
{
	class GraphicsInterface
	{
	public:
		virtual bool IsValid() const = 0;
		
		GRAPHICS_INTERFACE_USAGE bool IsInvalid() const;
	};
}
