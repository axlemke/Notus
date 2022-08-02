#include "Systems/HashingLibrary/Source/Public/Hashing.h"

using namespace Hashing;

unsigned long Hashing::Morton3(unsigned long x, unsigned long y, unsigned long z)
{
	// z--z--z--z--z--z--z--z--z--z-- : Part1By2(z) << 2  
	// -y--y--y--y--y--y--y--y--y--y- : Part1By2(y) << 1  
	// --x--x--x--x--x--x--x--x--x--x : Part1By2(x)  
	// zyxzyxzyxzyxzyxzyxzyxzyxzyxzyx : Final result  
	
	return (Part1By2(z) << 2) + (Part1By2(y) << 1) + Part1By2(x);
}

unsigned long Hashing::Part1By2(unsigned long x)
{
	// x = ----------------------9876543210 : Bits initially  
	// x = ------98----------------76543210 : After (1)  
	// x = ------98--------7654--------3210 : After (2)
	// x = ------98----76----54----32----10 : After (3)  
	// x = ----9--8--7--6--5--4--3--2--1--0 : After (4)  
	
	x = (x ^ (x << 16)) & 0xFF0000FF; // (1)  
	x = (x ^ (x << 8)) & 0x0300f00F; // (2)  
	x = (x ^ (x << 4)) & 0x030C30C3; // (3)  
	x = (x ^ (x << 2)) & 0x09249249; // (4)  
	
	return x; 
}
