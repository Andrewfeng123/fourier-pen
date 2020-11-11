#include <stdio.h>
#include <SDL2/SDL.h>  

const int W = 640;
const int H = 480;

int main() {
    SDL_WINDOW* window = NULL;

    SDL_SURFACE* screenSurface = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return 0;
}