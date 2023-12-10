#include "framework/core/game.h"

namespace Amethyst::Core {
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
		while (!glfwWindowShouldClose(window)) {
			glClear(GL_COLOR_BUFFER_BIT);

			/*
			* Update & Draw code
			*/

			glfwSwapBuffers(window);
			glfwPollEvents();
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