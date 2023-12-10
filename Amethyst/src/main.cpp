#include "game/core/app.h"

int main() {
	auto app = new Game::App("Amethyst");

	auto status = app->run();
	app->dispose();
	
	delete app;

	return status;
}