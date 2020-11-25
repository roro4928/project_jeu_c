#include "prototypes.h"




Sprites *getHero(void)
{
    Sprites *hero;
    return hero;
}

SDL_Texture *initHeroTexture(SDL_Texture *heroTexture)
{
    heroTexture = loadImage("graphics/meatboy.png");
    return heroTexture;

}


SDL_Texture *getHeroTexture(void)
{
    SDL_Texture *heroTexture = NULL;
    return heroTexture;
}

//Renvoie la coordonnée x du héro
int getHerox(Sprites *hero)
{
return hero->x;
}
//Renvoie la coordonnée y du héro
int getHeroy(Sprites *hero)
{
return hero->y;
}
//Change la coordonnéee x du héro
void setHerox(int valeur, Sprites *hero)
{
hero->x = valeur;
}

//Change la coordonnéee y du héro
void setHeroy(int valeur, Sprites *hero)
{
hero->y = valeur;
}


Sprites *initializeHero(Sprites *hero)
{

    //PV à 3
    hero->life = 3;

    //Timer d'invincibilité à 0
    hero->invincibleTimer = 0;

    //Indique l'état et la direction de notre héros
    hero->etat = IDLE;

    hero->x = getBeginX();
    hero->y = getBeginY();

    /* Hauteur et largeur de notre héros */
    hero->largeur = HERO_WIDTH;
    hero->hauteur = HERO_HEIGHT;

    //Variables nécessaires au fonctionnement de la gestion des collisions
    hero->timerMort = 0;
    hero->onGround = 0;
    hero->jump = hero->y - JUMPHEIGHT;

    return hero;
}

Sprites *updatePlayer(Input *input, Sprites *hero, Tiles **tiles)
{
    static int nb = 0;
    if (input->left == 1 && !(CollisionGauche(hero, tiles)))
    {
        hero->x -= HERO_SPEED;
    }

    if ((input->right == 1) && !(CollisionDroite(hero, tiles)))
    {
        hero->x += HERO_SPEED;
    }

    if(CollisionBas(hero, tiles))
    {

    }

    if (input->jump == 1 && (CollisionBas(hero, tiles) || nb!=0 ||(hero->y + hero->hauteur >= LIMITE_YMAX + hero->hauteur)))
    {

        if (nb!=25)
        {
            nb ++;
            hero->y -=4;
        }

        else
        {
            nb=0;
            input->jump = 0;
        }

    }
    if (!CollisionBas(hero, tiles) && (hero->y + hero->hauteur <= LIMITE_YMAX + hero->hauteur) && (nb == 0))
    {
        hero->y += 5;
    }

    return hero;
}



void heroTextureClean(SDL_Texture *heroTexture)
{
    if (heroTexture!= NULL)
    {
    SDL_DestroyTexture(heroTexture);
    heroTexture = NULL;
    }

}

int CollisionDroite(Sprites *player, Tiles** tabBox)
{
    for(int i=0;i< NBRE_TILES ;i++)
    {

        if( (player->x + player->largeur >= tabBox[i]->x)
           &&(player->x + player->largeur <= tabBox[i]->x +tabBox[i]->largeur/2)
           &&(player->y + player->hauteur  - 10 > tabBox[i]->y)
           &&(player->y < tabBox[i]->y + tabBox[i]->hauteur)
           )
        {
            return 1;
        }
    }
    return 0;
}

int CollisionGauche(Sprites *player, Tiles** tabBox)
{
    for(int i=0;i< NBRE_TILES ;i++)
    {
        if((player->x <= tabBox[i]->x + tabBox[i]->largeur)
           &&(player->x >= tabBox[i]->x +tabBox[i]->largeur/2)
           &&(player->y + player->hauteur  - 10 > tabBox[i]->y)
           &&(player->y < tabBox[i]->y + tabBox[i]->hauteur))
        {
            return 1;
        }
    }
    return 0;
}

int CollisionBas(Sprites *player, Tiles** tabBox)
{
    for(int i=0;i< NBRE_TILES ;i++)
    {
        if( (player->x + player->largeur >= tabBox[i]->x)
           && (player->x + player->largeur <= tabBox[i]->x +tabBox[i]->largeur)
           && (player->y + player->largeur >= tabBox[i]->y )
           && (player->y + player->largeur <= tabBox[i]->y + tabBox[i]->hauteur/2))
        {
            return 1;
        }
    }
    return 0;
}
/*
int CollisionHaut(Sprites *player, Tiles** tabBox)
{
    for(int i=0;i< NBRE_TILES ;i++)
    {
        if(tabBox->y + tabBox->hauteur <= player->y)
        {
            return 0;
        }
    }
    return 1;
}*/
