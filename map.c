
#include "prototypes.h"

Map map;

/**
* @brief: Cette fonction remplie la structure map pour l'initialiser
*@param:
*
*/
void initMaps(void)
{
    // Charge l'image du fond (background)
    map.background = loadImage("graphics/mountain.jpg");
    map.tile = loadImage("graphics/plateforme.png");
    map.beginx=HERO_STARTX;
    map.beginy=HERO_STARTY;
    map.startX=0;
    map.startY=0;

}

/**
* @brief: Cette fonction permet d'initialiser les plateformes en les stockant dans un tableau dynamique
*@param:
*       <output>: Tiles **tiles: tableau de pointeur
*/
Tiles **initTiles(void)
{
    Tiles **tiles = (Tiles**) malloc(sizeof(Tiles*)*NBRE_TILES);
    if (tiles)
    {

        for (int i=0;i<NBRE_TILES;i++)
        {
            tiles[i] = (Tiles*) malloc(sizeof(Tiles));
            if (tiles[i])
            {
                tiles[i]->interaction=BLOQUE;
                tiles[i]->largeur=TILES_WIDTH;
                tiles[i]->hauteur= TILES_HEIGHT;
                if (i<NBRE_TILES/2){

                        tiles[i]->x=128+i*TILES_WIDTH;
                        tiles[i]->y=420-i*TILES_HEIGHT;

                }
                else{
                     tiles[i]->x=128+i*TILES_WIDTH;
                    tiles[i]->y=tiles[NBRE_TILES/2-1]->y;
                }

            }
        }
    }
    return tiles;
}

/**
* @brief: Cette fonction r�cup�re la texture du background
*@param:
*       <output>: SDL_Texture *: pointeur vers la texture du background dans la structure de la map
*/
SDL_Texture *getBackground(void)
{
    return map.background;
}

/**
* @brief: Cette fonction r�cup�re la texture des tiles
*@param:
*       <output>: SDL_Texture *: pointeur vers la texture des tiles dans la structure de la map
*/
SDL_Texture *getTiles(void)
{
    return map.tile;
}

/**
* @brief: Cette fonction r�cup�re les coordonn�es en abscisse de chaque tiles
*@param:
*       <intput>: Tiles **tiles: tableau de pointeur
*       <input>: int indice: num�ro du tiles dans le tableau
*/
int getTileX(Tiles **tiles, int indice)
{
    if(initTiles()[indice])
    {
    return tiles[indice]->x;
    }
    else{
        exit(1);
    }
}

/**
* @brief: Cette fonction r�cup�re les coordonn�es en ordonn�e de chaque tiles
*@param:
*       <intput>: Tiles **tiles: tableau de pointeur
*       <input>: int indice: num�ro du tiles dans le tableau
*/
int getTileY(Tiles **tiles, int indice)
{
    if(initTiles()[indice])
    {
        return tiles[indice]->y;
    }
    else{
        exit(1);
    }

}

/**
* @brief: Cette fonction est un guetteur qui r�cup�re la coordonn�e en abscisse du d�but de la map
*@param:
*       <output>: map.startX: coordonn�e en abscisse du d�but de la map
*/
int getStartX(void)
{
    return map.startX;
}

/**
* @brief: Cette fonction est un setteur qui d�finit la coordonn�e en abscisse du d�but de la map
*@param:
*       <input>: int valeur: nouvelle coordonn�e en abscisse du d�but de la map
*/
void setStartX(int valeur)
{
    map.startX = valeur;
}

/**
* @brief: Cette fonction est un guetteur qui r�cup�re la coordonn�e en ordonn�e du d�but de la map
*@param:
*       <output>: map.startX: coordonn�e en ordonn�e du d�but de la map
*/
int getStartY(void)
{
    return map.startY;
}

/**
* @brief: Cette fonction est un setteur qui d�finit la coordonn�e en ordonn�e du d�but de la map
*@param:
*       <input>: int valeur: nouvelle coordonn�e en ordonn�e du d�but de la map
*/
void setStartY(int valeur)
{
    map.startY = valeur;
}

/**
* @brief: Cette fonction est un guetteur qui r�cup�re la coordonn�e en abscisse du d�but du hero
*@param:
*       <output>: map.beginx: coordonn�e en abscisse du d�but du hero
*/
int getBeginX(void)
{
    return map.beginx;
}

/**
* @brief: Cette fonction est un guetteur qui r�cup�re la coordonn�e en ordonn�e du d�but du hero
*@param:
*       <output>: map.beginy: coordonn�e en ordonn�e du d�but du hero
*/
int getBeginY(void)
{
return map.beginy;
}

/**
* @brief: Cette fonction lib�re la m�moire de la map
*@param:
*
*/
void cleanMaps(void)
{
// Lib�re la texture du background
if (map.background != NULL)
{
SDL_DestroyTexture(map.background);
map.background = NULL;
}

if (map.tile != NULL)
{
SDL_DestroyTexture(map.tile);
map.tile = NULL;
}

if (initTiles())
{
    for(int i=0;i<NBRE_TILES;i++)
    {
        free(initTiles()[i]);
    }
    free(initTiles());
}


}
