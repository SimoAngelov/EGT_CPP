
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

//flag to check if an event is happening
extern bool gIsEvent;

//The window we'll be rendering to
extern SDL_Window* gWindow;

//The window renderer
extern SDL_Renderer* gRenderer;






#endif /* GLOBALS_H_ */
