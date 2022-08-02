#pragma once

namespace Graphics
{
	class GraphicsAPI
	{
	public:
		virtual void Initialize() = 0;
		virtual void Deinitialize() = 0;

	protected:
		virtual void GatherAdaptors() = 0;

	};
}
