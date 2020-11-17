#include "prototypes.h"

player hero;
SDL_Texture *heroTexture;

player *getPlayer(void)
{
    return &hero;
}

int getPlayerx(void)
{
    return hero.x;
}

int getPlayery(void)
{
    return hero.y;
}


void initHeroTexture()
{
    heroTexture = loadImage("graphics/meatboy.png");
}


SDL_Texture *getHeroTexture(void)
{
    return heroTexture;
}


void initializePlayer(void)
{
    hero.x = HERO_STARTX;
    hero.y = HERO_STARTY;

    hero.w = HERO_WIDTH;
    hero.h = HERO_HEIGHT;

    hero.isFalling = 0;

}

void updatePlayer(Input *input)
{
    if (input->left == 1)
    {
        hero.x -= HERO_SPEED;
    }

    if (input->right == 1)
    {
        hero.x += HERO_SPEED;
    }

    if (input->jump == 1)
    {
        if (hero.y >= 247 && hero.isFalling == 1)
        {
            hero.y = 247;
            hero.isFalling = 0;
            input->jump = 0;
        }

        else if (hero.y >= 100 && hero.isFalling == 1)
            {
                hero.y +=5;
                hero.isFalling = 1;

            }
        else
        {
            hero.y -=5;
            if (hero.y <= 105)
                hero.isFalling = 1;
        }

    }

}

void heroTextureClean()
{
    if (heroTexture!= NULL)
    {
    SDL_DestroyTexture(heroTexture);
    heroTexture = NULL;
    }

}
