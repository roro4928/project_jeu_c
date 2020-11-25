#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

#include "defs.h"

// Structure pour g�rer la map � afficher
typedef struct
{

    SDL_Texture *background;
    SDL_Texture *tile;
    int beginx,beginy;//Coord du d�but pour le h�ro lorsque le niveau commence
    int startX,startY;// Coord du debut de la map
} Map;

// Structure pour g�rer les objets (plateformes)
typedef struct
{
    int hauteur;
    int largeur;
    int interaction;// quelle interaction du joueur avec la Tiles? Mort,bloqu�...
    int x,y;

}Tiles;

// Structure pour g�rer le personnage
typedef struct
{
    int x;//coord du sprite
    int y;//coord du sprite
    int hauteur;//hauteur du sprite
    int largeur;//largeur du sprite
}Sprites;



typedef struct Input
{

	int escape, right, left, jump;

} Input;

#endif // STRUCT_H_INCLUDED
