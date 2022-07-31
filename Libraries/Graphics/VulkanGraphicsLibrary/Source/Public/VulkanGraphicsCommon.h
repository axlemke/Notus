#pragma once

#include "Framework/LibraryShell/Source/Public/DLLCommon.h"

#if defined(FINAL) // Don't use dlls in final builds
#define VULKAN_GRAPHICS_USAGE
#elif defined(VULKANGRAPHICSLIBRARY_EXPORTS) // export
#define VULKAN_GRAPHICS_USAGE LIBRARY_EXPORT
#else // import
#define VULKAN_GRAPHICS_USAGE LIBRARY_IMPORT
#endif
