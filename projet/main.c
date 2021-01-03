/**
 * \file main.c
 * \author Lothaire Holcvart Alexandre Serratore
 * \brief fichier main du jeu
 */
#include"graphic.h"

#define SPRITE_SIZE 32;

int main( int argc, char* args[] )
{
  char** tab;
  SDL_Renderer *renderer = NULL;
  world_t world;
  textures_t texture;
  SDL_Event event;
  SDL_Window *window = NULL;

  if(init_sdl(&window,&renderer,512,512) == -1){
    return EXIT_FAILURE;
  }
  tab = lire_fichier("ressources/niveau/niveau.txt");
  nb_element(tab,&world);
  init_data(&world);
  create_level(tab,&world);
  init_textures(renderer,&texture);
  while(!is_game_over(&world)){
    handle_events(&event,&world);
    update_data(&world);
    refresh_graphics(renderer,&world,&texture);
  }
  printf("\n Partie Terminee.\n Votre score: %d. \n A bientot ! \n", world.score);
  desallouer_tab_2D(tab,16);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  clean_data(&world);
  clean_textures(&texture);
  SDL_Quit();
  return EXIT_SUCCESS;
}
