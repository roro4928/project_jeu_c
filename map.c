
#include "prototypes.h"

Map map;

void initMaps(void)
{
    // Charge l'image du fond (background)
    map.background = loadImage("graphics/background.png");
    map.tiles = loadImage("graphics/plateforme.png");
    map.startX = 0;

}


SDL_Texture *getBackground(void)
{
    return map.background;
}

SDL_Texture *getTiles(void)
{
    return map.tiles;
}



int getStartX(void)
{
return map.startX;
}

void setStartX(int valeur)
{
map.startX = valeur;
}


void cleanMaps(void)
{
    // Libère la texture du background
    if (map.background != NULL)
    {
        SDL_DestroyTexture(map.background);
        map.background = NULL;
    }

    if (map.tiles != NULL)
    {
        SDL_DestroyTexture(map.tiles);
        map.tiles = NULL;
    }

}
