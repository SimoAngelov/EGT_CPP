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
#include "ChessBoard.h"
#include "globals.h"

using namespace std;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Background texture
SDL_Texture* gBackground = NULL;

//Chess board object
ChessBoard gChessBoard;

//flag to check if an event is happening
bool gIsEvent = true;

//flag to check if determine whether to draw black pieces
bool gIsBlack = false;

bool Init()
{
	//Initialization flag
	bool success = true;
	//Initialize SDL
	if (SDL_Init( SDL_INIT_VIDEO) < 0)
	{
		cerr << "SDL could not initialize! SDL Error: " << SDL_GetError()
				<< endl;
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			cerr << "Warning: Linear texture filtering not enabled!" << endl;
		}

		//Create window
		gWindow = SDL_CreateWindow("Chess", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			cerr << "Window could not be created! SDL Error:" << SDL_GetError()
					<< endl;
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				cerr << "Renderer could not be created! SDL Error: "
						<< SDL_GetError() << endl;
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
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

bool LoadMedia()
{
	//Loading success flag
	bool success = true;

	//Load sprite
	success = gChessBoard.LoadBoard("chessBoard1.png", gRenderer);
	//success = gButton.LoadBtn("sonic.png", gRenderer);
	return success;
}

void Close()
{
	//Free loaded images

	gChessBoard.Free();

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

void ClearUpdate()
{
	//Clear screen
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);

	//ChessBoard
	gChessBoard.Draw(gRenderer, 0, SDL_FLIP_NONE);
	gChessBoard.DrawWhitePieces();
	if(gIsBlack)
	{
		gChessBoard.DrawBlackPieces();
	}
	//Update screen
	SDL_RenderPresent(gRenderer);
}

