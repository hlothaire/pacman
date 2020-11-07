#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char* args[] )
{
  SDL_Window *window = NULL;
  if(0 != SDL_Init(SDL_INIT_VIDEO)){
    fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
    return EXIT_FAILURE;
  }
  window = SDL_CreateWindow("TEST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,640, 480, SDL_WINDOW_SHOWN);
  if(NULL == window){
    fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
    return EXIT_FAILURE;
  }
  SDL_Delay(3000);
  SDL_Quit();
  return EXIT_SUCCESS;
}
