#pragma once

#include "framework/interfaces/IDisposable.h"
#include "framework/core/scene.h"

#include <memory>
#include <unordered_map>
#include <string>
#include <typeindex>

namespace Amethyst::Core {
	class SceneManager : IDisposable {
	public:
		SceneManager();
		void dispose() override;

		/// <summary>
		/// Register a scene to the scene manager. It can then be referenced by its type id
		/// </summary>
		/// <typeparam name="T">T is any scene in this scenario</typeparam>
		/// <param name="scene">The scene object you want to register</param>
		template <typename T>
		void registerScene(std::shared_ptr<T> scene) {
			static_assert(std::is_base_of<Scene, T>::value, "T must be derived of Scene");
			scenes[typeid(T)] = scene;
			if (currentScene == nullptr) {

			}
		}

		template <typename T>
		void setScene() {
			auto key = typeid(T);
			if (scenes.find(key) != scenes.end()) {
				if (currentScene != nullptr) currentScene->reset();
				currentScene = scenes[key];
				currentScene->init();
			}
		}

	private:
		std::unordered_map<std::type_index, std::shared_ptr<Scene>> scenes;
		std::shared_ptr<Scene> currentScene;
	};
}