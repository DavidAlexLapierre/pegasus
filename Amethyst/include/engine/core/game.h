#pragma once

#include "engine/interfaces/IDisposable.h";

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Amethyst {
	class Game : IDisposable {
	public:
		Game();
		~Game();
		/// <summary>
		/// Runs the game loop
		/// </summary>
		/// <returns>Returns the exit status of the loop. 0 means it exited correctly
		/// and any other code means an error.</returns>
		int run();
		void dispose() override;

	private:
		/// <summary>
		/// Reference to the GLFW context windwo
		/// </summary>
		GLFWwindow* window{};
		/// <summary>
		/// Dispose GLFW classes and terminate the context
		/// </summary>
		void terminateGLFW();
	};
}
