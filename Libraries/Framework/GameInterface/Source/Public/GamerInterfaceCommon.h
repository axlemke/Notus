#pragma once

#include <Framework/LibraryShell/Source/Public/DLLCommon.h>

#if defined(FINAL) // Don't use dlls in final builds
#define GAME_INTERFACE_USAGE
#elif defined(GAME_INTERFACE_EXPORT) // export
#define GAME_INTERFACE_USAGE LIBRARY_EXPORT
#else // import
#define GAME_INTERFACE_USAGE LIBRARY_IMPORT
#endif
