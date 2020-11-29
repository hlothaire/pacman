#include"niveau.h"
#include"graphic.h"
#include"pacman.h"
#include <stdbool.h>
#define SPRITE_SIZE 32;

int main( int argc, char* args[] )
{
  char** tab;
  SDL_Renderer *renderer = NULL;
  SDL_Texture *pacman = NULL;
  SDL_Texture *gomme = NULL;
  SDL_Texture *bloc = NULL;
  SDL_Texture *vide = NULL;
  bool terminer = false;
  SDL_Event event;
  SDL_Window *window = NULL;

  if(init_sdl(&window,&renderer,512,512) == -1){
    return EXIT_FAILURE;
  }
  bloc = load_image("ressources/sprites/bloc.bmp",renderer);
  vide = load_image("ressources/sprites/vide.bmp",renderer);
  gomme = load_image("ressources/sprites/gomme.bmp",renderer);
  pacman = load_image("ressources/sprites/pacman.bmp",renderer);
  tab = lire_fichier("ressources/niveau/niveau.txt");

  pacman_t Joueur = ConsJoueur(160,160,3);

  while(!terminer){
    while(SDL_PollEvent(&event)){
      if( event.type == SDL_QUIT ) {
        terminer = true;
      }
      if(event.type == SDL_KEYDOWN){
        if(event.key.keysym.sym == SDLK_ESCAPE){
            terminer = true;
        }
        switch(event.key.keysym.sym)
        {
            case SDLK_z:
                Joueur.PosY -= SPRITE_SIZE;
                break;
            case SDLK_s:
                Joueur.PosY += SPRITE_SIZE;
                break;
            case SDLK_q:
                Joueur.PosX -= SPRITE_SIZE;
                break;
            case SDLK_d:
                Joueur.PosX += SPRITE_SIZE;
                break;
        }
      }
    }
    create_level(tab,bloc,vide,gomme,renderer);
    apply_texture(pacman,renderer,Joueur.PosX,Joueur.PosY);
    SDL_RenderPresent(renderer);
  }

  desallouer_tab_2D(tab,16);
  SDL_DestroyTexture(pacman);
  SDL_DestroyTexture(bloc);
  SDL_DestroyTexture(vide);
  SDL_DestroyTexture(gomme);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return EXIT_SUCCESS;
}
