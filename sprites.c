#include "prototypes.h"

Sprites sprite;
SDL_Texture *spriteTexture;

void initSpriteTexture()
{
    spriteTexture = loadImage("graphics/monstre64.jpg");
}

SDL_Texture *getSpriteTexture(void)
{
    return spriteTexture;
}
 int initSpritex()
 {
     return sprite.x=SPRITE_STARTX;
}
 int initSpritey()
 {
     return sprite.y=SPRITE_STARTY;
}



void spriteTextureClean()
{
    if (spriteTexture!= NULL)
    {
    SDL_DestroyTexture(spriteTexture);
    spriteTexture = NULL;
    }

}
