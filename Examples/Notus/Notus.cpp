// Notus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Libraries/Graphics/APIs/DirectXGraphicsLibrary/Source/Public/DirectXAPI.h"
#include "Libraries/Graphics/APIs/VulkanGraphicsLibrary/Source/Public/VulkanAPI.h"
#include "Libraries/Systems/ApplicationWindows/WindowsApplicationWindowLibrary/Source/Public/WindowsApplicationWindow.h"
#include "Libraries/Systems/BitManipulationLibrary/Source/Public/BitFlags.h"

int main()
{
    Systems::WindowsApplicationWindow* newWindow = new Systems::WindowsApplicationWindow();
    newWindow->Initialize();
    newWindow->DisplayWindow(true);

    Graphics::DirectXAPI directXAPI;
    Graphics::VulkanAPI vulkanAPI;

    directXAPI.Initialize();
    vulkanAPI.Initialize();

    std::cout << "Hello World!\n";

    enum TestTime
    {
        Test,
    };

    BitManipulation::BitFlags<TestTime, int> test;

}
