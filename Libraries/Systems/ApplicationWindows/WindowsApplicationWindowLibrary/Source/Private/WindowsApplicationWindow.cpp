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

void WindowsApplicationWindow::Initialize()
{
	const char* windowName = m_name.c_str();

	m_hInstance = GetModuleHandle(nullptr);

	ZeroMemory(&m_windowClassEx, sizeof(WNDCLASSEX));
	m_windowClassEx.cbSize = sizeof(WNDCLASSEX);
	m_windowClassEx.style = CS_HREDRAW | CS_VREDRAW;
	m_windowClassEx.lpfnWndProc = WindowProc;
	m_windowClassEx.hCursor = LoadCursor(NULL, IDC_ARROW);
	m_windowClassEx.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW);
	m_windowClassEx.lpszClassName = windowName;
	m_windowClassEx.hInstance = m_hInstance;

	m_windowClassEx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	m_windowClassEx.hCursor = LoadCursor(NULL, IDC_ARROW);

	RegisterClassEx(&m_windowClassEx);

	constexpr long k_startingPositionX = 300;
	constexpr long k_startingPositionY = 300;

	m_windowHandle = CreateWindowEx(NULL, windowName, windowName, WS_OVERLAPPEDWINDOW, k_startingPositionX, k_startingPositionY, m_width, m_height, NULL, NULL, m_hInstance, NULL);

	RECT windowClientRect;
	GetClientRect(m_windowHandle, &windowClientRect);
	m_clientWidth = static_cast<unsigned int>(windowClientRect.right - windowClientRect.left);
	m_clientHeight = static_cast<unsigned int>(windowClientRect.bottom - windowClientRect.top);
}

void WindowsApplicationWindow::Deinitialize()
{
}

void WindowsApplicationWindow::DisplayWindow(bool showWindow)
{
	ShowWindow(m_windowHandle, showWindow);
}

HWND WindowsApplicationWindow::GetWindowHandle() const
{
	return m_windowHandle;
}

LRESULT CALLBACK WindowsApplicationWindow::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
	case WM_CLOSE:
	case WM_QUIT:
		PostQuitMessage(0);
		break;
	case WM_MOVE:
		break;
	case WM_SIZE:
		//ResizeWindow(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case WM_PAINT:
		break;
	}
	//ImGuiHelper::ImGuiWndProcHandler(hWnd, message, wParam, lParam);

	return DefWindowProc(hWnd, message, wParam, lParam);
}
