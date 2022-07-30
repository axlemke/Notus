#pragma once

#include <string>
#include <stddef.h>

#include "Libraries/Framework/LibraryShell/Source/Public/DLLCommon.h"

#if defined(FINAL) // Don't use dlls in final builds
#define LIBRARYSHELL_USAGE
#elif defined(LIBRARYSHELL_EXPORT) // export
#define LIBRARYSHELL_USAGE LIBRARY_EXPORT
#else // import
#define LIBRARYSHELL_USAGE LIBRARY_IMPORT
#endif

namespace HaveBlue
{
	class LibraryShell
	{
	public:
		LIBRARYSHELL_USAGE const char* GetName() const;

	private:
		std::string m_name;
	};
};

#define COMMA_DEFINE ,
