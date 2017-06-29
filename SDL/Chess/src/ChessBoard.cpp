/*
 * ChessBoard.cpp
 *
 *  Created on: Jun 26, 2017
 *      Author: SimoAngelov
 */

#include "ChessBoard.h"
#include "start.h"
ChessBoard::ChessBoard() :
		CDrawable()
{
	// TODO Auto-generated constructor stub

}

ChessBoard::~ChessBoard()
{
	// TODO Auto-generated destructor stub
}

void ChessBoard::EventHandle(SDL_Event& e)
{
	//Main loop flag
	bool quit = false;



	//While application is running
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//is an event
			gIsEvent = true;

			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			switch(e.key.keysym.sym)
			{
			case SDLK_RETURN:
				gIsBlack = true;
				break;
			}
		}

		//if an event occurs
		if (gIsEvent)
		{
			ClearUpdate();
			gIsEvent = false;
		}

	}
}


bool ChessBoard::LoadFromFile(SDL_Renderer* renderer, const string& path)
{
	if (path != "")
	{
		SDL_Surface * loadedSurface = IMG_Load(path.c_str());
		gBackground = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		SDL_FreeSurface(loadedSurface);
		loadedSurface = NULL;
		m_pieces.LoadFromFile(renderer, "chessPieces.png");
	}
	return gBackground != NULL;
}

bool ChessBoard::LoadBoard(const string& fileName, SDL_Renderer* renderer)
{
	bool success = true;
	if (!this->LoadFromFile(renderer, fileName.c_str()))
	{
		cerr << "Failed to chessBoard texture!" << endl;
		success = false;
	}
	else
	{
		this->InitPieces();
	}
	return success;
}

void ChessBoard::Draw(SDL_Renderer* renderer, double angle,
		SDL_RendererFlip flip)
{
	if (gBackground)
	{
		SDL_Rect backgroundRect
		{ 0, 0, BOARD_WIDTH, BOARD_HEIGHT };
		SDL_RenderCopy(renderer, gBackground, NULL, &backgroundRect);
	//	this->DrawWhitePieces();
	}
}

void ChessBoard::InitPieces()
{
	for (int i = 0; i < NUMBER_OF_PIECES; i++)
	{
		m_whitePieces[i].x = i * STEP;
		m_whitePieces[i].y = 0;
		m_whitePieces[i].w = PIECE_TEXTURE_WIDTH;
		m_whitePieces[i].h = PIECE_TEXTURE_HEIGHT;

		m_blackPieces[i].x = i * STEP;
		m_blackPieces[i].y = PIECE_TEXTURE_HEIGHT;
		m_blackPieces[i].w = PIECE_TEXTURE_WIDTH;
		m_blackPieces[i].h = PIECE_TEXTURE_HEIGHT;
	}
}
void ChessBoard::DrawWhitePieces()
{
	DrawWhitePawns();
	DrawWhiteRooks();
	DrawWhiteKnights();
	DrawWhiteBishops();
	DrawWhiteQueen();
	DrawWhiteKing();
}


void ChessBoard::DrawBlackPieces()
{
	DrawBlackPawns();
	DrawBlackRooks();
	DrawBlackKnights();
	DrawBlackBishops();
	DrawBlackQueen();
	DrawBlackKing();
}

//black piece draw functions
void ChessBoard::DrawBlackPawns()
{
	for (int i = 0; i < BOARD_SQUARES_Y; i++)
	{
		int x = (i * BOARD_SQUARE_SIZE);
		int y = ((BOARD_SQUARES_Y - 7) * BOARD_SQUARE_SIZE);
		Position currentPosition =
		{ x, y };
		m_pieces.Draw(gRenderer, currentPosition, &m_blackPieces[5]);
	}

}
void ChessBoard::DrawBlackRooks()
{
	int i = 0;
	int x1 = (i * BOARD_SQUARE_SIZE);
	int y1 = 0;
	int x2 = ((BOARD_SQUARES_X - i - 1) * BOARD_SQUARE_SIZE);
	int y2 = y1;
	Position rookA8Position =
	{ x1, y1 };
	Position rookH8Position =
	{ x2, y2 };
	m_pieces.Draw(gRenderer, rookA8Position, &m_blackPieces[4]);
	m_pieces.Draw(gRenderer, rookH8Position, &m_blackPieces[4]);
}

void ChessBoard::DrawBlackKnights()
{
	int i = 1;
	int x1 = (i * BOARD_SQUARE_SIZE);
	int y1 = 0;
	int x2 = ((BOARD_SQUARES_X - i - 1) * BOARD_SQUARE_SIZE);
	int y2 = y1;
	Position knightB8Position =
	{ x1, y1 };
	Position knightG8Position =
	{ x2, y2 };
	m_pieces.Draw(gRenderer, knightB8Position, &m_blackPieces[3]);
	m_pieces.Draw(gRenderer, knightG8Position, &m_blackPieces[3]);
}

void ChessBoard::DrawBlackBishops()
{
	int i = 2;
	int x1 = (i * BOARD_SQUARE_SIZE);
	int y1 = 0;
	int x2 = ((BOARD_SQUARES_X - i - 1) * BOARD_SQUARE_SIZE);
	int y2 = y1;
	Position bishopC8Position =
	{ x1, y1 };
	Position bishopF8Position =
	{ x2, y2 };
	m_pieces.Draw(gRenderer, bishopC8Position, &m_blackPieces[2]);
	m_pieces.Draw(gRenderer, bishopF8Position, &m_blackPieces[2]);

}

void ChessBoard::DrawBlackQueen()
{
	int i = 3;
	int x1 = (i * BOARD_SQUARE_SIZE);
	int y1 = 0;
	Position queenD8Position =
	{ x1, y1 };
	m_pieces.Draw(gRenderer, queenD8Position, &m_blackPieces[1]);
}

void ChessBoard::DrawBlackKing()
{
	int i = 4;
	int x1 = (i * BOARD_SQUARE_SIZE);
	int y1 = 0;
	Position kingE8Position =
	{ x1, y1 };
	m_pieces.Draw(gRenderer, kingE8Position, &m_blackPieces[0]);
}

//White piece draw functions
void ChessBoard::DrawWhitePawns()
{
	for (int i = 0; i < BOARD_SQUARES_Y; i++)
	{
		int x = (i * BOARD_SQUARE_SIZE);
		int y = ((BOARD_SQUARES_Y - 2) * BOARD_SQUARE_SIZE);
		Position currentPosition =
		{ x, y };
		m_pieces.Draw(gRenderer, currentPosition, &m_whitePieces[5]);
	}

}
void ChessBoard::DrawWhiteRooks()
{
	int i = 0;
	int x1 = (i * BOARD_SQUARE_SIZE);
	int y1 = (BOARD_SQUARES_Y - 1) * BOARD_SQUARE_SIZE;
	int x2 = ((BOARD_SQUARES_X - i - 1) * BOARD_SQUARE_SIZE);
	int y2 = y1;
	Position rookA1Position =
	{ x1, y1 };
	Position rookH1Position =
	{ x2, y2 };
	m_pieces.Draw(gRenderer, rookA1Position, &m_whitePieces[4]);
	m_pieces.Draw(gRenderer, rookH1Position, &m_whitePieces[4]);
}

void ChessBoard::DrawWhiteKnights()
{
	int i = 1;
	int x1 = (i * BOARD_SQUARE_SIZE);
	int y1 = (BOARD_SQUARES_Y - 1) * BOARD_SQUARE_SIZE;
	int x2 = ((BOARD_SQUARES_X - i - 1) * BOARD_SQUARE_SIZE);
	int y2 = y1;
	Position knightB1Position =
	{ x1, y1 };
	Position knightG1Position =
	{ x2, y2 };
	m_pieces.Draw(gRenderer, knightB1Position, &m_whitePieces[3]);
	m_pieces.Draw(gRenderer, knightG1Position, &m_whitePieces[3]);
}

void ChessBoard::DrawWhiteBishops()
{
	int i = 2;
	int x1 = (i * BOARD_SQUARE_SIZE);
	int y1 = (BOARD_SQUARES_Y - 1) * BOARD_SQUARE_SIZE;
	int x2 = ((BOARD_SQUARES_X - i - 1) * BOARD_SQUARE_SIZE);
	int y2 = y1;
	Position bishopC1Position =
	{ x1, y1 };
	Position bishopF1Position =
	{ x2, y2 };
	m_pieces.Draw(gRenderer, bishopC1Position, &m_whitePieces[2]);
	m_pieces.Draw(gRenderer, bishopF1Position, &m_whitePieces[2]);

}

void ChessBoard::DrawWhiteQueen()
{
	int i = 3;
	int x1 = (i * BOARD_SQUARE_SIZE);
	int y1 = (BOARD_SQUARES_Y - 1) * BOARD_SQUARE_SIZE;
	Position queenD1Position =
	{ x1, y1 };
	m_pieces.Draw(gRenderer, queenD1Position, &m_whitePieces[1]);
}

void ChessBoard::DrawWhiteKing()
{
	int i = 4;
	int x1 = (i * BOARD_SQUARE_SIZE);
	int y1 = (BOARD_SQUARES_Y - 1) * BOARD_SQUARE_SIZE;
	Position kingE1Position =
	{ x1, y1 };
	m_pieces.Draw(gRenderer, kingE1Position, &m_whitePieces[0]);
}



