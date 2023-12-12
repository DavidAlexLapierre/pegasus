#include "framework/core/game.h"

namespace Amethyst::Core {

	std::shared_ptr<SceneManager> Game::sceneManager = std::make_shared<SceneManager>();

	Game::Game(const char* title) {
		if (glfwInit()) {
			window = glfwCreateWindow(640, 480, title, NULL, NULL);
			if (!window) {
				terminateGLFW();
			}
			else {
				glfwMakeContextCurrent(window);
				gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
			}
		}
	}

	Game::~Game() {

	}

	int Game::run() {
		auto previousTime = glfwGetTime();
		while (!glfwWindowShouldClose(window)) {
			glClear(GL_COLOR_BUFFER_BIT);

			auto currentTime = glfwGetTime();
			Game::sceneManager->update(currentTime - previousTime);

			glfwSwapBuffers(window);
			glfwPollEvents();
			previousTime = currentTime;
		}

		return 0;
	}

	void Game::terminateGLFW() {
		if (window) {
			glfwDestroyWindow(window);
		}
		glfwTerminate();
	}

	void Game::dispose() {
		// Implement dispose logic
		terminateGLFW();
	}
}