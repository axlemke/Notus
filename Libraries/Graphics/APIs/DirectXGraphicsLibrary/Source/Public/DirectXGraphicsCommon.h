#pragma once

#include <Framework/LibraryShell/Source/Public/DLLCommon.h>

#if defined(FINAL) // Don't use dlls in final builds
#define DIRECTX_GRAPHICS_USAGE
#elif defined(DIRECTXGRAPHICSLIBRARY_EXPORTS) // export
#define DIRECTX_GRAPHICS_USAGE LIBRARY_EXPORT
#else // import
#define DIRECTX_GRAPHICS_USAGE LIBRARY_IMPORT
#endif
