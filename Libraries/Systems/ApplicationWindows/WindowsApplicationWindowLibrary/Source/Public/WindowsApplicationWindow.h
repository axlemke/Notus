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

		WINDOWS_APPLICATION_WINDOW_USAGE void Initialize();
		WINDOWS_APPLICATION_WINDOW_USAGE void Deinitialize();

		WINDOWS_APPLICATION_WINDOW_USAGE virtual void DisplayWindow(bool showWindow);

		WINDOWS_APPLICATION_WINDOW_USAGE HWND GetWindowHandle() const;

	protected:
		static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
		
		HINSTANCE		m_hInstance;
		WNDCLASSEX		m_windowClassEx;
		HWND			m_windowHandle;

	};
}
