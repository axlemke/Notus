#pragma once

#include "Systems/ApplicationWindows/WindowsApplicationWindowLibrary/Source/Public/WindowsApplicationWindowCommon.h"
#include <Systems/ApplicationWindows/ApplicationWindowInterfaceLibrary/Source/Public/ApplicationWindow.h>
#include <Windows.h>

namespace Systems
{
	class WindowsApplicationWindow : public ApplicationWindow
	{
	public:
		WINDOWS_APPLICATION_WINDOW_USAGE WindowsApplicationWindow(const char* name);
		WINDOWS_APPLICATION_WINDOW_USAGE WindowsApplicationWindow();
		WINDOWS_APPLICATION_WINDOW_USAGE virtual ~WindowsApplicationWindow();

		WINDOWS_APPLICATION_WINDOW_USAGE HWND GetWindowHandle() const;

	protected:
		HINSTANCE		m_hInstance;
		WNDCLASSEX		m_windowClassEx;
		HWND			m_windowHandle;

	};
}
