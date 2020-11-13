#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

#include "defs.h"

// Structure pour gérer la map à afficher (à compléter plus tard)
typedef struct
{

SDL_Texture *background;
SDL_Texture *tiles;

} Map;

typedef struct
{
    int x;
    int y;
    int longeur;
    int largeur;
    int type;
}Sprites;



typedef struct Input
{

	int escape;

} Input;







#endif // STRUCT_H_INCLUDED
