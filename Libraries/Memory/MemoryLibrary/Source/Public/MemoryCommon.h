#pragma once

#include <string>
#include "Libraries/Framework/LibraryShell/Source/Public/LibraryShell.h"

// NEED TO CLEAN THIS UP
#include <wrl/client.h>

#if defined(FINAL) // Don't use dlls in final builds
#define MEMORY_USAGE
#elif defined(MEMORY_EXPORT) // export
#define MEMORY_USAGE LIBRARY_EXPORT
#else // import
#define MEMORY_USAGE LIBRARY_IMPORT
#endif


#define MEMORY_CUSTOM_NEW 1
#define SUPPORTS_ALLOCATION_TYPENAME 1


#include "Utils/CustomNewDeleteUtils.h"
#include "Utils/MemcpyUtils.h"
