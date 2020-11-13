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
extern void initSpriteTexture();
extern void spriteTextureClean();
extern void initHeroTexture();
extern void heroTextureClean();
extern SDL_Renderer *getrenderer(void);
extern void init(char *);
extern void initMaps(void);
extern void loadGame(void);
extern SDL_Texture *loadImage(char *name);
extern void gestionInputs(Input *);
extern void getInput(Input *);
extern void initHerox(int valeur);
extern void initHeroy(int valeur);
extern void initSpritex(int valeur);
extern void initSpritey(int valeur);



#endif
#endif // PROTOTYPES_H_INCLUDED
