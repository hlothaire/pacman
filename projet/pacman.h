/*
* Structure de pacman = composee de:
* - un int qui represente une Postion X 
* - un int qui represente une Postion XY
* - un int qui represente le nombre de vie
*/
typedef struct pacman {
	int PosX;
	int PosY;
	int NbVie = 3;
} pacman_t;

/*
* Deplacer(char touche, pacman_t Joueur): fonction qui depace le joueur en fonction de la touche enfonce
* Ne fait rien si le deplacement est invalide
*/
void deplacer();

/*
* Verifie les collisions pour valider ou non le deplacement (valide = return 1)
* Variables: ??
*/
int collision();
