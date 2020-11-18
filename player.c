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

}

void drawHero(void)
{


/* Rectangle de destination � dessiner */
SDL_Rect dest;

// On soustrait des coordonn�es de notre h�ros, ceux du d�but de la map, pour qu'il colle
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
