#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

#include "defs.h"

// Structure pour gérer la map à afficher (à compléter plus tard)
typedef struct
{

SDL_Texture *background;
SDL_Texture *tile;
int beginx,beginy;//Coord du début pour le héro lorsque le niveau commence
int startX,startY;// Coord du debut de la map
int mapTimer;
} Map;

typedef struct
{
    int hauteur;
    int largeur;
    int interaction;// quelle interaction du joueur avec la Tiles? Mort,bloqué...
    int x,y;

}Tiles;

typedef struct
{
    int life,invincibleTimer;//point de vie et temps d'invicibilité
    int x;//coord du sprite
    int y;//coord du sprite
    int hauteur;//hauteur du sprite
    int largeur;//largeur du sprite
    int type; //Type de sprite , monstre hero, power up?
    int respawnX,respawnY;
    int etat;
    int onGround,timerMort;// sur le sol? et chorno une fois mort
    float dirX,dirY;//vecteur de déplacement avant détéction des collisions avec la map
    int saveX,saveY;//coord de départ
    int jump; // var pour le saut
}Sprites;



typedef struct Input
{

	int escape;

} Input;







#endif // STRUCT_H_INCLUDED
