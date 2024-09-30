#pragma once
class Gameloop
{
public:
	void window_init(const char *title, int X, int Y, int width, int height, int window_flag);
	void window_resize(const char* title, int X, int Y, int width, int height, int window_flag);
	void eventhandler();
	void update();
	void render();
	void clean();
	bool running;
	SDL_Window *window;
	SDL_Renderer* renderer;
};

