/*
 * main.cpp
 *
 *  Created on: Jun 26, 2017
 *      Author: SimoAngelov
 */

//Using SDL, SDL_image, standard IO, and strings
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include <stdio.h>
#include <string>
#include "globals.h"
#include "start.h"
#include "CBtn.h"

using namespace std;

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!Init())
	{
		cerr << "Failed to initialize" << endl;
	}
	else
	{
		//Load media
		if (!LoadMedia())
		{
			cerr << "Failed to load media" << endl;
		}
		else
		{
			//Event handler
			SDL_Event e;
			gChessBoard.EventHandle(e);
		}
	}

	//Free resources and close SDL
	Close();

	return 0;
}



