#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <stdbool.h>


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
                        terminer = true; break;
                    case SDLK_a:
                        printf("Touche A enfoncee"); break;
                }
        }
    }
    //Quitter SDL
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
}
