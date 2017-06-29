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
#include "ChessBoard.h"
#include <iostream>
using std::cerr;
using std::endl;

//Chess board object
extern ChessBoard gChessBoard;

//Starts up SDL and creates window
bool Init();

//Loads media
bool LoadMedia();

//Frees media and shuts down SDL
void Close();

//clear the screen, render buttons and update it
void ClearUpdate();

#endif /* START_H_ */
