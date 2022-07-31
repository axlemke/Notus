#include "Operations/Floating.h"

#include "MathConstants.h"
#include <bit>

using namespace Math;

int Math::GetSign(float value)
{
	unsigned int* bits = reinterpret_cast<unsigned int*>(&value);
	
	// Just shift the first bit all the way over to get the sign
	return *bits >> 31;
}

int Math::GetExponent(float value)
{
	unsigned int* bits = reinterpret_cast<unsigned int*>(&value);

	// Get the upper bits for the exponent
	int exponent = *bits & k_floatExponentMask;

	// Now shift them over
	return exponent >> 23;
}

int Math::GetMantissa(float value)
{
	unsigned int* bits = reinterpret_cast<unsigned int*>(&value);

	// Just mask out the bits for the mantissa
	return *bits & k_floatMantissaMask;
}

float Math::FastInverseSqureRoot(float value)
{
	static_assert(std::numeric_limits<float>::is_iec559); // (enable only on IEEE 754)

	constexpr float k_threeHalfs = 1.5f;
	constexpr uint32_t k_magic = 0x5f3759df;

	//float const y = std::bit_cast<float>(0x5f3759df - (std::bit_cast<std::uint32_t>(value) >> 1));
	float y = std::bit_cast<float>(k_magic - (std::bit_cast<std::uint32_t>(value) >> 1));
	return y * (k_threeHalfs - (value * 0.5f * y * y));

	//float x2 = value * 0.5f;
	//float y = value;

	//long i = *(long*)&y;
	//i = 0x5F3759F - (i >> 1);
	//y = *(float*)&i;

	//y = y * (k_threeHalfs - (x2 * y * y));

	//return y;
}
