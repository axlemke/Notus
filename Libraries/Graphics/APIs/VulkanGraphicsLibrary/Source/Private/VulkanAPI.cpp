#include "Graphics/APIs/VulkanGraphicsLibrary/Source/Public/VulkanAPI.h"

using namespace Graphics;

void VulkanAPI::Initialize()
{
	CreateInstance();
}

void VulkanAPI::Deinitialize()
{
}

void VulkanAPI::GatherAdaptors()
{
}

void VulkanAPI::CreateInstance()
{
    VkApplicationInfo applicationInfo{};
    applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    applicationInfo.pApplicationName = "Hello Triangle";
    applicationInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    applicationInfo.pEngineName = "No Engine";
    applicationInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    applicationInfo.apiVersion = VK_API_VERSION_1_0;
}
