#include <cstdlib>
#include <stdio.h>
#include <SDL2/SDL.h>

// Screen dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char ** argv)
{
  SDL_Window* window = NULL;
  SDL_Surface* screen_surface = NULL;

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("SDL could not initialize, SDL_Error: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  else
  {
    // Creation of window with some parameters
    window = SDL_CreateWindow("Demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (NULL == window)
    {
      printf("Window could not be created, SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
      // Get the surface drawable from the window
      screen_surface = SDL_GetWindowSurface(window);

      // Fill the surface with white
      SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0xFF, 0xFF, 0xFF));

      // Update the surface of window
      SDL_UpdateWindowSurface(window);

      SDL_Delay(2000);

      SDL_DestroyWindow(window);
    }

    // Quit all SDL subsystems
    SDL_Quit();
  }

  return EXIT_SUCCESS;
}

