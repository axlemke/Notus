#pragma once

#include <Framework/LibraryShell/Source/Public/DLLCommon.h>

#if defined(FINAL) // Don't use dlls in final builds
#define BIT_FLAGS_USAGE
#elif defined(BIT_MANIPULATION_EXPORT) // export
#define BIT_MANIPULATION_USAGE LIBRARY_EXPORT
#else // import
#define BIT_MANIPULATION_USAGE LIBRARY_IMPORT
#endif
