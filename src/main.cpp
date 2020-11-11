#include <iostream>
#include <SDL2/SDL.h>  

const int W = 640;
const int H = 480;

int main(int argc, char* args[]) {
    SDL_Window* window = NULL;

    SDL_Surface* screenSurface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError();
        return 0;
    }
    else
    {
        //Create window
        window = SDL_CreateWindow("Andrew and Yvonne's first window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, W, H, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            std::cout << "Window could not be created! SDL_Error: " << SDL_GetError();
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface(window);

            // Fill the surface black
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));

            // Update the surface
            SDL_UpdateWindowSurface(window);

            // wait two seconds
            SDL_Delay(2000);
        }
    }

    // Destroy window
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    SDL_Quit();

    return 0;
}