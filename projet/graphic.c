/**
 * \file graphic.h
 * \author Lothaire Holcvart Alexandre Serratore
 * \brief bibliotheque gestion textures et affichage graphique
 */

#include "graphic.h"


void clean_texture(SDL_Texture *texture)
{
  if(NULL != texture){
      SDL_DestroyTexture(texture);
    }
}

void clean_textures(textures_t *textures)
{
  clean_texture(textures->joueur);
  clean_texture(textures->fantome);
  clean_texture(textures->gomme);
  clean_texture(textures->mur);
}

void  init_textures(SDL_Renderer *renderer, textures_t *textures)
{
  textures->joueur = load_imageJ("ressources/sprites/pacman.bmp",renderer);
  textures->fantome = load_imageJ("ressources/sprites/fantome.bmp",renderer);
  textures->mur = load_image("ressources/sprites/bloc.bmp",renderer);
  textures->gomme = load_image("ressources/sprites/gomme.bmp",renderer);
}

void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t * sprite)
{
    apply_texture(texture,renderer,sprite->x,sprite->y);
}

void apply_player(SDL_Renderer *renderer,SDL_Texture *texture,pacman_t *pacman)
{
  apply_texture(texture,renderer,pacman->PosX,pacman->PosY);
}

void apply_fantome(SDL_Renderer *renderer,SDL_Texture *texture,fantome_t *fantome)
{
  apply_texture(texture,renderer,fantome->PosX,fantome->PosY);
}

void clear_renderer(SDL_Renderer *renderer){
  SDL_RenderClear(renderer);
}

void apply_texture(SDL_Texture *texture,SDL_Renderer *renderer,int x, int y){
  SDL_Rect dst = {0, 0, 0, 0};

  SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
  dst.x = x; dst.y=y;

  SDL_RenderCopy(renderer, texture, NULL, &dst);
}


SDL_Texture *load_image(const char path[], SDL_Renderer *renderer){
  SDL_Surface *tmp = NULL;
  SDL_Texture *texture = NULL;
  tmp = SDL_LoadBMP(path);
  if(NULL == tmp)
  {
      fprintf(stderr, "Erreur pendant chargement image BMP: %s", SDL_GetError());
      return NULL;
  }
  //SDL_SetColorKey(tmp, SDL_TRUE, SDL_MapRGB(tmp->format, 255, 0, 255));
  texture = SDL_CreateTextureFromSurface(renderer, tmp);
  SDL_FreeSurface(tmp);
  if(NULL == texture)
  {
      fprintf(stderr, "Erreur pendant creation de la texture: %s", SDL_GetError());
      return NULL;
  }
  return texture;
}

void update_screen(SDL_Renderer *renderer){
  SDL_RenderPresent(renderer);
}

void clean_sdl(SDL_Renderer *renderer,SDL_Window *window){
  if(NULL != renderer)
      SDL_DestroyRenderer(renderer);
  if(NULL != window)
      SDL_DestroyWindow(window);
  SDL_Quit();
}

int init_sdl(SDL_Window **window, SDL_Renderer **renderer, int width, int height){
  if(0 != SDL_Init(SDL_INIT_VIDEO))
  {
      fprintf(stderr, "Erreur initialisation de la SDL : %s", SDL_GetError());
      return -1;
  }
  if(0 != SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, window, renderer))
  {
      fprintf(stderr, "Erreur lors de la creation de l'image et du renderer : %s", SDL_GetError());
      return -1;
  }
  return 0;
}

SDL_Texture *load_imageJ(const char path[], SDL_Renderer *renderer){
  SDL_Surface *tmp = NULL;
  SDL_Texture *texture = NULL;
  tmp = SDL_LoadBMP(path);
  if(NULL == tmp)
  {
      fprintf(stderr, "Erreur pendant chargement image BMP: %s", SDL_GetError());
      return NULL;
  }
  SDL_SetColorKey(tmp, SDL_TRUE, SDL_MapRGB(tmp->format, 0, 0, 0));
  texture = SDL_CreateTextureFromSurface(renderer, tmp);
  SDL_FreeSurface(tmp);
  if(NULL == texture)
  {
      fprintf(stderr, "Erreur pendant creation de la texture: %s", SDL_GetError());
      return NULL;
  }
  return texture;
}

void apply_mur(SDL_Renderer *renderer, SDL_Texture *textures, world_t* world)
{
  for(int i=0;i<world->nb_mur;i++){
    if(world->mur[i]->is_visible ==0){
      apply_texture(textures,renderer,world->mur[i]->y,world->mur[i]->x);
    }
  }
}

void apply_gomme(SDL_Renderer *renderer, SDL_Texture *textures, world_t* world)
{
  for(int i=0;i<world->nb_gomme;i++){
    if(world->gomme[i]->is_visible ==0){
      apply_texture(textures,renderer,world->gomme[i]->y,world->gomme[i]->x);
    }
  }
}

void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures)
{
  clear_renderer(renderer);
  apply_mur(renderer,textures->mur,world);
  apply_gomme(renderer,textures->gomme,world);
  if(world->joueur->is_visible == 0){
      apply_player(renderer,textures->joueur,world->joueur);
  }
  if(world->fantome->is_visible == 0){
      apply_fantome(renderer,textures->fantome,world->fantome);
  }
  SDL_RenderPresent(renderer);
}
