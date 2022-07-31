#include "Uint/Uint2.h"

#include <Framework/LibraryShell/Source/Public/CustomAssert.h>

using namespace Math;

bool Uint2::operator==(const Uint2& rhs) const
{
	return ((x == rhs.x) && (y == rhs.y));
}

bool Uint2::operator!=(const Uint2& rhs) const
{
	return !(operator==(rhs));
}
