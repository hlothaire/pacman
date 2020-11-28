/*
* Structure de pacman = composee de:
* - un int qui represente une Postion X 
* - un int qui represente une Postion Y
* - un int qui represente le nombre de vie
*/
typedef struct pacman {
	int PosX;
	int PosY;
	int NbVie;
} pacman_t;

/*
 * Constructeur du joueur
 */
pacman_t ConsJoueur(int PosX, int PosY, int NbVie);

/*
* Deplacer(int touche, pacman_t Joueur): fonction qui depace le joueur en fonction de la touche enfonce
* //1 gauche 2 bas 3 droite 4 haut
* Ne fait rien si le deplacement est invalide
*/
void deplacer(int touche, pacman_t Joueur); //1 gauche 2 bas 3 droite 4 haut

/*
* Verifie les collisions pour valider ou non le deplacement (valide = return 1)
* Variables: Directire: 1 gauche 2 bas 3 droite 4 haut
*            Joueur => Coordonne du jouer Joueur a verifier
*/
int collision(pacman_t Joueur, int direction);
