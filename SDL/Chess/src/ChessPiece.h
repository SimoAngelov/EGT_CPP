/*
 * ChessPiece.h
 *
 *  Created on: Jun 26, 2017
 *      Author: SimoAngelov
 */

#ifndef CHESSPIECE_H_
#define CHESSPIECE_H_

#include "CDrawable.h"
#include "globals.h"
class ChessPiece: public CDrawable {
private:
	Dimensions m_pieceSize;
public:
	ChessPiece();
	virtual ~ChessPiece();
	//getters
	const Dimensions& GetPieceSize() const;
	//setters
	void SetPieceSize(const Dimensions& pieceSize);

	bool LoadFromFile(SDL_Renderer*, const string&);
	void Draw(SDL_Renderer*, Position, SDL_Rect*, double = 0, SDL_RendererFlip =
			SDL_FLIP_NONE);
	void FreeChessPiece();
};

#endif /* CHESSPIECE_H_ */
