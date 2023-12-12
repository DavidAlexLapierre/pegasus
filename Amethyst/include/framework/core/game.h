#pragma once

#include "framework/interfaces/IDisposable.h"
#include "framework/core/sceneManager.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>

namespace Amethyst::Core {
	class Game : IDisposable {
	public:
		Game(const char* title);
		~Game();
		/// <summary>
		/// Runs the game loop
		/// </summary>
		/// <returns>Returns the exit status of the loop. 0 means it exited correctly
		/// and any other code means an error.</returns>
		int run();
		void dispose() override;

		/// <summary>
		/// Reference to the scene manager used for the Game
		/// </summary>
		static std::shared_ptr<SceneManager> sceneManager;

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
