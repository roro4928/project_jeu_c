#include "prototypes.h"

Sprites hero;
SDL_Texture *heroTexture;

Sprites *getHero(void)
{
    return &hero;
}

void initHeroTexture()
{
    heroTexture = loadImage("graphics/meatboy.png");
}


SDL_Texture *getHeroTexture(void)
{
    return heroTexture;
}

//Renvoie la coordonn�e x du h�ro
int getHerox(void)
{
return hero.x;
}
//Renvoie la coordonn�e y du h�ro
int getHeroy(void)
{
return hero.y;
}
//Change la coordonn�ee x du h�ro
void setHerox(int valeur)
{
hero.x = valeur;
}

//Change la coordonn�ee y du h�ro
void setHeroy(int valeur)
{
hero.y = valeur;
}


void initializeHero(void)
{

//PV � 3
hero.life = 3;

//Timer d'invincibilit� � 0
hero.invincibleTimer = 0;

//Indique l'�tat et la direction de notre h�ros
hero.etat = IDLE;

hero.x = getBeginX();
hero.y = getBeginY();

/* Hauteur et largeur de notre h�ros */
hero.largeur = HERO_WIDTH;
hero.hauteur = HERO_HEIGHT;

//Variables n�cessaires au fonctionnement de la gestion des collisions
hero.timerMort = 0;
hero.onGround = 0;
hero.jump = hero.y - JUMPHEIGHT;


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

}



void heroTextureClean()
{
    if (heroTexture!= NULL)
    {
    SDL_DestroyTexture(heroTexture);
    heroTexture = NULL;
    }

}
