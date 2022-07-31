#pragma once

#include <Framework/LibraryShell/Source/Public/DLLCommon.h>

#if defined(FINAL) // Don't use dlls in final builds
#define INPUT_INTERFACE_USAGE
#elif defined(INPUT_INTERFACE_EXPORT) // export
#define INPUT_INTERFACE_USAGE LIBRARY_EXPORT
#else // import
#define INPUT_INTERFACE_USAGE LIBRARY_IMPORT
#endif

