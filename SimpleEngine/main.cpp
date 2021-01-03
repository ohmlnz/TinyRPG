#include "Game.h"

int main(int argc, char* argv[])
{
	const int FPS = 15;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	Game game;

	game.init("SimpleEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	while (game.running())
	{
		frameStart = SDL_GetTicks();

		game.handleEvents();
		game.update();
		game.render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game.clean();

	return 0;
}