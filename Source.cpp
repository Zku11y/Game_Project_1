#include <SDL.h>
#include <iostream>
#include "Gameloop.h"

Gameloop* game = nullptr;
int main(int argc,char** argv)
{
	game = new Gameloop();
	game->running = true;
	game->window_init("nice", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	while (game->running)
	{
		game->eventhandler();
		game->render();
	}
	return 0;
}