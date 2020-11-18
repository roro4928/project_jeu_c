#include "prototypes.h"


void gestionInputs(Input *input)
{
	//On gère le clavier
	getInput(input);
}


void getInput(Input *input)
{
	SDL_Event event;

	/* Keymapping : gère les appuis sur les touches et les enregistre
	dans la structure input */

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{

			case SDL_QUIT:
				exit(0);
			break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						exit(0);
					break;

					default:
					break;
				}
			break;



		}

	}
}


