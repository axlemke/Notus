#pragma once

#include "Libraries/Framework/LibraryShell/Source/Public/DLLCommon.h"

#if defined(FINAL) // Don't use dlls in final builds
#define RTTI_USAGE
#elif defined(RTTI_EXPORT) // export
#define RTTI_USAGE LIBRARY_EXPORT
#else // import
#define RTTI_USAGE LIBRARY_IMPORT
#endif
