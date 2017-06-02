//============================================================================
// Name        : Task1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

//the window we will be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

int main(int argv, char** argc) {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	//Initialize the windwo
	if (SDL_INIT_VIDEO < 0) {
		cerr << "Could not initialize sdl window: " << SDL_GetError() << endl;
		return false;
	}
	//Create a window
	gWindow = SDL_CreateWindow("Task 1", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (gWindow == NULL) {
		cerr << "Window could not be created: " << SDL_GetError();
		return false;
	}

	bool quit = false;
	SDL_Event e;

	int clickCounter = 0;

	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			} else if (e.type == SDL_MOUSEBUTTONDOWN && !quit) {
				++clickCounter;
				//get the mouse position;
				int iX, iY;
				SDL_GetMouseState(&iX, &iY);
				cout << "Click No" << clickCounter
						<< ". Mouse is now at coordinates (" << iX << ", " << iY
						<< ")\n";

			}
		} // end the event queue
	}

	cout << "The mouse was clicked a total of " << clickCounter << " times";

	//Delete surface
	SDL_FreeSurface (gScreenSurface);
	gScreenSurface = NULL;
	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();

	return 0;
}
