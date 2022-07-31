#include "Libraries/Systems/RTTISystem/Source/Public/RTTI.h"

using namespace HaveBlue;

const RTTI* RTTI::QueryInterface(UINT64 id) const
{
	return nullptr;
}

bool RTTI::Is(UINT64 id) const
{
	return false;
}

bool RTTI::Is(const std::string& name) const
{
	return false;
}

std::string RTTI::GetTypeName() const
{
	return "RTTI";
}
