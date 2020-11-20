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

    setStartX(getStartX());

    hero.jump = hero.y - JUMPHEIGHT;

}

void scroll(void)
{
    SDL_Rect camera = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

    camera.x = (getPlayerx + HERO_WIDTH / 2) - SCREEN_WIDTH / 2;
    camera.y = (getPlayery + HERO_HEIGHT / 2) - SCREEN_HEIGHT / 2;

    if( camera.x < 0 )
    {
        camera.x = 0;
    }
    if( camera.y < 0 )
    {
        camera.y = 0;
    }
    if( camera.x > LEVEL_W - camera.w )
    {
        camera.x = LEVEL_W - camera.w;
    }
    if( camera.y > LEVEL_H - camera.h )
    {
        camera.y = LEVEL_H - camera.h;
    }
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
            hero.jump = hero.y - JUMPHEIGHT;
            input->jump = 0;
        }

    }
    scroll();

}



void heroTextureClean()
{
    if (heroTexture!= NULL)
    {
    SDL_DestroyTexture(heroTexture);
    heroTexture = NULL;
    }

}
