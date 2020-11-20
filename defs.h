#ifndef DEFS_H_INCLUDED
#define DEFS_H_INCLUDED

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

// Taille de la fenêtre : 850x500 pixels
#define SCREEN_WIDTH 850
#define SCREEN_HEIGHT 500
#define TILES_WIDTH 64
#define TILES_HEIGHT 30
#define INCREMENT 27
#define MONSTRE 1
#define HERO 2
#define HERO_STARTX 0
#define HERO_STARTY 420
#define SPRITE_STARTX 236
#define SPRITE_STARTY 236
#define HERO_HEIGHT 64
#define HERO_WIDTH 64
#define IDLE 0
#define JUMP 1
#define DEAD 2
#define WALK 3
//Screen WIDTH/PLATEFORM WIDTH = 13
#define NBRE_TILES 13
#define BLOQUE 1
#define TUE 0
#define LIMITE_YMIN 0
#define LIMITE_YMAX 420
#define HERO_SPEED 4
#define INCREMENT 27
#define RIGHT 1
#define LEFT 2
#define JUMPHEIGHT 100





#endif // DEFS_H_INCLUDED
