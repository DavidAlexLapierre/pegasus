#pragma once

#include "framework/interfaces/IDisposable.h"

namespace Amethyst::Core {
	class Scene : IDisposable {
	public:
		void dispose() override;
	};
}