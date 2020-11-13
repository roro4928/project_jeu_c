
#include "prototypes.h"


Map map;


void initMaps(void)
{
// Charge l'image du fond (background)
map.background = loadImage("graphics/background.png");
}


SDL_Texture *getBackground(void)
{
return map.background;
}


void cleanMaps(void)
{
// Libère la texture du background
if (map.background != NULL)
{
SDL_DestroyTexture(map.background);
map.background = NULL;
}

}
