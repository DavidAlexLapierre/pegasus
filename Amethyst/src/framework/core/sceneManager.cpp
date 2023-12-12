#include "framework/core/sceneManager.h"

namespace Amethyst::Core {

	SceneManager::SceneManager() {
		currentScene = nullptr;
	}

	/// <summary>
	/// Update loop for the game.
	/// </summary>
	/// <param name="deltaT">Time between each frame in seconds</param>
	void SceneManager::update(double deltaT) {
		if (currentScene != nullptr) {

		}
		else {
			throw std::exception("Make sure to register a scene in the SceneManager");
		}
	}

	void SceneManager::dispose() {
		for (const auto& scene : scenes) {
			scene.second->dispose();
		}
	}
}