#pragma once

#include "Libraries/Framework/LibraryShell/Source/Public/DLLCommon.h"

#if defined(FINAL) // Don't use dlls in final builds
#define FILE_LIBRARY_USAGE
#elif defined(FILE_LIBRARY_EXPORT) // export
#define FILE_LIBRARY_USAGE LIBRARY_EXPORT
#else // import
#define FILE_LIBRARY_USAGE LIBRARY_IMPORT
#endif
