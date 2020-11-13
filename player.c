#include "prototypes.h"

Sprites hero;
SDL_Texture *heroTexture;


void initHeroTexture()
{
    heroTexture = loadImage("graphics/meatboy.png");
}


SDL_Texture *getHeroTexture(void)
{
    return heroTexture;
}


int initHerox()
{
    return hero.x=HERO_STARTX;
}

int initHeroy()
{
    return hero.y=HERO_STARTY;
}


void heroTextureClean()
{
    if (heroTexture!= NULL)
    {
    SDL_DestroyTexture(heroTexture);
    heroTexture = NULL;
    }

}
