#pragma once

#include "Graphics\APIs\DirectXGraphicsLibrary\Source\Public\DirectXGraphicsCommon.h"
#include "Graphics\APIs\GraphicsInterfaceLibrary\Source\Public\GraphicsAPI\GraphicsAPI.h"

namespace Graphics
{
	class DirectXAPI : public GraphicsAPI
	{
		DIRECTX_GRAPHICS_USAGE virtual void Initialize();
		DIRECTX_GRAPHICS_USAGE virtual void Deinitialize();
	};
}
