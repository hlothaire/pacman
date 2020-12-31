#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include "jeu.h"
#define SPRITE_SIZE 32
#define SPRITE_HEIGHT 32
#define PACMAN_HEIGHT 30
#define XdepartJ 160
#define YdepartJ 160
#define XdepartF1 96
#define YdepartF1 96


void init_pacman(pacman_t* pacman,int PosX, int PosY)
{
    pacman->PosX = PosX;
    pacman->PosY = PosY;
    pacman->NbVie = 3;
    pacman->is_visible = 0;
}

void init_fantome(fantome_t* fantome,int PosX, int PosY)
{
    fantome->PosX = PosX;
    fantome->PosY = PosY;
    fantome->Couleur = 1;
    fantome->is_visible = 0;
}

void init_sprite(sprite_t* sprite,int x,int y,int id)
{
  sprite->x = x;
  sprite->y = y;
  sprite->id = id ;
  sprite->is_visible = 0;
}

void init_data(world_t* world)
{
  world->gameover = 0;
  world->joueur = malloc(4*sizeof(int));
  world->fantome1 = malloc(4*sizeof(int));
  world->mur = (sprite_t**)malloc(world->nb_mur*sizeof(sprite_t*));
  for(int j =0; j<world->nb_mur; j++){
      world->mur[j] = malloc(4*sizeof(int));
  }
  world->gomme = (sprite_t**)malloc(world->nb_mur*sizeof(sprite_t*));
  for(int i =0; i<world->nb_gomme; i++){
      world->gomme[i] = malloc(4*sizeof(int));
  }
  init_pacman(world->joueur,XdepartJ,YdepartJ);
  init_fantome(world->fantome1,XdepartF1,YdepartF1);
}

void clean_data(world_t* world)
{
  free(world->joueur);
  free(world->fantome1);
  free(world->mur);
  free(world->gomme);
}

void set_visible(sprite_t* sprite)
{
    sprite->is_visible = 0;
}

void set_invisible(sprite_t* sprite)
{
    sprite->is_visible = 1;
}

int is_game_over(world_t *world)
{
    return world->gameover;
}

void handle_events(SDL_Event *event,world_t *world)
{
  while( SDL_PollEvent( event ) ) {
    if( event->type == SDL_QUIT ) {
      world->gameover = 1;
    }
    if(event->type == SDL_KEYDOWN){
      if(event->key.keysym.sym == SDLK_ESCAPE){
        world->gameover = 1;
      }
      switch(event->key.keysym.sym)
      {
        case SDLK_z:
            move_fantome1(world);
            if(collision_wall(world->joueur->PosX, (world->joueur->PosY - SPRITE_SIZE),world) == 0){
              world->joueur->PosY -= SPRITE_SIZE;
              collision_fantome1(world);
              break;
            }
            break;
        case SDLK_s:
            move_fantome1(world);
            if(collision_wall(world->joueur->PosX, (world->joueur->PosY + SPRITE_SIZE),world) == 0){
              world->joueur->PosY += SPRITE_SIZE;
              collision_fantome1(world);
              break;
            }
            break;
        case SDLK_q:
            move_fantome1(world);
            if(collision_wall(world->joueur->PosX - SPRITE_SIZE,world->joueur->PosY,world) == 0){
              world->joueur->PosX -= SPRITE_SIZE;
              collision_fantome1(world);
              break;
            }
            break;
        case SDLK_d:
            move_fantome1(world);
            if(collision_wall(world->joueur->PosX + SPRITE_SIZE,world->joueur->PosY,world) == 0){
              world->joueur->PosX += SPRITE_SIZE;
              collision_fantome1(world);
              break;
            }
            break;
        }
      }
    }
  }

void init_mur(world_t *world,int x,int y,int index)
 {
   init_sprite(world->mur[index],x,y,2);
 }

void init_gomme(world_t *world,int x,int y,int index)
  {
    init_sprite(world->gomme[index],x,y,1);
  }

int collision(int x, int y,sprite_t *sprite)
{
  int d;
  d = sqrt(pow((x - sprite->y), 2) + pow((y - sprite->x), 2));
  if(d<=(PACMAN_HEIGHT + SPRITE_HEIGHT)/2){
      return 1;
  }
  return 0;
}

int collision_wall(int x,int y,world_t *world)
{
  for(int i=0;i<world->nb_mur;i++){
    if(collision(x,y,world->mur[i]) == 1){
      return 1;
    }
  } return 0;
}

void collision_gomme(world_t *world)
{
  for(int i=0;i<world->nb_gomme;i++){
    if((collision(world->joueur->PosX,world->joueur->PosY,world->gomme[i]) == 1) && world->gomme[i]->is_visible == 0){
      set_invisible(world->gomme[i]);
      world->score += 1;
    }
  }
}

void collision_fantome1(world_t *world)
{
    if(world->joueur->PosX == world->fantome1->PosX && world->joueur->PosY == world->fantome1->PosY){
        world->joueur->PosX = XdepartJ;
        world->joueur->PosY = YdepartJ;
        world->fantome1->PosX = XdepartF1;
        world->fantome1->PosY = YdepartF1;
        world->joueur->NbVie += -1;
        if(world->joueur->NbVie <= 0){
            world->gameover = 1;
        }
    }
}

void update_data(world_t *world)
{
  collision_gomme(world);
}
void move_fantome1(world_t *world)
{
    int PosXJ = world->joueur->PosX;
    int PosYJ = world->joueur->PosY;
    int PosXF = world->fantome1->PosX;
    int PosYF = world->fantome1->PosY;
    //difference de position
    int DX = abs(PosXF - PosXJ);
    int DY = abs(PosYF - PosYJ);
    switch(world->fantome1->Couleur)
    {
        case 1:
            //Si la distance en X est plus grande qu'en Y, alors on bouge sur X
            if(DX > DY){
                //Si F est plus a droite
                if(PosXF > PosXJ){
                    //detection collision gauche
                    if(collision_wall((PosXF - SPRITE_SIZE), PosYF,world) == 0)
                    {
                        world->fantome1->PosX -= SPRITE_SIZE;
                    }else{
                        if(collision_wall(PosXF, (PosYF - SPRITE_SIZE),world) == 0){
                            world->fantome1->PosY -= SPRITE_SIZE;
                        }else{
                            world->fantome1->PosY += SPRITE_SIZE;
                        }
                    }
                }else{
                    //dectection collision droite
                    if(collision_wall((PosXF + SPRITE_SIZE), PosYF,world) == 0){
                        world->fantome1->PosX += SPRITE_SIZE;
                    }else{
                        if(collision_wall(PosXF, (PosYF - SPRITE_SIZE),world) == 0){
                            world->fantome1->PosY -= SPRITE_SIZE;
                        }else{
                            world->fantome1->PosY += SPRITE_SIZE;
                        }
                    }
                }
            }else{
                if(PosYF > PosYJ){
                    //dectection collision haut
                    if(collision_wall(PosXF, (PosYF - SPRITE_SIZE),world) == 0){
                        world->fantome1->PosY -= SPRITE_SIZE;
                    }else{
                        if(collision_wall((PosXF - SPRITE_SIZE), PosYF,world) == 0){
                            world->fantome1->PosX -= SPRITE_SIZE;
                        }else{
                            world->fantome1->PosX +=SPRITE_SIZE;
                        }
                    }
                }else{
                    //Detection collision bas
                    if(collision_wall(PosXF, (PosYF + SPRITE_SIZE),world) == 0){
                        world->fantome1->PosY += SPRITE_SIZE;
                    }else{
                        if(collision_wall((PosXF - SPRITE_SIZE), PosYF,world) == 0){
                            world->fantome1->PosX -= SPRITE_SIZE;
                        }else{
                            world->fantome1->PosX +=SPRITE_SIZE;
                        }
                    }
                }
            }

    }
}
