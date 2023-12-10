#pragma once

#include "framework/core/game.h"

namespace Game {
	class App : public Amethyst::Core::Game {	
	public:
		App(const char* title) : Amethyst::Core::Game(title) {}
	};
}
