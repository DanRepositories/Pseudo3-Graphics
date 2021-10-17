#include <cstdlib>
#include <stdio.h>
#include <SDL2/SDL.h>

// Screen dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Prototypes
bool initResources(SDL_Window *window, SDL_Renderer *renderer);
void mainLoop(SDL_Renderer *renderer);
void close(SDL_Window *window, SDL_Renderer *renderer);

int main(int argc, char ** argv)
{
  SDL_Window* window = NULL;
  SDL_Renderer *renderer;

  if (initResources(window, renderer))
  {
    mainLoop(renderer);

    close(window, renderer);
  }
  else
  {
    exit(EXIT_FAILURE);
  }


  return EXIT_SUCCESS;
}

/**
 * Inicializa los recursos y valida su correcta inicializacion
 * @return true si todo se pudo inicializar bien, en caso contrario false
 * */
bool initResources(SDL_Window *window, SDL_Renderer *renderer)
{
  // Initialize the resources from SDL2
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("SDL could not initialize, SDL_Error: %s\n", SDL_GetError());
    return false;
  }

  // Creation of window with some parameters
  window = SDL_CreateWindow("Demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (NULL == window)
  {
    printf("Window could not be created, SDL_Error: %s\n", SDL_GetError());
    return false;
  }

  // Get the renderer for window
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (NULL == renderer)
  {
    printf("Renderer could not be created! - SDL Error: %s\n", SDL_GetError());
    return false;
  }

  return true;
}

/**
 * Bucle principal del juego
 * */
void mainLoop(SDL_Renderer *renderer)
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
}

/**
 * Close all resources, check if window and renderer aren't NULL
 * */
void close(SDL_Window *window, SDL_Renderer *renderer)
{
  if (renderer != NULL)
  {
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
  }

  if (window != NULL)
  {
    SDL_DestroyWindow(window);
    window = NULL;
  }

  SDL_Quit();
}

