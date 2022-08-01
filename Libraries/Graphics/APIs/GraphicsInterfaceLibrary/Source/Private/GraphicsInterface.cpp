#include "Graphics\APIs\GraphicsInterfaceLibrary\Source\Public\GraphicsInterface.h"

using namespace Graphics;

bool GraphicsInterface::IsInvalid() const
{
	return !IsValid();
}
