#include "Systems/ApplicationWindows/WindowInterfaceLibrary/Source/Public/ApplicationWindow.h"

using namespace Systems;

constexpr unsigned short k_defaultWindowWidth = 1000;
constexpr unsigned short k_defaultWindowHeight = 1000;

ApplicationWindow::ApplicationWindow()
	: m_width(k_defaultWindowWidth)
	, m_height(k_defaultWindowHeight)
	, m_clientWidth(k_defaultWindowWidth)
	, m_clientHeight(k_defaultWindowHeight)
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

unsigned short ApplicationWindow::GetClientWidth() const
{
	return m_clientWidth;
}

unsigned short ApplicationWindow::GetClientHeight() const
{
	return m_clientHeight;
}
