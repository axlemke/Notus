#pragma once

#include "Graphics/APIs/DirectXGraphicsLibrary/Source/Public/DirectXGraphicsCommon.h"
#include "Graphics/APIs/GraphicsInterfaceLibrary/Source/Public/Adaptors/Adaptor.h"
#include "Memory/MemoryLibrary/Source/Public/Pointers/ComPointer.h"

namespace Graphics
{
	class DirectXAdaptor : public Adaptor
	{
	public:


	protected:
		Memory::ComPtr<IDXGIAdapter1> m_dxgiAdapter;
		DXGI_ADAPTER_DESC1 m_dxgiAdaptorDesc;
		D3D_FEATURE_LEVEL m_maxSupportedFeatureLevel;
	};
}