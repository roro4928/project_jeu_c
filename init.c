#include "prototypes.h"

//Variables globales pour l'affichache de l'ecran
SDL_Window *screen;
SDL_Renderer *renderer;


/**
* @brief: Cette fonction permet de recuperer un pointeur sur le rendu renderer de type SDL_Renderer
*@param:
*       <output>: SDL_Renderer *getrenderer: pointeur sur le rendu renderer de type SDL_Renderer
*
*/
SDL_Renderer *getrenderer(void)
{
    return renderer;
}

/**
* @brief: On cr�e la fen�tre en utilisant la largeur et la hauteur d�finies dans les defines (defs.h).
*@param:
*       <intput>: char *title: titre de la fenetre
*/
void init(char *title)
{
    screen = SDL_CreateWindow(title,
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  SCREEN_WIDTH, SCREEN_HEIGHT,
                                  SDL_WINDOW_SHOWN);

    //On cr�e un renderer pour la SDL et on active la synchro verticale : VSYNC
    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_PRESENTVSYNC);

    // Si on n'y arrive pas, on quitte
    if (screen == NULL || renderer == NULL)
    {
        printf("Impossible d'initialiser le mode �cran � %d x %d: %s\n", SCREEN_WIDTH,
                                                                    SCREEN_HEIGHT, SDL_GetError());
        exit(1);
    }

    //Initialisation du chargement des images png avec SDL_Image 2
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image n'a pu �tre initialis�e! SDL_image Error: %s\n", IMG_GetError() );
        exit(1);
    }

    //On cache le curseur de la souris
    SDL_ShowCursor(SDL_DISABLE);

    //On initialise SDL_TTF 2 qui g�rera l'�criture de texte
    if (TTF_Init() < 0)
    {
        printf("Impossible d'initialiser SDL TTF: %s\n", TTF_GetError());
        exit(1);
    }

    //On initialise SDL_Mixer 2, qui g�rera la musique et les effets sonores
    int flags = MIX_INIT_MP3;
    int initted = Mix_Init(flags);
    if ((initted & flags) != flags)
    {
        printf("Mix_Init: Failed to init SDL_Mixer\n");
        printf("Mix_Init: %s\n", Mix_GetError());
        exit(1);
    }

    /* Open 44.1KHz, signed 16bit, system byte order,
    stereo audio, using 1024 byte chunks (voir la doc pour plus d'infos) */
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
        printf("Mix_OpenAudio: %s\n", Mix_GetError());
        exit(1);
    }

    // D�finit le nombre de pistes audio (channels) � mixer
    Mix_AllocateChannels(32);

}

/**
* @brief: Cette fonction permet de charger une musique et de la jouer en boucle
*
*/
void son(Mix_Music *musique)
{
    musique = Mix_LoadMUS("Music/Hello.mp3");
    Mix_PlayMusic(musique, -1);
}

/**
* @brief:Cette fonction charge le jeu en appelant les fonctions pour charger la map, le hero
*        et les plateformes.
*@param:
*       <intput>: SDL_Texture *heroTexture: pointeur sur un type SDL_Texture vers la texture du personnage
*       <output>: SDL_Texture *: pointeur sur un type SDL_Texture vers la texture du personnage
*/
SDL_Texture *loadGame(SDL_Texture *heroTexture)
{
//On charge les donn�es pour la map

    initMaps();
    heroTexture=initHeroTexture(heroTexture);
    return heroTexture;
}

/**
* @brief: Cette fonction decharge la memoire et remets les pointer a NULL
*@param:
*       <intput>: SDL_Texture *heroTexture: pointeur sur un type SDL_Texture vers la texture du personnage
*       <intput>: Mix_Music *musique: pointeur sur un type Mix_Music vers la musique du jeu
*/
void cleanup(SDL_Texture *heroTexture, Mix_Music *musique)
{
    //Nettoie les sprites de la map
    cleanMaps();
    heroTextureClean(heroTexture);
    //On quitte SDL_Mixer 2 et on d�charge la m�moire
    Mix_FreeMusic(musique);
    Mix_CloseAudio();
    Mix_Quit();

    //On fait le m�nage et on remet les pointeurs � NULL
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(screen);
    screen = NULL;

    //On quitte SDL_TTF 2
    TTF_Quit();

    //On quitte la SDL
    SDL_Quit();
}
