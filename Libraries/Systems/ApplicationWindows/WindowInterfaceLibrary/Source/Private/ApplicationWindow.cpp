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
