#pragma once

#include "Systems/ApplicationWindows/WindowInterfaceLibrary/Source/Public/WindowInterfaceCommon.h"
#include <string>

namespace Systems
{
	class ApplicationWindow
	{
	public:
		WINDOW_INTERFACE_USAGE ApplicationWindow(const char* name);
		WINDOW_INTERFACE_USAGE ApplicationWindow();
		WINDOW_INTERFACE_USAGE virtual ~ApplicationWindow();

		WINDOW_INTERFACE_USAGE unsigned short GetWidth() const;
		WINDOW_INTERFACE_USAGE unsigned short GetHeight() const;
		WINDOW_INTERFACE_USAGE float GetAspectRatio() const;
		WINDOW_INTERFACE_USAGE unsigned short GetClientWidth() const;
		WINDOW_INTERFACE_USAGE unsigned short GetClientHeight() const;
		WINDOW_INTERFACE_USAGE float GetClientAspectRatio() const;

	protected:
		std::string			m_name;
		unsigned short		m_width;
		unsigned short		m_height;
		unsigned short		m_clientWidth;
		unsigned short		m_clientHeight;
	};
}