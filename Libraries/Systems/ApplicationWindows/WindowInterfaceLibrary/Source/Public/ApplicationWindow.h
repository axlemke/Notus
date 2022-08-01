#pragma once

#include "Systems/ApplicationWindows/WindowInterfaceLibrary/Source/Public/WindowInterfaceCommon.h"

namespace Systems
{
	class ApplicationWindow
	{
	public:
		WINDOW_INTERFACE_USAGE ApplicationWindow();
		WINDOW_INTERFACE_USAGE virtual ~ApplicationWindow();

	protected:
		unsigned short		m_width;
		unsigned short		m_height;
		unsigned short		m_clientWidth;
		unsigned short		m_clientHeight;
	};
}