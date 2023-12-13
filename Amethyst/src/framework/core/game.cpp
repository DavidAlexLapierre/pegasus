#include "framework/core/game.h"

#include <exception>
#include <iostream>

namespace Amethyst::Core {

	std::shared_ptr<SceneManager> Game::sceneManager = std::make_shared<SceneManager>();

	Game::Game(const char* title) {
		if (glfwInit()) {
			window = glfwCreateWindow(WINDOW_BASE_W, WINDOW_BASE_H, title, NULL, NULL);
			if (!window) {
				terminateGLFW();
			} else {
				// Get the primary monitor
				GLFWmonitor* monitor = glfwGetPrimaryMonitor();
				if (!monitor) {
					terminateGLFW();
				}
				else {
					// Get the monitor's video mode
					const GLFWvidmode* mode = glfwGetVideoMode(monitor);
					if (!mode) {
						terminateGLFW();
					}
					else {
						// Calculate the position to center the window
						int xPos = (mode->width - WINDOW_BASE_W) / 2;
						int yPos = (mode->height - WINDOW_BASE_H) / 2;

						// Set the window position
						glfwSetWindowPos(window, xPos, yPos);
						glfwMakeContextCurrent(window);
						gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
					}
				}
			}
		}
	}

	Game::~Game() {
		dispose();
	}

	int Game::run() {
		auto previousTime = glfwGetTime();
		while (!glfwWindowShouldClose(window)) {
			try {
				glClear(GL_COLOR_BUFFER_BIT);

				auto currentTime = glfwGetTime();
				Game::sceneManager->update(currentTime - previousTime);

				glfwSwapBuffers(window);
				glfwPollEvents();
				previousTime = currentTime;
			}
			catch (std::exception e) {
				// do stuff here
				std::cerr << "ERROR: " << e.what() << std::endl;
				dispose();
				return -1;
			}
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
		Game::sceneManager->dispose();
		terminateGLFW();
	}
}