#pragma once

#include "engine/interfaces/IDisposable.h";

namespace Amethyst::Core {
	class SceneManager : IDisposable {
	public:
		void init();
		void dispose() override;
	};
}