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

//Renvoie la coordonnée x du héro
int getHerox(void)
{
return hero.x;
}
//Renvoie la coordonnée y du héro
int getHeroy(void)
{
return hero.y;
}
//Change la coordonnéee x du héro
void setHerox(int valeur)
{
hero.x = valeur;
}

//Change la coordonnéee y du héro
void setHeroy(int valeur)
{
hero.y = valeur;
}


void initializeHero(void)
{

//PV à 3
hero.life = 3;

//Timer d'invincibilité à 0
hero.invincibleTimer = 0;

//Indique l'état et la direction de notre héros
hero.etat = IDLE;

hero.x = getBeginX();
hero.y = getBeginY();

/* Hauteur et largeur de notre héros */
hero.largeur = HERO_WIDTH;
hero.hauteur = HERO_HEIGHT;

//Variables nécessaires au fonctionnement de la gestion des collisions
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
