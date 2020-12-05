/**
 * \file graphic.h
 * \author Lothaire Holcvart Alexandre Serratore
 * \brief bibliotheque gestion textures et affichage graphique
 */

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "niveau.h"

typedef struct textures_s{
  SDL_Texture* joueur;
  SDL_Texture* mur;
  SDL_Texture* gomme;
} textures_t;




/**
 * \brief La fonction nettoie une texture en mémoire
 * \param texture la texture à nettoyer
*/

void clean_texture(SDL_Texture *texture);

void clean_textures(textures_t *textures);

void init_textures(SDL_Renderer *renderer, textures_t *textures);

void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t * sprite);

void apply_player(SDL_Renderer *renderer,SDL_Texture *texture,pacman_t *pacman);

/**
 * \brief La fonction vide le contenu graphique du renderer lié à l'écran de jeu
 * \param renderer le renderer de l'écran
*/

void clear_renderer(SDL_Renderer *renderer);

/**
 * \brief La fonction permet d'appliquer une texture sur le renderer à une position donnée.
 * \param texture  la texture que l'on va appliquer
 * \param renderer le renderer qui va recevoir la texture
 * \param x point en haut à gauche de la surface
 *  \param y point en haut à gauche de la surface
*/


void apply_texture(SDL_Texture *texture,SDL_Renderer *renderer,int x, int y);


/**
 * \brief La fonction charge une image  et renvoie la texture correspondante
 * \param path est le chemin du fichier image.
 * \param renderer le renderer
 * \return la surface SDL contenant l'image.
 * renvoie NULL si le chargement a échoué
*/

SDL_Texture *load_image(const char path[], SDL_Renderer *renderer);

/**
 * \brief La fonction met à jour l'écran avec le contenu du renderer
 * \param renderer le renderer de l'écran
*/

void update_screen(SDL_Renderer *renderer);

/**
 * \brief La fonction nettoie le renderer et la fenêtre du jeu en mémoire
 * \param renderer le renderer à nettoyer
 * \param window la fenêtre à nettoyer
*/

void clean_sdl(SDL_Renderer *renderer,SDL_Window *window);

/**
 * \brief La fonction initialise la SDL.
 * Elle crée la fenêtre du jeu ainsi que le renderer
 * \param window la fenêtre du jeu
 * \param renderer le renderer
 * \param width largeur de l'écran de jeu
 * \param height hauteur de l'écran de jeu
 * \return -1 en cas d'erreur, 0 sinon
*/

int init_sdl(SDL_Window **window, SDL_Renderer **renderer, int width, int height);

SDL_Texture *load_imageJ(const char path[], SDL_Renderer *renderer);

void apply_mur(SDL_Renderer *renderer, SDL_Texture *textures, world_t* world);

void apply_gomme(SDL_Renderer *renderer, SDL_Texture *textures, world_t* world);

void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures);
