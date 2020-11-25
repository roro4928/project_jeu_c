#include "prototypes.h"


/* Déclaration des variables / structures utilisées par le jeu */
Input input;


int main(int argc, char *argv[])
{
    SDL_Texture *heroTexture=NULL;
    Sprites Shero;
    Sprites *hero=&Shero;
    unsigned int frameLimit = SDL_GetTicks() + 16;
    int go;

    // Initialisation de la SDL
    init("Jeu des BOSS");
    // Chargement des ressources (graphismes, sons)
    heroTexture=loadGame(heroTexture);

    // on initialise les plateforme sur la map
    hero=initializeHero(hero);//on initialise le hero
    Tiles **tiles = initTiles();

    Mix_Music *musique;
    son(musique);

    // Appelle la fonction cleanup à la fin du programme
    atexit((cleanup));

    go = 1;
    // Boucle infinie, principale, du jeu
    while (go == 1)
    {

        //On dessine tout

        drawGame(heroTexture,hero);
        gestionInputs(&input);
        hero=updatePlayer(&input, hero,tiles);





        // Gestion des 60 fps (1000ms/60 = 16.6 -> 16
        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 16;

        }

    // On quitte
    exit(0);

}
