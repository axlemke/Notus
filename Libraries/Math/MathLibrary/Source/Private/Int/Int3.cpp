#include "Int/Int3.h"

#include <Framework/LibraryShell/Source/Public/CustomAssert.h>

using namespace Math;

bool Int3::operator==(const Int3& rhs) const
{
	return ((x == rhs.x) && (y == rhs.y) && (z == rhs.z));
}

bool Int3::operator!=(const Int3& rhs) const
{
	return !(operator==(rhs));
}
