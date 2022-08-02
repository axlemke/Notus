#pragma once

#include "Graphics/APIs/VulkanGraphicsLibrary/Source/Public/VulkanGraphicsCommon.h"
#include "Graphics/APIs/GraphicsInterfaceLibrary/Source/Public/GraphicsAPI/GraphicsAPI.h"

namespace Graphics
{
	class VulkanAPI : public GraphicsAPI
	{
	public:
		VULKAN_GRAPHICS_USAGE VulkanAPI();
		VULKAN_GRAPHICS_USAGE virtual ~VulkanAPI();
		
		VULKAN_GRAPHICS_USAGE virtual void Deinitialize();

	protected:
		virtual void CreateFactoryOrInstance() override;
		virtual void GatherAdaptors() override;

	protected:
		void CreateInstance();

		VkInstance m_instance;
	};
}
