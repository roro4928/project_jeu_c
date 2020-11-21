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

//Renvoie la coordonn�e x du h�ro
int getHerox(Sprites *hero)
{
return hero->x;
}
//Renvoie la coordonn�e y du h�ro
int getHeroy(Sprites *hero)
{
return hero->y;
}
//Change la coordonn�ee x du h�ro
void setHerox(int valeur, Sprites *hero)
{
hero->x = valeur;
}

//Change la coordonn�ee y du h�ro
void setHeroy(int valeur, Sprites *hero)
{
hero->y = valeur;
}


Sprites *initializeHero(Sprites *hero)
{

//PV � 3
hero->life = 3;

//Timer d'invincibilit� � 0
hero->invincibleTimer = 0;

//Indique l'�tat et la direction de notre h�ros
hero->etat = IDLE;

hero->x = getBeginX();
hero->y = getBeginY();

/* Hauteur et largeur de notre h�ros */
hero->largeur = HERO_WIDTH;
hero->hauteur = HERO_HEIGHT;

//Variables n�cessaires au fonctionnement de la gestion des collisions
hero->timerMort = 0;
hero->onGround = 0;
hero->jump = hero->y - JUMPHEIGHT;

    return hero;
}

Sprites *updatePlayer(Input *input, Sprites *hero)
{
    if ((input->left == 1) )
    {
        hero->x -= HERO_SPEED;
    }

    if (input->right == 1)
    {
        hero->x += HERO_SPEED;
    }

    if (input->jump == 1)
    {

        if (hero->y != hero->jump)
        {
            if(hero->y<=LIMITE_YMIN)
            {

            }
            else{

                hero->y -= 5;
            }

        }
        else
        {
            gravity(hero);
            input->jump = 0;
        }

    }
    return hero;
}

void gravity(Sprites *hero)
{
    if(hero->y>=LIMITE_YMAX){}
    else{
        while(hero->y!=HERO_STARTY)
            {
                delay(SDL_GetTicks());
             hero->y+=5;

            }

    }

}



void heroTextureClean(SDL_Texture *heroTexture)
{
    if (heroTexture!= NULL)
    {
    SDL_DestroyTexture(heroTexture);
    heroTexture = NULL;
    }

}

/*int CollisionDroite(Sprites *player, Tiles** tabBox)
{
    for(int i=0;i< NBRE_TILES ;i++)
    {
        if( (player->x + player->largeur >= tabBox[i]->x)
           &&(player->x + player->largeur <= tabBox[i]->x +(tabBox[i]->largeur)/2)
           &&(player->y + player->hauteur <= tabBox[i]->y)
           &&(player->y >= tabBox[i]->y + tabBox[i]->hauteur)
           )
        {
            return 1;
        }
    }
    return 0;
}*/

/*int CollisionGauche(Sprites *player, Tiles** tabBox)
{
    for(int i=0;i< NBRE_TILES ;i++)
    {
        if(tabBox[i]->x + tabBox[i]->largeur <= player->x)
        {
            return 0;
        }
    }
    return 1;
}

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
}

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
