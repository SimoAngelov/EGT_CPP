/*
 * start.cpp
 *
 *  Created on: Jun 19, 2017
 *      Author: SimoAngelov
 */

#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include <stdio.h>
#include <string>
#include "MouseBtn.h"
#include "globals.h"

using namespace std;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Buttons object
MouseBtn gButton;

//flag to check if an event is happening
bool gIsEvent = true;

bool init() {
	//Initialization flag
	bool success = true;
	//Initialize SDL
	if (SDL_Init( SDL_INIT_VIDEO) < 0) {
		cerr << "SDL could not initialize! SDL Error: " << SDL_GetError()
				<< endl;
		success = false;
	} else {
		//Set texture filtering to linear
		if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			cerr << "Warning: Linear texture filtering not enabled!" << endl;
			;
		}

		//Create window
		gWindow = SDL_CreateWindow("Random Rectangle", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			cerr << "Window could not be created! SDL Error:" << SDL_GetError()
					<< endl;
			success = false;
		} else {
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL) {
				cerr << "Renderer could not be created! SDL Error: "
						<< SDL_GetError() << endl;
				success = false;
			} else {
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {
					cerr << "SDL_image could not initialize! SDL_image Error: "
							<<
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
	success = gButton.loadBtn("foo.png", gRenderer);
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

void clearUpdate() {
	//Clear screen
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);

	//Render buttons

	gButton.draw(gRenderer, 0, SDL_FLIP_NONE);

	//Update screen
	SDL_RenderPresent(gRenderer);
}

bool CheckCollision(SDL_Rect& a, SDL_Rect& b) {
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;
	//Calculate the sides of rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;
	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	//If any of the sides from A are outside of B
	if (bottomA <= topB) {
		return false;
	}
	if (topA >= bottomB) {
		return false;
	}
	if (rightA <= leftB) {
		return false;
	}
	if (leftA >= rightB) {
		return false;
	} //If none of the sides from A are outside B
	return true;
}

