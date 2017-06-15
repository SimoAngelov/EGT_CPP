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


//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;




#endif /* GLOBALS_H_ */
