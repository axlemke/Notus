#pragma once

#include "Libraries/Framework/LibraryShell/Source/Public/DLLCommon.h"

#if defined(FINAL) // Don't use dlls in final builds
#define TIMER_USAGE
#elif defined(TIMER_EXPORT) // export
#define TIMER_USAGE LIBRARY_EXPORT
#else // import
#define TIMER_USAGE LIBRARY_IMPORT
#endif
