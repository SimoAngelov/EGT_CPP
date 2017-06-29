/*
 * CDrawable.h
 *
 *  Created on: Jun 15, 2017
 *      Author: SimoAngelov
 */

#ifndef CDRAWABLE_H_
#define CDRAWABLE_H_

#include <iostream>
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
using std::string;
class CDrawable
{
public:
	CDrawable(int x = 0, int y = 0);
	virtual ~CDrawable();
	virtual bool LoadFromFile(SDL_Renderer* gRenderer, const string& path);
	virtual void Draw(SDL_Renderer*, double = 0, SDL_RendererFlip =
			SDL_FLIP_NONE);
	virtual void Free();
	int GetHeight() const;
	void SetHeight(int height);
	int GetWidth() const;
	void SetWidth(int width);
	int GetX() const;
	int GetY() const;
	virtual void SetPosition(int x, int y);
	void ChangeColor();
	void SetColor(Uint8 red, Uint8 green, Uint8 blue);

protected:
	SDL_Texture * m_texture;
	SDL_Rect m_rect;
};

#endif /* CDRAWABLE_H_ */
