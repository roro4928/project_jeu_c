#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

#include "defs.h"

// Structure pour gérer la map à afficher (à compléter plus tard)
typedef struct
{

SDL_Texture *background;
SDL_Texture *tiles;
int startX;

} Map;

typedef struct
{
    int x;
    int y;
    int longeur;
    int largeur;
    int type;
}Sprites;

typedef struct
{
    int x;
    int y;
    int h;
    int w;
    int jump;
}player;



typedef struct Input
{

	int escape, right, left, jump;

} Input;


#endif // STRUCT_H_INCLUDED
