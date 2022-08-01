#pragma once

#include "Graphics/APIs/GraphicsInterfaceLibrary/Source/Public/GraphicsInterfaceCommon.h"
#include <basetsd.h>
#include <string>

namespace Graphics
{
	class Adaptor
	{
	public:
		GRAPHICS_INTERFACE_USAGE Adaptor();
		GRAPHICS_INTERFACE_USAGE Adaptor(const char* name);
		GRAPHICS_INTERFACE_USAGE virtual ~Adaptor();

		GRAPHICS_INTERFACE_USAGE const std::string& GetName() const;

		virtual UINT64 GetDedicatedVideoMemory() const = 0;
		virtual UINT64 GetDedicatedSystemMemory() const = 0;
		virtual UINT64 GetSharedSystemMemory() const = 0;

		virtual bool IsSoftwareAdapter() const = 0;
		virtual bool IsHardwareAdapter() const = 0;

		virtual bool DoesSupportHDR() const = 0;

	private:
		std::string m_name;

	};
}
