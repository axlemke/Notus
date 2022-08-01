#pragma once

#include "Systems/ApplicationWindows/WindowInterfaceLibrary/Source/Public/ApplicationWindowInterfaceCommon.h"
#include <string>

namespace Systems
{
	class ApplicationWindow
	{
	public:
		APPLICATION_WINDOW_INTERFACE_USAGE ApplicationWindow(const char* name);
		APPLICATION_WINDOW_INTERFACE_USAGE ApplicationWindow();
		APPLICATION_WINDOW_INTERFACE_USAGE virtual ~ApplicationWindow();

		APPLICATION_WINDOW_INTERFACE_USAGE const char* GetName() const;

		APPLICATION_WINDOW_INTERFACE_USAGE unsigned short GetWidth() const;
		APPLICATION_WINDOW_INTERFACE_USAGE unsigned short GetHeight() const;
		APPLICATION_WINDOW_INTERFACE_USAGE float GetAspectRatio() const;
		APPLICATION_WINDOW_INTERFACE_USAGE unsigned short GetClientWidth() const;
		APPLICATION_WINDOW_INTERFACE_USAGE unsigned short GetClientHeight() const;
		APPLICATION_WINDOW_INTERFACE_USAGE float GetClientAspectRatio() const;
		APPLICATION_WINDOW_INTERFACE_USAGE bool IsActive() const;

		virtual void DisplayWindow(bool showWindow) = 0;
		virtual void ResizeWindow(unsigned short width, unsigned short height) = 0;

	protected:
		std::string			m_name;
		unsigned short		m_width;
		unsigned short		m_height;
		unsigned short		m_clientWidth;
		unsigned short		m_clientHeight;
		bool				m_isActive;
	};
}