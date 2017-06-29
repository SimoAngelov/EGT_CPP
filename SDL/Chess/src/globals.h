
#ifndef GLOBALS_H_
#define GLOBALS_H_
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include "CBtn.h"
#include <iostream>
using std::cerr;
using std::endl;

//Screen dimension constants
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

//Button growth dimension constants
const int BUTTON_GROWTH_X = 10;
const int BUTTON_GROWTH_Y = 10;

//flag to check if an event is happening
extern bool gIsEvent;

//The window we'll be rendering to
extern SDL_Window* gWindow;

//The window renderer
extern SDL_Renderer* gRenderer;

//background texture
extern SDL_Texture* gBackground;

//size of the chess board
const int BOARD_WIDTH = SCREEN_WIDTH;
const int BOARD_HEIGHT = SCREEN_HEIGHT;

//size of the picture, containing all 12 pieces
const int PIECES_TEXTURE_WIDTH = 1800;
const int PIECES_TEXTURE_HEIGHT = 800;

const int PIECE_TEXTURE_WIDTH = 350;
const int PIECE_TEXTURE_HEIGHT = 350;

//number of pieces per row
const int NUMBER_OF_PIECES = 6;

//size of single chess piece
const int PIECE_WIDTH = 70;
const int PIECE_HEIGHT = 70;

//Number of squares
const int BOARD_SQUARES_X = 8;
const int BOARD_SQUARES_Y = 8;

const int BOARD_SQUARE_SIZE = 75;

const int STEP = 333;

extern bool gIsBlack;


typedef struct Dimensions
{
	int width;
	int height;
} Dimensions;

typedef struct Position
{
	int x;
	int y;
} Position;


#endif /* GLOBALS_H_ */
