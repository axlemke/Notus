#include "Libraries/Framework/LibraryShell/Source/Public/LibraryShell.h"

using namespace HaveBlue;

const char* LibraryShell::GetName() const
{
	return m_name.c_str();
}