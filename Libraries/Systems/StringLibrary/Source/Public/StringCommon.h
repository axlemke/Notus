#pragma once

#include "Libraries/Framework/LibraryShell/Source/Public/DLLCommon.h"

#if defined(FINAL) // Don't use dlls in final builds
#define STRING_USAGE
#elif defined(STRING_EXPORT) // export
#define STRING_USAGE LIBRARY_EXPORT
#else // import
#define STRING_USAGE LIBRARY_IMPORT
#endif