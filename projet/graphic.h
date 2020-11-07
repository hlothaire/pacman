/**
 * \file graphic.h
 * \author Lothaire Holcvart
 * \brief bibliotheque gestion textures et affichage graphique
 */

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Représentation pour stocker les textures nécessaires à l'affichage graphique
*/

struct textures_s{
    SDL_Texture* background; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* fantome;/*!< Texture liée au fantome */
    SDL_Texture* joueur;/*< Texture liée au joueur */
    TTF_Font * font; /*!< champ lié a la police*/
};

/**
 * \brief Type qui correspond aux textures du jeu
*/

typedef struct textures_s textures_t;

/**
 * \brief La fonction nettoie les textures
 * \param textures les textures
*/

void clean_textures(textures_t *textures);

/**
 * \brief La fonction applique la texture du fond sur le renderer lié à l'écran de jeu
 * \param renderer le renderer
 * \param textures les textures du jeu
*/

void apply_background(SDL_Renderer *renderer, textures_t *textures);
