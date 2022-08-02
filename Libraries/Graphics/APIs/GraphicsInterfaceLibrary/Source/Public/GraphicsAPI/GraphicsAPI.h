#pragma once

#include "Graphics/APIs/GraphicsInterfaceLibrary/Source/Public/GraphicsInterfaceCommon.h"

namespace Graphics
{
	class GraphicsAPI
	{
	public:
		GRAPHICS_INTERFACE_USAGE GraphicsAPI();
		GRAPHICS_INTERFACE_USAGE virtual ~GraphicsAPI();

		virtual void Initialize() = 0;
		virtual void Deinitialize() = 0;

	protected:
		virtual void GatherAdaptors() = 0;

	};
}
