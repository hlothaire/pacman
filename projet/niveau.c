/**
 * \file niveau.c
 * \author Lothaire Holcvart Alexandre Serratore
 * \brief bibliotheque gestion niveau
 */

#include"niveau.h"

char** allouer_tab_2D(int n, int m){
    char** tab = malloc(n * sizeof(char*));
    for(int i =0; i<n; i++){
        tab[i] = malloc(m * sizeof(char*));
    }
     for(int i =0; i<n; i++){
          for(int j =0; j<m; j++){
              tab[i][j] = ' ';
          }
     }
     return tab;
}

void desallouer_tab_2D(char** tab, int n){
    for(int i = 0; i<n; i++){
        free(tab[i]);
    }
}

char** lire_fichier(const char* nomFichier){
  FILE* fichier = fopen(nomFichier, "r");
  if (fichier == NULL){
    printf("Impossible d'ouvrir le fichier text : %s",nomFichier);
  } else {

    int nbLig,nbCol;
    nbLig = 16;
    nbCol = 16;
    char ch[nbLig*nbCol];
    char** tab = allouer_tab_2D(nbLig,nbCol);

    int i = 0;
    while (fgets(ch, nbLig*nbCol, fichier) != NULL){
      for(int j = 0; j< nbCol ; j++){
          tab[i][j] = ch[j];
      }
      i++;
    }
    fclose(fichier);
    return tab;
  }
}

void create_level(char** tab,SDL_Texture* bloc,SDL_Texture *vide,SDL_Texture *gomme,SDL_Renderer *renderer)
{
  for(int i = 0;i<16;i++){
    for(int j = 0;j<16;j++){
      int x = i*32;
      int y = j*32;
      switch(tab[i][j])
      {
        case '0':
            apply_texture(vide,renderer,y,x);
            break;
        case '1':
            apply_texture(gomme,renderer,y,x);
            break;
        case '2':
            apply_texture(bloc,renderer,y,x);
            break;
        case '3':
            apply_texture(gomme,renderer,y,x);
            break;
      }
    }
  }
}
