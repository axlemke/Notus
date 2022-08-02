#include "Graphics/APIs/DirectXGraphicsLibrary/Source/Public/DirectXAPI.h"

using namespace Graphics;

DirectXAPI::DirectXAPI()
{
}

DirectXAPI::~DirectXAPI()
{
}

void DirectXAPI::Initialize()
{
	CreateFactory();
}

void DirectXAPI::Deinitialize()
{
}

void DirectXAPI::CreateFactory()
{
	DX::ThrowIfFailed(CreateDXGIFactory1(__uuidof(IDXGIFactory4), (void**)(&m_factory)));
}

void DirectXAPI::GatherAdaptors()
{
}
