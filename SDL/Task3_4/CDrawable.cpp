/*
 * CCDrawable.cpp
 *
 *  Created on: Jun 15, 2017
 *      Author: SimoAngelov
 */

#include "CDrawable.h"
#include <iostream>

CDrawable::CDrawable(int x, int y) {
	setPosition(x, y);
	rect.w = 0;
	rect.h = 0;
	mTexture = NULL;
}

CDrawable::~CDrawable() {
	free();
}

int CDrawable::getHeight() const {
	return rect.h;
}

void CDrawable::setHeight(int height) {
	this->rect.h = height;
}

int CDrawable::getWidth() const {
	return rect.w;
}

void CDrawable::setWidth(int width) {
	this->rect.w = width;
}

int CDrawable::getX() const {
	return rect.x;
}

int CDrawable::getY() const {
	return rect.y;
}

void CDrawable::draw(SDL_Renderer* gRenderer, double angle, SDL_RendererFlip flip) {
	if (mTexture) {
		SDL_RenderCopyEx(gRenderer, mTexture, 0, &rect,angle,0, flip);
	}
}

void CDrawable::free() {
	if (mTexture) {
		SDL_DestroyTexture(mTexture);
		mTexture = 0;
	}
}


bool CDrawable::loadFromFile(SDL_Renderer* gRenderer, std::string path) {
	if (path != "") {
		SDL_Surface * loadedSurface = IMG_Load(path.data());
		mTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		this->setWidth(loadedSurface->w);
		this->setHeight(loadedSurface->h);
		SDL_FreeSurface(loadedSurface);
		loadedSurface = NULL;
	}
	return mTexture != NULL;
}

void CDrawable::setPosition(int x, int y) {
	this->rect.x = x;
	this->rect.y = y;
}
