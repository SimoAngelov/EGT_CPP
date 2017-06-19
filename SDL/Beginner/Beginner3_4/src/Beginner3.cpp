//============================================================================
// Name        : Beginner3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "globals.h"
#include "start.h"

using namespace std;

int main(int argc, char* args[]) {
	//Start up SDL and create window
	if (!init()) {
		cerr << "Failed to initialize!\n";
	} else {
		//Load media
		if (!loadMedia()) {
			cerr << "Failed to load media!\n";
		} else {
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while (!quit) {
				gIsEvent = true;
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0) {
					//User requests quit
					gIsEvent = true;
					if (e.type == SDL_QUIT) {
						quit = true;
					} else {
						gButton.Move(e);
					}
				}

				if (gIsEvent) {
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
