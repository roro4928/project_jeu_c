#include "prototypes.h"


/**
* @brief: Cette fonction initialise et renvoie la texture de notre héro à afficher
*@param:<input> SDL_Texture *heroTexture: Le pointeur vers la texture de notre héro
*       <output> heroTexture: La texture de notre héro
*/


SDL_Texture *initHeroTexture(SDL_Texture *heroTexture)
{
    heroTexture = loadImage("graphics/meatboy.png");
    return heroTexture;

}

/**
* @brief: Cette fonction est un guetteur qui récupère la coordonnée en abcisse du hero
*@param: <input>:Sprites *hero: le pointeur vers notre structure Sprite qui fournit les attributs de notre héro
*         <output> hero->x : renvoie l'abcisse du héro à un instant t
*/


//Renvoie la coordonnée x du héro
int getHerox(Sprites *hero)
{
return hero->x;
}
/**
* @brief: Cette fonction est un guetteur qui récupère la coordonnée en ordonnée du hero
*@param: <input>:Sprites *hero: le pointeur vers notre structure Sprite qui fournit les attributs de notre héro
*         <output> hero->y : renvoie l'abcisse du héro à un instant t
*/

//Renvoie la coordonnée y du héro
int getHeroy(Sprites *hero)
{
return hero->y;
}
/**
* @brief: Cette fonction est un setteur qui change la coordonnée en abcisse du hero
*@param: <input>:Sprites *hero: le pointeur vers notre structure Sprite qui fournit les attributs de notre héro
*        <input>: int valeur : la valeur que l'on veut donner à l'abcisse
*/

//Change la coordonnéee x du héro
void setHerox(int valeur, Sprites *hero)
{
hero->x = valeur;
}
/**
* @brief: Cette fonction est un setteur qui change la coordonnée en ordonné du hero
*@param: <input>:Sprites *hero: le pointeur vers notre structure Sprite qui fournit les attributs de notre héro
*        <input>: int valeur : la valeur que l'on veut donner à l'ordonné
*/
//Change la coordonnéee y du héro
void setHeroy(int valeur, Sprites *hero)
{
hero->y = valeur;
}

/**
* @brief: Cette fonction est un setteur qui initalise les attributs de notre hero
*@param: <input>Sprites *hero: le pointeur vers notre structure Sprite qui fournit les attributs de notre héro
*       <output>Sprites *hero: le pointeur vers notre structure Sprite qui fournit les attributs de notre héro
*/
Sprites *initializeHero(Sprites *hero)
{

    hero->x = getBeginX();
    hero->y = getBeginY();

    /* Hauteur et largeur de notre héros */
    hero->largeur = HERO_WIDTH;
    hero->hauteur = HERO_HEIGHT;

    return hero;
}


/**
* @brief: Cette fonction modifie les coordonnées du joueur lors qu'il avance, recule, saute ou tombe.
*@param: <intput>: Input *input: pointeur sur les commandes du jeu du type Input
*        <input>Sprites *hero: le pointeur vers notre structure Sprite qui fournit les attributs de notre héro
*        <intput>: Tiles **tiles: tableau de pointeur
*        <output>Sprites *: le pointeur vers notre structure Sprite qui fournit les attributs de notre héro
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
*@param: <input>Sprites *player: le pointeur vers notre structure Sprite qui fournit les attributs de notre héro
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
*@param: <input>Sprites *player: le pointeur vers notre structure Sprite qui fournit les attributs de notre héro
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
*@param: <input>Sprites *player: le pointeur vers notre structure Sprite qui fournit les attributs de notre héro
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

