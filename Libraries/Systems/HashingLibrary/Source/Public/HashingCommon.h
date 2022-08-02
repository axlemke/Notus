#pragma once

#include <Framework/LibraryShell/Source/Public/DLLCommon.h>

#if defined(FINAL) // Don't use dlls in final builds
#define HASHING_USAGE
#elif defined(HASHING_EXPORT) // export
#define HASHING_USAGE LIBRARY_EXPORT
#else // import
#define HASHING_USAGE LIBRARY_IMPORT
#endif
