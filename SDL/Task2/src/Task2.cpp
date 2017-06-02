//============================================================================
// Name        : Task2.cpp
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
//C:\Users\SimoAngelov\Pictures\SDL_Pictures

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image
SDL_Surface* loadSurface( string path );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//Current displayed image
SDL_Surface* gPNGSurface = NULL;

bool init(){
	bool success = true;
	 if(SDL_Init(SDL_INIT_VIDEO) < 0)
	 {
		 cout << "SDL could not initialize. SDL ERROR: " << SDL_GetError() << endl;
		 success = false;
	 }	else {
		 gWindow = SDL_CreateWindow("Task 2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		 if(gWindow == NULL)
		 {
			 cout << "Window could not be created. Error: " << SDL_GetError() << endl;
			 success = false;
		 } else {
			 //initialize png
			 int imgFlags = IMG_INIT_PNG;
			 if(!(IMG_Init(imgFlags) & imgFlags))
			 {
				 cout << "SDL_image could not initialize! Error: " << SDL_GetError() << endl;
				 success = false;
			 }	else {
			 gScreenSurface = SDL_GetWindowSurface(gWindow);
			 }
		 }
	 }
	 return success;
}

bool loadMedia()
{
	bool success = true;
	gPNGSurface = loadSurface("C:\\Users\\SimoAngelov\\Pictures\\SDL_Pictures\\ex2.png");
	//gPNGSurface = loadSurface("ex2.png");
	//gPNGSurface = IMG_Load("ex2.png");
	if(gPNGSurface == NULL){
		cerr << "Failed to load png img" << endl;
		success = false;
	}
	return success;
}


void close(){
	//free loaded image
	SDL_FreeSurface(gPNGSurface);
	gPNGSurface = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();

}

SDL_Surface* loadSurface(string path)
{
	//final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if(loadedSurface == NULL)
	{
		cerr << "Unable to load image " << path.c_str() <<
				"! Error " << IMG_GetError() << endl;
	} else {
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, NULL );
		if( optimizedSurface == NULL)
		{
			cerr << "Unable to optimize image " << path.c_str() <<
					"SDL ERROR " << SDL_GetError() << endl;
		}
		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	return optimizedSurface;
}

int main(int argv, char** argc) {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	//Start up SDL and create window
	if(!init())
	{
		cerr << "Failed to initialize\n";
	} else {
		//load media
		if(!loadMedia())
		{
			cerr << "Faild to load media\n" << endl;
		} else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while(!quit)
			{
				//Handle events on queue
				while(!SDL_PollEvent(&e) != 0)
				{
					//User requests to quit
					if(e.type == SDL_QUIT)
					{
						quit = true;
					}
				}
				//Set the picture to coordinates x and y, using a rectangle
				SDL_Rect rectangle;
				rectangle.h = 200;
				rectangle.w = 200;
				rectangle.x = 20;
				rectangle.y = 20;
				//load image to memory
				SDL_BlitSurface(gPNGSurface, NULL, gScreenSurface, &rectangle);

				//update the window
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}


	return 0;
}
