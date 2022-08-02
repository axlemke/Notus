#pragma once

#include "Graphics/APIs/VulkanGraphicsLibrary/Source/Public/VulkanGraphicsCommon.h"
#include "Graphics/APIs/GraphicsInterfaceLibrary/Source/Public/Adaptors/Adaptor.h"
#include "Memory/MemoryLibrary/Source/Public/Pointers/ComPointer.h"

namespace Graphics
{
	class VulkanAdaptor : public Adaptor
	{
	public:


	protected:
		VkPhysicalDevice			m_physicalDevice;
		VkPhysicalDeviceProperties  m_physicalDeviceProperties;
	};
}