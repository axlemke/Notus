#include "Graphics/APIs/DirectXGraphicsLibrary/Source/Public/DirectXAPI.h"

#include "Memory/MemoryLibrary/Source/Public/Pointers/ComPointer.h"

using namespace Graphics;

DirectXAPI::DirectXAPI()
	: GraphicsAPI()
{
}

DirectXAPI::~DirectXAPI()
{
}

void DirectXAPI::Deinitialize()
{
}

void DirectXAPI::CreateFactory()
{
	DX::ThrowIfFailed(CreateDXGIFactory1(__uuidof(IDXGIFactory4), (void**)(&m_factory)));
}

void DirectXAPI::CreateFactoryOrInstance()
{
	CreateFactory();
}

void DirectXAPI::GatherAdaptors()
{
	Memory::ComPtr<IDXGIAdapter1> dxgiAdapter;

	for (UINT adapterIndex = 0; DXGI_ERROR_NOT_FOUND != m_factory->EnumAdapters1(adapterIndex, dxgiAdapter.GetAddressOf()); ++adapterIndex)
	{
		if (dxgiAdapter != nullptr)
		{
			//m_adaptors.push_back(Adaptor(dxgiAdapter));
		}
	}
}
