#include "Graphics/APIs/GraphicsInterfaceLibrary/Source/Public/Adaptors/Adaptor.h"

using namespace Graphics;

Adaptor::Adaptor()
{
}

Adaptor::Adaptor(const char* name)
	: m_name(name)
{
}

Adaptor::~Adaptor()
{
}

const std::string& Adaptor::GetName() const
{
	return m_name;
}
