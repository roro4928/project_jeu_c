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
   int cxperso = hero.x + hero.w / 2;
   int xlimmin = getStartX() + LIMITE_X;
   int xlimmax = xlimmin + LIMITE_W;

   if (cxperso < xlimmin)
    {
    setStartX(getStartX() - 3);
    }


    //Si on dépasse par la droite, on avance la caméra de 3 pixels (vous
    //pouvez modifier cette valeur)
    if (cxperso > xlimmax)
    {
        setStartX(getStartX() + 3);
    }


    //Si on arrive au bout de la map à gauche, on stoppe le scrolling
    if (getStartX() < 0)
    {
        setStartX(0);
    }


    //Si on arrive au bout de la map à droite, on stoppe le scrolling à la
    //valeur Max de la map - la moitié d'un écran (pour ne pas afficher du noir).
//    else if (getStartX() + SCREEN_WIDTH >= getMaxX())
//    {
//        setStartX(getMaxX() - SCREEN_WIDTH);
//    }
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
