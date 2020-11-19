#include "prototypes.h"


void drawGame(void)
{

    // Affiche le fond (background) aux coordonn�es (0,0)
    //drawImage(getSpriteTexture(), SPRITE_STARTX,SPRITE_STARTY);
    drawBackground();
    initPlateforme();
    drawHero();

    // Affiche l'�cran
    SDL_RenderPresent(getrenderer());


    // D�lai pour laisser respirer le proc
    SDL_Delay(1);

}

void drawBackground(void)
{
        drawImage(getBackground(), 0, 0);

}

void drawHero(void)
{
        drawImage(getHeroTexture(), getHerox(), getHeroy());

}

void initPlateforme(void)
{
  Tiles **ptrTabTiles = initTiles();
  for (int i=0; i<NBRE_TILES;i++)
  {
      drawImage(getTiles(),getTileX(ptrTabTiles, i),getTileY(ptrTabTiles, i));
  }

}

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

// On se d�barrasse du pointeur vers une surface
SDL_FreeSurface(loadedImage);
loadedImage = NULL;
}
else
printf("L'image n'a pas pu �tre charg�e! SDL_Error : %s\n", SDL_GetError());

return texture;

}


void drawImage(SDL_Texture *image, int x, int y)
{

SDL_Rect dest;

/* R�gle le rectangle � dessiner selon la taille de l'image source */
dest.x = x;
dest.y = y;

/* Dessine l'image enti�re sur l'�cran aux coordonn�es x et y */
SDL_QueryTexture(image, NULL, NULL, &dest.w, &dest.h);
SDL_RenderCopy(getrenderer(), image, NULL, &dest);

}




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
