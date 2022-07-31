#include "GraphicsInterface.h"

using namespace Graphics;

bool GraphicsInterface::IsInvalid() const
{
	return !IsValid();
}
