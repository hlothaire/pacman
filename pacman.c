#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
* Deplacer(char touche): fonction qui depace le joueur en fonction de la touche enfonce
* Ne fait rien si le deplacement est invalide
*/
void deplacer(char touche, pacman_t Joueur){
	//A changer en fonction de la taille du sprite
	int Sprite_Size = 1;
	switch(touche){
		case "z":
			if (collision(Joueur) == 1){
				Joueur.PosY = Joueur.PosY - Sprite_Size ;
				break;
			}else{
				break;
			}
		case "s":
			if (collision(Joueur) == 1){
				Joueur.PosY = Joueur.PosY + Sprite_Size;
				break;
			}else{
				break;
			}
		case "q";
			if (collision(Joueur) == 1){
                Joueur.PosX = Joueur.PosX - Sprite_Size;
                break;
            }else{
				break;
			}
		case "d";
			if (collision(Joueur) == 1){
                Joueur.PosX = Joueur.PosX - Sprite_Size;
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
int collision(pacman_t Joueur){
	return 1;
}
