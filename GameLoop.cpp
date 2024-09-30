#include <SDL.h>
#include <iostream>
#include "Gameloop.h"

const char** titleptr;
int* Xptr;
int* Yptr;
int* widghtptr;
int* heightptr;
int* window_optionptr;

void Gameloop::window_init(const char* title, int X, int Y, int widght, int height, int window_option)
{
	titleptr = &title;
	Xptr = &X;
	Yptr = &Y;
	widghtptr = &widght;
	heightptr = &height;
	window_optionptr = &window_option;
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(title, X, Y, widght, height, SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(window, -1, 0);
};

void Gameloop::eventhandler()
{
	SDL_Event ev;
	SDL_PollEvent(&ev);
		if (ev.type == SDL_QUIT)
		{
			running = false;
			SDL_DestroyWindow(window);
			SDL_DestroyRenderer(renderer);
			SDL_Quit();
		}
		else if (ev.type == SDL_WINDOWEVENT)
		{
			if (ev.window.event == SDL_WINDOWEVENT_RESIZED)
			{
				SDL_SetWindowSize(window, ev.window.data1, ev.window.data2);
				//SDL_DestroyWindow(window);
				//SDL_DestroyRenderer(renderer);
				//window = SDL_CreateWindow(*titleptr, *Xptr, *Yptr, ev.window.data1, ev.window.data2, SDL_WINDOW_RESIZABLE);
				//renderer = SDL_CreateRenderer(window, -1, 0);
			}
			Gameloop::render();
		}
};

void Gameloop::render()
{
	SDL_SetRenderDrawColor(renderer, 255, 92, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}