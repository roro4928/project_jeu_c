#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED


#ifndef PROTOTYPES
#define PROTOTYPES

#include "struct.h"

/* Catalogue des prototypes des fonctions utilisées.
   On le complétera au fur et à mesure. */
extern void cleanMaps(void);
extern void cleanup(void);
extern void delay(unsigned int frameLimit);
extern void drawGame(void);
extern void drawImage(SDL_Texture *, int, int);
extern void drawMap(int);
extern SDL_Texture *getBackground(void);
extern SDL_Texture *getHeroTexture(void);
extern SDL_Texture *getTiles(void);
extern SDL_Texture *getSpriteTexture(void);
extern void initSpriteTexture(void);
extern void spriteTextureClean(void);
extern void initHeroTexture(void);
extern void heroTextureClean(void);
extern SDL_Renderer *getrenderer(void);
extern void init(char *);
extern void initMaps(void);
extern void loadGame(void);
extern SDL_Texture *loadImage(char *name);
extern void gestionInputs(Input *);
extern void getInput(Input *);
extern void setHerox(int valeur);
extern void setHeroy(int valeur);
extern int getHerox(void);
extern int getHeroy(void);
extern void initializeHero(void);
extern void drawHero(void);
extern int initSpritex(void);
extern int initSpritey(void);
extern int getBeginX(void);
extern int getBeginY(void);
extern int getStartX(void);
extern int getStartY(void);
extern void setStartX(int valeur);
extern void setStartY(int valeur);
extern Tiles** initTiles(void);
extern int getTileX(Tiles **tiles, int);
extern int getTileY(Tiles **tiles, int);
extern  void initPlateforme(void);




#endif
#endif // PROTOTYPES_H_INCLUDED
