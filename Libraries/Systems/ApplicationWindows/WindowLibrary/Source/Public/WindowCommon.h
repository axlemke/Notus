#pragma once

#include <Framework/LibraryShell/Source/Public/DLLCommon.h>

#if defined(FINAL) // Don't use dlls in final builds
#define WINDOWs_APPLICATION_WINDOW_USAGE
#elif defined(WINDOWs_APPLICATION_WINDOW_EXPORT) // export
#define WINDOWs_APPLICATION_WINDOW_USAGE LIBRARY_EXPORT
#else // import
#define WINDOWs_APPLICATION_WINDOW_USAGE LIBRARY_IMPORT
#endif

