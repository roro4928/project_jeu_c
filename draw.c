#include "prototypes.h"

/**
* @brief: Cette fonction dessine toutes les millisecondes le background,
*         les plateformes et le personnage
*@param:
*       <input>: SDL_Texture *heroTexture: pointeur sur un type SDL_Texture vers la texture du personnage
*       <input>: Sprites *hero: pointeur sur le hero de type Sprites
*/
void drawGame(SDL_Texture *heroTexture, Sprites *hero)
{

    // Affiche le fond (background) aux coordonnées (0,0)
    drawBackground();
    initPlateforme();
    drawHero(heroTexture, hero);
    // Affiche l'écran
    SDL_RenderPresent(getrenderer());


    // Délai pour laisser respirer le proc
    SDL_Delay(1);

}

/**
* @brief: Cette fonction dessine le background en appelant la fonction drawImage()
*
*/
void drawBackground(void)
{
        drawImage(getBackground(), 0, 0);

}

/**
* @brief: Cette fonction dessine le hero en appelant la fonction drawHero()
*@param:
*       <input>: SDL_Texture *heroTexture: pointeur sur un type SDL_Texture vers la texture du personnage
        <input>: Sprites *hero: pointeur sur le hero de type Sprites
*/
void drawHero(SDL_Texture *heroTexture, Sprites *hero)
{
        drawImage(heroTexture, getHerox(hero), getHeroy(hero));

}

/**
* @brief: Cette fonction dessine les plateformes en fonction de leurs coordonnées x, y
*
*/
void initPlateforme(void)
{
  Tiles **ptrTabTiles = initTiles();
  for (int i=0; i<NBRE_TILES;i++)
  {
      drawImage(getTiles(),getTileX(ptrTabTiles, i),getTileY(ptrTabTiles, i));
  }

}

/**
* @brief: Cette fonction charge les images avec SDL Image avec une gestion d'erreur
*@param:
*       <input>: char *name: chemin+nom du fichier image à charger
*       <output>: texture: pointeur vers la texture de l'image
*/
SDL_Texture *loadImage(char *name)
{

    /* Charge les images avec SDL Image dans une SDL_Surface */

    SDL_Surface *loadedImage = NULL;
    SDL_Texture *texture = NULL;
    loadedImage = IMG_Load(name);

    if (loadedImage != NULL)
    {
    // Conversion de l'image en texture
    texture = SDL_CreateTextureFromSurface(getrenderer(), loadedImage);

    // On se débarrasse du pointeur vers une surface
    SDL_FreeSurface(loadedImage);
    loadedImage = NULL;
    }
    else
    printf("L'image n'a pas pu être chargée! SDL_Error : %s\n", SDL_GetError());

    return texture;

}

/**
* @brief: Cette fonction permet de dessiner l'image rentrée en paramètre
*@param:
*       <input>: SDL_Texture *image: pointeur sur un type SDL_Texture vers la texture de l'image
*       <input>: int x: coordonnée en abscisse de l'image
*       <input>: int y: coordonnée en ordonnée de l'image
*/
void drawImage(SDL_Texture *image, int x, int y)
{

    SDL_Rect dest;

    /* Règle le rectangle à dessiner selon la taille de l'image source */
    dest.x = x;
    dest.y = y;

    /* Dessine l'image entière sur l'écran aux coordonnées x et y */
    SDL_QueryTexture(image, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(getrenderer(), image, NULL, &dest);

}

/**
* @brief: Cette fonction est une fonction d'attente qui permet d'avoir 60 fps
*@param:
*       <input>: unsigned int frameLimit:temps écoulé depuis le dernier affichage
*/
void delay(unsigned int frameLimit)
{
    // Gestion des 60 fps (images/seconde)
    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return;
    }

    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }

    else
    {
        SDL_Delay(frameLimit - ticks);
    }
}
