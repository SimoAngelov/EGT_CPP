//============================================================================
// Name        : 7_TextureRendering.cpp
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

//start up SDL and create a window;
bool init();

//load the images
bool loadMedia();

//frees media and shuts down SDL
void close();

//loads individual texture
SDL_Texture* loadTexture(const string& path);

//the window we'll be rendering to
SDL_Window* gWindow = NULL;

//current displayed texture
SDL_Texture* gTexture = NULL;

//the window renderer
SDL_Renderer* gRenderer = NULL;

bool init() {
	bool flag = true;
	//initialize sdl
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cerr << "SDL FAILED TO LOAD. " << SDL_GetError() << endl;
		flag = false;
	} else {
		// set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			cerr << "Warning! Linear texture filtering not enabled" << endl;
		} else {
			//create window
			gWindow = SDL_CreateWindow("Task 3", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
					SDL_WINDOW_SHOWN);
			if (gWindow == NULL) {
				cout << "Window could not be created. Error: " << SDL_GetError()
						<< endl;
				flag = false;
			} else {
				//create renderer
				gRenderer = SDL_CreateRenderer(gWindow, -1,
						SDL_RENDERER_ACCELERATED);
				if (!gRenderer) {
					cerr << "Renderer could not be created! " << SDL_GetError()
							<< endl;
					flag = false;
				} else {
					//Initialize renderer color
					SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

					//Initialize PNG loading
					int imgFlags = IMG_INIT_PNG;
					if (!(IMG_Init(imgFlags) & imgFlags)) {
						cerr
								<< "SDL_image could not initialize! SDL_image Error:\n"
								<<
								IMG_GetError() << endl;
						flag = false;
					}
				}
			}
		}
	}
	return flag;
}

bool loadMedia() {
	bool success = true;
	gTexture = loadTexture(
			"C:\\Users\\SimoAngelov\\Pictures\\SDL_Pictures\\ex2.png");
	if (!gTexture) {
		cerr << "failed to load texture image" << endl;
		success = false;
	}
	return success;
}

void close() {
	//Free loaded image
	SDL_DestroyTexture(gTexture);
	gTexture = NULL;

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* loadTexture(const string& path) {
	//the final texture
	SDL_Texture* newTexture = NULL;

	//load the image at the specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (!loadedSurface) {
		cerr << "Unable to load image " << path.c_str() << "\nSDL Error "
				<< IMG_GetError() << endl;
	} else {
		//create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (!newTexture) {
			cerr << "Unable to create texture from " << path.c_str()
					<< "SDL_Error\n" << SDL_GetError() << endl;
		}
		//get rid of the old surface
		SDL_FreeSurface(loadedSurface);

	}
	return newTexture;
}
int main(int argc, char** argv) {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	if (!init()) {
		cerr << "Failed to initialize" << endl;

	} else {
		if (!loadMedia()) {
			cerr << "Failed to load media" << endl;
		} else {
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while (!quit) {
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0) {
					//User requests quit
					if (e.type == SDL_QUIT) {
						quit = true;
					}
				}

				//Clear screen
				SDL_RenderClear(gRenderer);

				//Render texture to screen
				SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

				//Update screen
				SDL_RenderPresent(gRenderer);
			}
		}
	}

	close();
	return 0;
}
