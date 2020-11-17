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

    hero.jump = hero.y - 100;

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
        if (hero.y != hero.jump)
        {
            hero.y -= 5;
        }
        else
        {
            hero.jump = hero.y - 100;
            input->jump = 0;

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
