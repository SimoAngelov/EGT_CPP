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
class CDrawable {
public:
	CDrawable(int x, int y);
	virtual ~CDrawable();
	virtual bool loadFromFile(SDL_Renderer* gRenderer, string path);
	virtual void draw(SDL_Renderer*, double = 0, SDL_RendererFlip = SDL_FLIP_NONE);
	virtual void free();
	int getHeight() const;
	void setHeight(int height);
	int getWidth() const;
	void setWidth(int width);
	int getX() const;
	int getY() const;
	virtual void setPosition(int x, int y);

protected:
	SDL_Texture * mTexture;
	SDL_Rect rect;
};

#endif /* CDRAWABLE_H_ */
