#include "game/core/app.h"

int main() {
	auto app = new Game::App();
	app->run();

	app->dispose();

	delete app;
}