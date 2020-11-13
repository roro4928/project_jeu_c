
#include "prototypes.h"

Map map;

void initMaps(void)
{
// Charge l'image du fond (background)
map.background = loadImage("graphics/mountain.jpg");
map.tiles = loadImage("graphics/plateforme.png");

}


SDL_Texture *getBackground(void)
{
return map.background;
}

SDL_Texture *getTiles(void)
{
return map.tiles;
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
