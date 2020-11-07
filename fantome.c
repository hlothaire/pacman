#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

/*
* Deplacer(int Couleur, fantome_t F): fonction qui depace le fantome F en fonction de sa Couleur (bleu par defaut ou si couleur different de 2/3/4)
* Ne fait rien si le deplacement est invalide
*/
void deplacer(int Couleur, fantome_t F){
	//A changer en fonction de la taille du sprite
	int Sprite_Size = 1;
    //Deplacement: https://fr.wikipedia.org/wiki/Pac-Man#Personnages
	switch(Couleur){
		default:
			if (collision(F) == 1){
				//Instructions deplacement
				break;
			}else{
				break;
			}
		case 2:
			if (collision(F) == 1){
				//Instructions deplacement
				break;
			}else{
				break;
			}
		case 3;
			if (collision(F) == 1){
                //Instructions deplacement
                break;
            }else{
				break;
			}
        case 4:
			if (collision(F) == 1){
                //Instructions deplacement
                break;
            }else{
				break;
			}
	}
}

/*
* Verifie les collisions pour valider ou non le deplacement (valide = return 1)
* Variables: ??
*/
int collisionF(){
    return 1;
}
