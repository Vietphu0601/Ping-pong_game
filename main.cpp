
#include "Game.h"


int main() {
	const int FPS = 60;

	Game *game = new Game();
	
	if (!game->init()) {
		std::cout << "Failed to init window" << std::endl;
	} else {
		if (!game->loadMedia()) {
			std::cout << "Failed to load Media" << std::endl;
		}
		else {
			while (game->getGameState()) {
				game->update();
				game->render();
			}
		}
	}
	game->close();
	return 0;
}