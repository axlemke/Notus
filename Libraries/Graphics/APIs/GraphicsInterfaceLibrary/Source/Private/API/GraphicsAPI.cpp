#include "Graphics/APIs/GraphicsInterfaceLibrary/Source/Public/GraphicsAPI/GraphicsAPI.h"

#include "Graphics/APIs/GraphicsInterfaceLibrary/Source/Public/Adaptors/Adaptor.h"
#include "Memory/MemoryLibrary/Source/Public/Utils/CustomNewDeleteUtils.h"

using namespace Graphics;

GraphicsAPI::GraphicsAPI()
{
}

GraphicsAPI::~GraphicsAPI()
{
}

void GraphicsAPI::Initialize()
{
	CreateFactoryOrInstance();

	GatherAdaptors();
}

void GraphicsAPI::ClearAdaptors()
{
	for (Adaptor* adaptor : m_adaptors)
	{
		HaveBlueDelete(adaptor);
	}
	m_adaptors.clear();
}
