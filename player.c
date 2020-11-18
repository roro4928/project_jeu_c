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

}

void drawHero(void)
{


/* Rectangle de destination à dessiner */
SDL_Rect dest;

// On soustrait des coordonnées de notre héros, ceux du début de la map, pour qu'il colle
//au scrolling :
dest.x = hero.x - getStartX();
dest.y = hero.y - getStartY();
dest.w = hero.largeur;
dest.h = hero.hauteur;

}

void heroTextureClean()
{
    if (heroTexture!= NULL)
    {
    SDL_DestroyTexture(heroTexture);
    heroTexture = NULL;
    }

}
