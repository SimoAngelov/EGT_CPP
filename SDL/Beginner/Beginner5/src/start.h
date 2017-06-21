/*
 * start.h
 *
 *  Created on: Jun 19, 2017
 *      Author: SimoAngelov
 */

#ifndef START_H_
#define START_H_

#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include "MouseBtn.h"
#include <iostream>
using std::cerr;
using std::endl;


//Buttons object
extern MouseBtn gButton;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//clear the screen, render buttons and render it
void clearUpdate();

//check for collision

bool CheckCollision(SDL_Rect&, SDL_Rect&);



#endif /* START_H_ */
