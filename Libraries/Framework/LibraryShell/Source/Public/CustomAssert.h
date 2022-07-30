#pragma once

#if defined(_DEBUG)

#include <assert.h>
#define HB_ASSERT(x) assert(x)
#define HB_WITHIN_RANGE_ASSERT(x, minValue, maxValue) HB_ASSERT((x >= minValue) && (x <= maxValue))

#else

#define HB_ASSERT(x)
#define HB_WITHIN_RANGE_ASSERT(x, minValue, maxValue)

#endif
