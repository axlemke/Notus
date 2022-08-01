// Notus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Libraries/Systems/ApplicationWindows/WindowsApplicationWindowLibrary/Source/Public/WindowsApplicationWindow.h"

int main()
{
    Systems::WindowsApplicationWindow* newWindow = new Systems::WindowsApplicationWindow();
    newWindow->Initialize();
    newWindow->DisplayWindow(true);

    std::cout << "Hello World!\n";
}
