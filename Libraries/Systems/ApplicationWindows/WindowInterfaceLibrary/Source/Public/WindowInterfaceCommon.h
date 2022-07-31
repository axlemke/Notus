#pragma once

#include <Framework/LibraryShell/Source/Public/DLLCommon.h>

#if defined(FINAL) // Don't use dlls in final builds
#define WINDOW_INTERFACE_USAGE
#elif defined(WINDOW_INTERFACE_EXPORT) // export
#define WINDOW_INTERFACE_USAGE LIBRARY_EXPORT
#else // import
#define WINDOW_INTERFACE_USAGE LIBRARY_IMPORT
#endif

