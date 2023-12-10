#pragma once

#include "engine/interfaces/IDisposable.h";

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Amethyst {
	class Game : IDisposable {
	public:
		Game();
		~Game();
		void run();
		void dispose() override;

	private:
		GLFWwindow* window{};
		void terminateGLFW();
	};
}
