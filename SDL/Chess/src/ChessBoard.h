/*
 * ChessBoard.h
 *
 *  Created on: Jun 26, 2017
 *      Author: SimoAngelov
 */

#ifndef CHESSBOARD_H_
#define CHESSBOARD_H_

#include "CDrawable.h"
#include "ChessPiece.h"

class ChessBoard: public CDrawable {
private:
	ChessPiece m_pieces;
	SDL_Rect m_whitePieces[NUMBER_OF_PIECES];
	SDL_Rect m_blackPieces[NUMBER_OF_PIECES];
	void InitPieces();
	void DrawWhitePawns();
	void DrawWhiteRooks();
	void DrawWhiteKnights();
	void DrawWhiteBishops();
	void DrawWhiteQueen();
	void DrawWhiteKing();
	void DrawBlackPawns();
	void DrawBlackRooks();
	void DrawBlackKnights();
	void DrawBlackBishops();
	void DrawBlackQueen();
	void DrawBlackKing();
public:
	ChessBoard();
	bool LoadFromFile(SDL_Renderer*, const string&);
	bool LoadBoard(const string&, SDL_Renderer*);
	void DrawWhitePieces();
	void DrawBlackPieces();
	void Draw(SDL_Renderer*, double = 0, SDL_RendererFlip =
			SDL_FLIP_NONE);
	void EventHandle(SDL_Event&);
	virtual ~ChessBoard();
};

#endif /* CHESSBOARD_H_ */
