#pragma once

namespace Graphics
{
	class GraphicsInterface
	{
	public:
		virtual bool IsValid() const = 0;
		
		bool IsInvalid() const;
	};
}
