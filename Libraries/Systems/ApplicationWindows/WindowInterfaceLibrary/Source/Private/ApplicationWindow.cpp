#include "Systems/ApplicationWindows/WindowInterfaceLibrary/Source/Public/ApplicationWindow.h"

#include <Framework/LibraryShell/Source/Public/CustomAssert.h>

using namespace Systems;

constexpr unsigned short k_defaultWindowWidth = 1000;
constexpr unsigned short k_defaultWindowHeight = 1000;

ApplicationWindow::ApplicationWindow(const char* name)
	: m_name(name)
	, m_width(k_defaultWindowWidth)
	, m_height(k_defaultWindowHeight)
	, m_clientWidth(k_defaultWindowWidth)
	, m_clientHeight(k_defaultWindowHeight)
{
}

ApplicationWindow::ApplicationWindow()
	: ApplicationWindow("TestWindow")
{
}

ApplicationWindow::~ApplicationWindow()
{
}

unsigned short ApplicationWindow::GetWidth() const
{
	return m_width;
}

unsigned short ApplicationWindow::GetHeight() const
{
	return m_height;
}

float ApplicationWindow::GetAspectRatio() const
{
	HB_ASSERT(m_height != 0);
	return static_cast<float>(m_width) / static_cast<float>(m_height);
}

unsigned short ApplicationWindow::GetClientWidth() const
{
	return m_clientWidth;
}

unsigned short ApplicationWindow::GetClientHeight() const
{
	return m_clientHeight;
}
float ApplicationWindow::GetClientAspectRatio() const
{
	HB_ASSERT(m_clientHeight != 0);
	return static_cast<float>(m_clientWidth) / static_cast<float>(m_clientHeight);
}
