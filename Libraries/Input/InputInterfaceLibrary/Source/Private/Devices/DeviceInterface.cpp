#include "Input/InputInterfaceLibrary/Source/Public/Devices/DeviceInterface.h"

using namespace Input;

DeviceInterface::DeviceInterface()
{
}

DeviceInterface::~DeviceInterface()
{
}

bool DeviceInterface::IsInvalid() const
{
	return !IsValid();
}
