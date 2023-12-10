#pragma once

#include "framework/interfaces/IDisposable.h"

namespace Amethyst::Core {
	class Scene : IDisposable {
	public:
		void init();
		void dispose() override;
		void reset();
	};
}