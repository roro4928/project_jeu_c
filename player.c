#include "prototypes.h"


/**
* @brief: Cette fonction initialise et renvoie la texture de notre h�ro � afficher
*@param:<input> SDL_Texture *heroTexture: Le pointeur vers la texture de notre h�ro
*       <output> heroTexture: La texture de notre h�ro
*/


SDL_Texture *initHeroTexture(SDL_Texture *heroTexture)
{
    heroTexture = loadImage("graphics/meatboy.png");
    return heroTexture;

}

/**
* @brief: Cette fonction est un guetteur qui r�cup�re la coordonn�e en abcisse du hero
*@param: <input>:Sprites *hero: le pointeur vers notre structure Sprite qui fournit les attributs de notre h�ro
*         <output> hero->x : renvoie l'abcisse du h�ro � un instant t
*/


//Renvoie la coordonn�e x du h�ro
int getHerox(Sprites *hero)
{
return hero->x;
}
/**
* @brief: Cette fonction est un guetteur qui r�cup�re la coordonn�e en ordonn�e du hero
*@param: <input>:Sprites *hero: le pointeur vers notre structure Sprite qui fournit les attributs de notre h�ro
*         <output> hero->y : renvoie l'abcisse du h�ro � un instant t
*/

//Renvoie la coordonn�e y du h�ro
int getHeroy(Sprites *hero)
{
return hero->y;
}
/**
* @brief: Cette fonction est un setteur qui change la coordonn�e en abcisse du hero
*@param: <input>:Sprites *hero: le pointeur vers notre structure Sprite qui fournit les attributs de notre h�ro
*        <input>: int valeur : la valeur que l'on veut donner � l'abcisse
*/

//Change la coordonn�ee x du h�ro
void setHerox(int valeur, Sprites *hero)
{
hero->x = valeur;
}
/**
* @brief: Cette fonction est un setteur qui change la coordonn�e en ordonn� du hero
*@param: <input>:Sprites *hero: le pointeur vers notre structure Sprite qui fournit les attributs de notre h�ro
*        <input>: int valeur : la valeur que l'on veut donner � l'ordonn�
*/
//Change la coordonn�ee y du h�ro
void setHeroy(int valeur, Sprites *hero)
{
hero->y = valeur;
}

/**
* @brief: Cette fonction est un setteur qui initalise les attributs de notre hero
*@param: <input>Sprites *hero: le pointeur vers notre structure Sprite qui fournit les attributs de notre h�ro
*       <output>Sprites *hero: le pointeur vers notre structure Sprite qui fournit les attributs de notre h�ro
*/
Sprites *initializeHero(Sprites *hero)
{

    hero->x = getBeginX();
    hero->y = getBeginY();

    /* Hauteur et largeur de notre h�ros */
    hero->largeur = HERO_WIDTH;
    hero->hauteur = HERO_HEIGHT;

    return hero;
}


/**
* @brief: Cette fonction modifie les coordonn�es du joueur lors qu'il avance, recule, saute ou tombe.
*@param: <intput>: Input *input: pointeur sur les commandes du jeu du type Input
*        <input>Sprites *hero: le pointeur vers notre structure Sprite qui fournit les attributs de notre h�ro
*        <intput>: Tiles **tiles: tableau de pointeur
*        <output>Sprites *: le pointeur vers notre structure Sprite qui fournit les attributs de notre h�ro
*/
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

    if (input->jump == 1 && (CollisionBas(hero, tiles) || nb!=0 ||(hero->y + hero->hauteur >= LIMITE_YMAX + hero->hauteur)))
    {

        if (nb!= JUMPHEIGHT)
        {
            nb ++;
            hero->y -=HERO_SPEED;
        }

        else
        {
            nb=0;
            input->jump = 0;
        }

    }
    if (!CollisionBas(hero, tiles) && (hero->y + hero->hauteur <= LIMITE_YMAX + hero->hauteur) && (nb == 0))
    {
        hero->y += GRAVITYSPEED;
    }

    return hero;
}


/**
* @brief: Cette fonction libere la memoire de la texture du joueur.
*@param: <intput>: Input *input: pointeur sur les commandes du jeu du type Input
*        <output>: SDL_Texture *heroTexture: pointeur sur un type SDL_Texture vers la texture du personnage
*/
void heroTextureClean(SDL_Texture *heroTexture)
{
    if (heroTexture!= NULL)
    {
    SDL_DestroyTexture(heroTexture);
    heroTexture = NULL;
    }

}

/**
* @brief: Cette fonction renvoie s'il y a une colision entre la doite du joueur et une des plateforme.
*@param: <input>Sprites *player: le pointeur vers notre structure Sprite qui fournit les attributs de notre h�ro
*        <intput>: Tiles **tiles: tableau de pointeur
*        <output>: int:0 pas de collision, 1 collision
*/
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

/**
* @brief: Cette fonction renvoie s'il y a une colision entre la gauche du joueur et une des plateforme.
*@param: <input>Sprites *player: le pointeur vers notre structure Sprite qui fournit les attributs de notre h�ro
*        <intput>: Tiles **tiles: tableau de pointeur
*        <output>: int:0 pas de collision, 1 collision
*/
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

/**
* @brief: Cette fonction renvoie s'il y a une colision entre le bas du joueur et une des plateforme.
*@param: <input>Sprites *player: le pointeur vers notre structure Sprite qui fournit les attributs de notre h�ro
*        <intput>: Tiles **tiles: tableau de pointeur
*        <output>: int:0 pas de collision, 1 collision
*/
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

