#include "amethyst/core/game.h"

namespace Amethyst {
	Game::Game() {
		if (glfwInit()) {
			window = glfwCreateWindow(640, 480, "Amethyst", NULL, NULL);
			if (!window) {
				terminate();
			}
			else {
				glfwMakeContextCurrent(window);
				gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
			}
		}
	}

	Game::~Game() {

	}

	void Game::run() {
		while (!glfwWindowShouldClose(window)) {
			glClear(GL_COLOR_BUFFER_BIT);

			/*
			* Update & Draw code
			*/

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		terminate();
	}

	void Game::terminate() {
		if (window) {
			glfwDestroyWindow(window);
		}
		glfwTerminate();
	}
}