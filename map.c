
#include "prototypes.h"

Map map;


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


SDL_Texture *getBackground(void)
{
return map.background;
}

SDL_Texture *getTiles(void)
{
return map.tile;
}

int getTileX(Tiles **tiles, int indice)
{
    return tiles[indice]->x;
}

int getTileY(Tiles **tiles, int indice)
{
    return tiles[indice]->y;
}


int getStartX(void)
{
return map.startX;
}

void setStartX(int valeur)
{
map.startX = valeur;
}

int getStartY(void)
{
return map.startY;
}

void setStartY(int valeur)
{
map.startY = valeur;
}


int getBeginX(void)
{
return map.beginx;
}

int getBeginY(void)
{
return map.beginy;
}


void cleanMaps(void)
{
// Libère la texture du background
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
