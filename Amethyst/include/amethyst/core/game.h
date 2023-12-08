#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Amethyst {
	class Game {
	public:
		Game();
		~Game();
		void run();

	private:
		GLFWwindow* window{};
		void terminate();
	};
}
