#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED


#ifndef PROTOTYPES
#define PROTOTYPES

#include "struct.h"

/* Catalogue des prototypes des fonctions utilisées.
   On le complétera au fur et à mesure. */
extern void cleanMaps(void);
extern void cleanup(SDL_Texture*);
extern void delay(unsigned int);
extern void drawGame(SDL_Texture*, Sprites*);
extern void drawImage(SDL_Texture *, int, int);
extern void drawMap(int);
extern SDL_Texture *getBackground(void);
extern SDL_Texture *getHeroTexture(void);
extern SDL_Texture *getTiles(void);
extern SDL_Texture *getSpriteTexture(void);
extern void initSpriteTexture(void);
extern void spriteTextureClean(void);
extern SDL_Texture *initHeroTexture(SDL_Texture*);
extern void heroTextureClean(SDL_Texture*);
extern SDL_Renderer *getrenderer(void);
extern void init(char *);
extern void initMaps(void);
extern SDL_Texture *loadGame(SDL_Texture*);
extern SDL_Texture *loadImage(char *name);
extern void gestionInputs(Input *);
extern void getInput(Input *);
extern Sprites* getHero(void);
extern void setHerox(int valeur,Sprites*);
extern void setHeroy(int valeur, Sprites*);
extern int getHerox(Sprites*);
extern int getHeroy(Sprites*);
extern Sprites *initializeHero(Sprites*);
extern void drawHero(SDL_Texture*, Sprites*);
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
extern void drawBackground(void);
extern Sprites *updatePlayer(Input *, Sprites*, Tiles**);
extern int CollisionDroite(Sprites *, Tiles **);
extern int CollisionBas(Sprites *, Tiles**);
extern int CollisionGauche(Sprites *, Tiles ** );




#endif
#endif // PROTOTYPES_H_INCLUDED
