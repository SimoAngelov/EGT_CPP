/*
 * ChessPiece.cpp
 *
 *  Created on: Jun 26, 2017
 *      Author: SimoAngelov
 */

#include "ChessPiece.h"

ChessPiece::ChessPiece(): CDrawable() {
	// TODO Auto-generated constructor stub
	m_pieceSize = {PIECE_WIDTH, PIECE_HEIGHT};
}

ChessPiece::~ChessPiece() {
	// TODO Auto-generated destructor stub
}


//getters and setters
const Dimensions& ChessPiece::GetPieceSize() const {
	return m_pieceSize;
}

void ChessPiece::SetPieceSize(const Dimensions& pieceSize) {
	m_pieceSize = pieceSize;
}


//load from file
bool ChessPiece::LoadFromFile(SDL_Renderer* renderer, const string& path)
{
	this->FreeChessPiece();
	if (path != "")
	{
		SDL_Surface * loadedSurface = IMG_Load(path.c_str());
		if(!loadedSurface)
		{
			cerr << "Failed to load surface.SDL_ERROR " << SDL_GetError() << endl;
		} else
		{
			//set transparent background
			SDL_SetColorKey(loadedSurface, SDL_TRUE,
					SDL_MapRGB(loadedSurface->format, 255, 255, 255));
			m_texture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
			if(!m_texture)
			{
				cerr << "Failed to load texture " << SDL_GetError() << endl;
			} else {
				this->SetWidth(loadedSurface->w);
				this->SetHeight(loadedSurface->h);
				SDL_FreeSurface(loadedSurface);
				loadedSurface = NULL;
			}
		}
	}
	return m_texture != NULL;
}


//render the current chess piece
void ChessPiece::Draw(SDL_Renderer* renderer, Position newPos,
		SDL_Rect* currentRect, double, SDL_RendererFlip)
{
	SDL_Rect newPosition = {newPos.x, newPos.y,
	m_pieceSize.width, m_pieceSize.height};

	//resize the piece
	if(currentRect != NULL)
	{
		newPosition.w = this->m_rect.w / 25;
		newPosition.h = this->m_rect.h / 10;
	}
	SDL_RenderCopy(renderer, this->m_texture, currentRect, &newPosition);
}


void ChessPiece::FreeChessPiece()
{
	this->Free();
	m_pieceSize = {0, 0};
}
