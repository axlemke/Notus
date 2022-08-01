#include "Systems/ApplicationWindows/WindowsApplicationWindowLibrary/Source/Public/WindowsApplicationWindow.h"

using namespace Systems;

WindowsApplicationWindow::WindowsApplicationWindow(const char* name)
	: ApplicationWindow(name)
	, m_hInstance()
	, m_windowClassEx()
	, m_windowHandle()
{
}

WindowsApplicationWindow::WindowsApplicationWindow()
	: ApplicationWindow()
	, m_hInstance()
	, m_windowClassEx()
	, m_windowHandle()
{
}

WindowsApplicationWindow::~WindowsApplicationWindow()
{
}

HWND WindowsApplicationWindow::GetWindowHandle() const
{
	return m_windowHandle;
}
