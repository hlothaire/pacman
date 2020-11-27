#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "pacman.h"
#define SPRITE_SIZE 32

/*
 * Constructeur du joueur
 */
pacman_t ConsJoueur(int PosX, int PosY, int NbVie){
    pacman_t Joueur;
    Joueur.PosX = PosX;
    Joueur.PosY = PosY;
    Joueur.NbVie = NbVie;
    return Joueur;
}

/*
* Deplacer(int touche, pacman_t Joueur): fonction qui depace le joueur en fonction de la touche enfonce
* //1 gauche 2 bas 3 droite 4 haut
* Ne fait rien si le deplacement est invalide
*/
void deplacer(int touche, pacman_t Joueur){
	//A changer en fonction de la taille du sprite
	int Sprite_Size = 1;
	switch(touche){
		case 4:
			if (collision(Joueur,4) == 1){
				Joueur.PosY = Joueur.PosY - Sprite_Size ;
				break;
			}else{
				break;
			}
		case 2:
			if (collision(Joueur,2) == 1){
				Joueur.PosY = Joueur.PosY + 1;
				break;
			}else{
				break;
			}
        case 1:
			if (collision(Joueur,1) == 1){
                Joueur.PosX = Joueur.PosX - Sprite_Size;
                break;
            }else{
				break;
			}
        case 3:
			if (collision(Joueur,3) == 1){
                Joueur.PosX = Joueur.PosX - Sprite_Size;
                break;
            }else{
				break;
			}
	}
}

/*
* Verifie les collisions pour valider ou non le deplacement (valide = return 1)
* Variables: Directire: 1 gauche 2 bas 3 droite 4 haut
*            Joueur => Coordonne du jouer Joueur a verifier
*/
int collision(pacman_t Joueur, int direction){
    switch(direction){
		case 4://Monter
			if(Joueur.PosY - SPRITE_SIZE < 0){
                return 0;
                break;
			}else{
				break;
			}
		case 2://descendre
			if(Joueur.PosY + SPRITE_SIZE > 600){
                return 0;
                break;
			}else{
				break;
			}
        case 1://gauche
			if (Joueur.PosX - SPRITE_SIZE < 0){
                return 0;
                break;
            }else{
				break;
			}
        case 3://droite
			if (Joueur.PosX + SPRITE_SIZE > 600){
                return 0;
                break;
            }else{
				break;
			}
	}
	return 1;
}
