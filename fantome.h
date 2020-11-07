/*
* Structure de fantome = composee de:
* - un int qui represente une Postion X 
* - un int qui represente une Postion XY
* - un int qui represente sa couleur (1 = Bleu / 2 = Orange / 3 = Rouge / 4 = Rose)
* 1 = deplacement facile / 4 = deplacement difficiles
*/
typedef struct fantome {
	int PosX;
	int PosY;
	int Couleur;
} fantome_t;

/*
* Deplacer(int Couleur, fantome_t F): fonction qui depace le fantome F en fonction de sa Couleur (bleu par defaut ou si couleur different de 2/3/4)
* Ne fait rien si le deplacement est invalide
*/
void deplacer(int Couleur, fantome_t F);

/*
* Verifie les collisions pour valider ou non le deplacement (valide = return 1)
* Variables: ??
*/
int collisionF();
