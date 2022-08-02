#pragma once

#include "Graphics/APIs/GraphicsInterfaceLibrary/Source/Public/GraphicsInterfaceCommon.h"
#include <vector>

namespace Graphics
{
	class Adaptor;

	class GraphicsAPI
	{
	public:
		GRAPHICS_INTERFACE_USAGE GraphicsAPI();
		GRAPHICS_INTERFACE_USAGE virtual ~GraphicsAPI();

		GRAPHICS_INTERFACE_USAGE void Initialize();

		virtual void Deinitialize() = 0;

	protected:
		virtual void CreateFactoryOrInstance() = 0;
		virtual void GatherAdaptors() = 0;

		void ClearAdaptors();


		std::vector<Adaptor*> m_adaptors;

	};
}
