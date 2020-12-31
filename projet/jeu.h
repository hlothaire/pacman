#include <SDL2/SDL.h>


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
	int is_visible;
} pacman_t;

/*
* Structure de fantome = composee de:
* - un int qui represente une Postion X 
* - un int qui represente une Postion Y
* - un int qui represente sa couleur (1 = Bleu / 2 = Orange / 3 = Rouge / 4 = Rose)
* 1 = deplacement facile / 4 = deplacement difficiles
*/
typedef struct fantome {
	int PosX;
	int PosY;
	int Couleur;
    int is_visible;
} fantome_t;

typedef struct sprite {
	int x;
	int y;
	int id;
	int is_visible;
} sprite_t;

typedef struct world{
	pacman_t *joueur;
    fantome_t *fantome1;
	sprite_t **mur;
	sprite_t **gomme;
	int gameover;
	int score;
	int nb_mur;
	int nb_gomme;
} world_t;


void init_pacman(pacman_t* pacman,int PosX, int PosY);

void init_fantome(fantome_t* fantome, int PosX, int PosY);

void init_sprite(sprite_t* sprite,int x,int y,int id);

void init_data(world_t* world);

void clean_data(world_t* world);

void set_visible(sprite_t* sprite);

void set_invisible(sprite_t* sprite);

int is_game_over(world_t *world);

void handle_events(SDL_Event *event,world_t *world);

void init_mur(world_t *world,int x,int y, int index);

void init_gomme(world_t *world,int x,int y, int index);

int collision(int x, int y,sprite_t *sprite);

int collision_wall(int x,int y,world_t *world);

void collision_gomme(world_t *world);

void collision_fantome1(world_t *world);

void update_data(world_t *world);

void move_fantome1(world_t *world);
