/*
 * CCDrawable.cpp
 *
 *  Created on: Jun 15, 2017
 *      Author: SimoAngelov
 */

#include "CDrawable.h"
#include "globals.h"
#include <iostream>


CDrawable::CDrawable(int x, int y) {
	setPosition(x, y);
	m_rect.w = 0;
	m_rect.h = 0;
	mTexture = NULL;
}

CDrawable::~CDrawable() {
	free();
}

int CDrawable::getHeight() const {
	return m_rect.h;
}

void CDrawable::setHeight(int height) {
	this->m_rect.h = height;
}

int CDrawable::getWidth() const {
	return m_rect.w;
}

void CDrawable::setWidth(int width) {
	this->m_rect.w = width;
}

int CDrawable::getX() const {
	return m_rect.x;
}

int CDrawable::getY() const {
	return m_rect.y;
}

void CDrawable::draw(SDL_Renderer* gRenderer, double angle,
		SDL_RendererFlip flip) {
	if (mTexture) {
		SDL_RenderCopyEx(gRenderer, mTexture, 0, &m_rect, angle, 0, flip);
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
		//this->setWidth(loadedSurface->w);
		//this->setHeight(loadedSurface->h);
		this->setWidth(350);
		this->setHeight(200);
		SDL_FreeSurface(loadedSurface);
		loadedSurface = NULL;
	}
	return mTexture != NULL;
}

void CDrawable::setPosition(int x, int y) {
	this->m_rect.x = x;
	this->m_rect.y = y;
}

void CDrawable::drawRect(SDL_Renderer* renderer, int x, int y,
		int w, int h, basicColor color) {
	//SDL_Rect fillRect = { x, y, w, h};
	this->m_rect = { x, y, w, h};
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b , 0xFF);
	SDL_RenderFillRect(renderer, &m_rect);
}

void CDrawable::drawRandomRect()
{

	srand(time(0));
	int x = rand() % SCREEN_WIDTH;
	int y = rand() % SCREEN_HEIGHT;
	int w = rand() % (SCREEN_WIDTH - x);
	int h = rand() % (SCREEN_HEIGHT - y);
	int r, g, b;
	r = rand() % 0xFF;
	g = rand() % 0xFF;
	b = rand() % 0xFF;
	basicColor color = {r, g, b};
	this->drawRect(gRenderer, x, y, w, h, color);

}
