#include <SDL.h>
#include <iostream>

int main(int ac, char** av)
{
    int running = 1;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    SDL_CreateWindowAndRenderer(680,460,SDL_WINDOW_RESIZABLE,&window,&renderer);
    SDL_SetWindowTitle(window, "this is kinda fun fr!!!");
    if (window == NULL)
    {
        std::cout << "Could not create window : " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 255, 92, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer,0,460/2,680,460/2);
    SDL_RenderPresent(renderer);

    SDL_Event event;
    SDL_PollEvent(&event);
    while(running == 1)
    {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) running = 0;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}