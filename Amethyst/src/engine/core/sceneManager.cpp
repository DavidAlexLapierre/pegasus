#include "framework/core/sceneManager.h"

namespace Amethyst::Core {

	SceneManager::SceneManager() {
		currentScene = nullptr;
	}

	void SceneManager::dispose() {
		for (const auto& scene : scenes) {
			scene.second->dispose();
		}
	}
}