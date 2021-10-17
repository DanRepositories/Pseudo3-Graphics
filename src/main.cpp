#include <cstdlib>
#include <stdio.h>
#include <SDL2/SDL.h>

// Screen dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char ** argv)
{
  SDL_Window* window = NULL;
  SDL_Renderer *renderer;

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
      // Get the renderer for window
      renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
      if (NULL == renderer)
      {
        printf("Renderer could not be created! - SDL Error: %s\n", SDL_GetError());
      }
      else
      {
        SDL_Event event;
        bool quit = false;

        // Main loop
        while (!quit) 
        {
          // Check the events
          while (SDL_PollEvent(&event) != 0)
          {
            if (SDL_QUIT == event.type)
              quit = true;
          }
          
          // Clear screen
          SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
          SDL_RenderClear(renderer);

          // Update Screen
          SDL_RenderPresent(renderer);
        }

        SDL_DestroyRenderer(renderer);
        renderer = NULL;
      }

      // Close the window
      SDL_DestroyWindow(window);
      window = NULL;
    }

    // Quit all SDL subsystems
    SDL_Quit();
  }

  return EXIT_SUCCESS;
}

