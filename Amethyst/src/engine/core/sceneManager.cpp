#include "framework/core/sceneManager.h"

#include <iostream>

namespace Amethyst::Core {

	SceneManager::SceneManager() {
		currentScene = nullptr;
	}

	/// <summary>
	/// Update loop for the game.
	/// </summary>
	/// <param name="deltaT">Time between each frame in seconds</param>
	void SceneManager::update(double deltaT) {
		std::cout << deltaT << std::endl;
	}

	void SceneManager::dispose() {
		for (const auto& scene : scenes) {
			scene.second->dispose();
		}
	}
}