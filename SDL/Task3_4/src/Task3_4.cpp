/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
 and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include <stdio.h>
#include <string>
#include "globals.h"
#include "start.h"
#include "MouseBtn.h"

using namespace std;


int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		cerr << "Failed to initialize" << endl;
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			cerr << "Failed to load media" << endl;
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while (!quit)
			{
				//is an event
				gIsEvent = true;
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}

					if (e.type == SDL_MOUSEBUTTONDOWN)
					{
						gButton.Move();
					}
				}

				if(gIsEvent)
				{
					clearUpdate();
					gIsEvent = false;
				}
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}
