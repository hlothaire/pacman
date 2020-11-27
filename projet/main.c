#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "pacman.h"
#define SPRITE_SIZE 32;

int main(int argc, char *argv[])
{
    SDL_Window* fenetre; //Declaration de la fenetre
    SDL_Event evenements; //Evenements lies a la fenetres
    bool terminer = false; //boolean de gestion de fin de partie/fenetre/jeu

    if(SDL_Init(SDL_INIT_VIDEO < 0)) //Initialisation de la SDL2
    {
        printf("Erreur d'initialisation de la SDL: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    //Creer la fenetre
    fenetre = SDL_CreateWindow("FenetreSDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_RESIZABLE);
    if(fenetre == NULL) //En cas d erreur
    {
        printf("Erreur de la creation de fenetre: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    
    //creation du joueur
    pacman_t Joueur = ConsJoueur(0,0,3);
    
    //boucle principale
    while(!terminer){
        SDL_PollEvent(&evenements);
        switch(evenements.type)
        {
            case SDL_QUIT:
                terminer = true;break;
            case SDL_KEYDOWN:
                switch(evenements.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        printf("\n*------------------------------------*\nFermeture du jeu...\nAu revoir !\n*------------------------------------*\n");
                        terminer = true; break;
                    case SDLK_z:
                        printf("Touche Z enfoncee \n");
                        if (collision(Joueur, 4) == 1){
                            Joueur.PosY = Joueur.PosY - SPRITE_SIZE;
                        }
                        printf("x = %d / y = %d\n", Joueur.PosX, Joueur.PosY);
                        break;
                    case SDLK_s:
                        printf("Touche S enfoncee \n");
                        if (collision(Joueur, 2) == 1){
                            Joueur.PosY = Joueur.PosY + SPRITE_SIZE;
                        }
                        //Joueur.PosY = Joueur.PosY + 1;
                        printf("x = %d / y = %d\n", Joueur.PosX, Joueur.PosY);
                        break;
                    case SDLK_q:
                        printf("Touche Q enfoncee \n");
                        if (collision(Joueur, 1) == 1){
                            Joueur.PosX = Joueur.PosX - SPRITE_SIZE;
                        }
                        printf("x = %d / y = %d\n", Joueur.PosX, Joueur.PosY);
                        break;
                    case SDLK_d:
                        printf("Touche D enfoncee \n");
                        if (collision(Joueur, 3) == 1){
                            Joueur.PosX = Joueur.PosX + SPRITE_SIZE;
                        }
                        printf("x = %d / y = %d\n", Joueur.PosX, Joueur.PosY);
                        break;
                }
        }
    }
    //Quitter SDL
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
}
