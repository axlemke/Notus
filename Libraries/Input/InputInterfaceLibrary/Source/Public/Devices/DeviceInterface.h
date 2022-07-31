#pragma once

#include "Input/InputInterfaceLibrary/Source/Public/InputInterfaceCommon.h"

namespace Input
{
	class DeviceInterface
	{
	public:
		INPUT_INTERFACE_USAGE DeviceInterface();
		INPUT_INTERFACE_USAGE virtual ~DeviceInterface();

		virtual bool IsValid() const = 0;
		INPUT_INTERFACE_USAGE bool IsInvalid() const;

	};
}
