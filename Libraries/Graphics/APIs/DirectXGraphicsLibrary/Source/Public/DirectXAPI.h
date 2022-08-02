#pragma once

#include "Graphics/APIs/DirectXGraphicsLibrary/Source/Public/DirectXGraphicsCommon.h"
#include "Graphics/APIs/GraphicsInterfaceLibrary/Source/Public/GraphicsAPI/GraphicsAPI.h"
#include <Memory/MemoryLibrary/Source/Public/Pointers/ComPointer.h>

namespace Graphics
{
	class DirectXAPI : public GraphicsAPI
	{
	public:
		DIRECTX_GRAPHICS_USAGE DirectXAPI();
		DIRECTX_GRAPHICS_USAGE virtual ~DirectXAPI();

		DIRECTX_GRAPHICS_USAGE virtual void Deinitialize();

	protected:
		virtual void CreateFactoryOrInstance() override;
		virtual void GatherAdaptors() override;

	protected:
		void CreateFactory();

		Memory::ComPtr<ID3D12Debug> m_debugInterface;
		Memory::ComPtr<IDXGIFactory4> m_factory;

	};
}
