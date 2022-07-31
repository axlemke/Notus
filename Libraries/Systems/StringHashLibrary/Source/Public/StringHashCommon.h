#pragma once

#include "Libraries/Framework/LibraryShell/Source/Public/LibraryShell.h"

#if defined(FINAL) // Don't use dlls in final builds
#define STRING_HASH_USAGE
#elif defined(STRING_HASH_EXPORT) // export
#define STRING_HASH_USAGE LIBRARY_EXPORT
#else // import
#define STRING_HASH_USAGE LIBRARY_IMPORT
#endif
