/*
 * globals.h
 *
 *  Created on: Jun 8, 2017
 *      Author: Katya
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include "MouseBtn.h"
#include <iostream>
using std::cerr;
using std::endl;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The window we'll be rendering to
SDL_Window* gWindow;

//The window renderer
SDL_Renderer* gRenderer;

//Buttons object
MouseBtn gButton;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();


bool init() {
	//Initialization flag
	bool success = true;
	//Initialize SDL
	if (SDL_Init( SDL_INIT_VIDEO) < 0) {
		cerr << "SDL could not initialize! SDL Error: " <<
				SDL_GetError() << endl;
		success = false;
	} else {
		//Set texture filtering to linear
		if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			cerr << "Warning: Linear texture filtering not enabled!" << endl;;
		}

		//Create window
		gWindow = SDL_CreateWindow("3rdTime is the charm", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			cerr << "Window could not be created! SDL Error:" <<
					SDL_GetError() << endl;
			success = false;
		} else {
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL) {
				cerr << "Renderer could not be created! SDL Error: " <<
						SDL_GetError() << endl;
				success = false;
			} else {
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {
					cerr <<
							"SDL_image could not initialize! SDL_image Error: " <<
							IMG_GetError() << endl;
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia() {
	//Loading success flag
	bool success = true;

	//Load sprite

	if (!gButton.loadFromFile(gRenderer, "foo.png")) {
		cerr << "Failed to load button sprite texture!" << endl;
		success = false;
	} else {
		//Set sprites
		gButton.setPosition(0, 0);
		gButton.setWidth(200);
		gButton.setHeight(200);
	}

	return success;
}

void close() {
	//Free loaded images

	gButton.free();

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}





#endif /* GLOBALS_H_ */
