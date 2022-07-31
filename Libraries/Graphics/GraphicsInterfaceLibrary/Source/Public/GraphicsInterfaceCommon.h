#pragma once

#include "Framework/LibraryShell/Source/Public/DLLCommon.h"


#if defined(FINAL) // Don't use dlls in final builds
#define GRAPHICS_INTERFACE_USAGE
#elif defined(GRAPHICSINTERFACELIBRARY_EXPORTS) // export
#define GRAPHICS_INTERFACE_USAGE LIBRARY_EXPORT
#else // import
#define GRAPHICS_INTERFACE_USAGE LIBRARY_IMPORT
#endif
