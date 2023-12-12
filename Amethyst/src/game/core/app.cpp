#include "game/core/app.h"

#include "game/scenes/mainScene.h"

namespace Game {
	void App::registerScenes() {
		Game::sceneManager->registerScene(std::make_shared<MainScene>());
	}
}