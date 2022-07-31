#pragma once

#include "Libraries/Framework/LibraryShell/Source/Public/LibraryShell.h"

#if defined(FINAL) // Don't use dlls in final builds
#define MULTITHREADING_USAGE
#elif defined(MULTITHREADING_EXPORT) // export
#define MULTITHREADING_USAGE LIBRARY_EXPORT
#else // import
#define MULTITHREADING_USAGE LIBRARY_IMPORT
#endif
