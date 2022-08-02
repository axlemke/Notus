#include "Graphics/APIs/VulkanGraphicsLibrary/Source/Public/VulkanAPI.h"

using namespace Graphics;

VulkanAPI::VulkanAPI()
{
}

VulkanAPI::~VulkanAPI()
{
}

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

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &applicationInfo;

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;

    //glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount = glfwExtensionCount;
    //createInfo.ppEnabledExtensionNames = glfwExtensions;
    createInfo.enabledLayerCount = 0;

    if (vkCreateInstance(&createInfo, nullptr, &m_instance) != VK_SUCCESS)
    {

    }
}
