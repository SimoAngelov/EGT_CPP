/*
 * CCDrawable.cpp
 *
 *  Created on: Jun 26, 2017
 *      Author: SimoAngelov
 */

#include "CDrawable.h"
#include <iostream>
#include <cstdlib>
using std::srand;
#include <ctime>

CDrawable::CDrawable(int x, int y)
{
	SetPosition(x, y);
	m_rect.w = 0;
	m_rect.h = 0;
	m_texture = NULL;
}

CDrawable::~CDrawable()
{
	Free();
}

int CDrawable::GetHeight() const
{
	return m_rect.h;
}

void CDrawable::SetHeight(int height)
{
	this->m_rect.h = height;
}

int CDrawable::GetWidth() const
{
	return m_rect.w;
}

void CDrawable::SetWidth(int width)
{
	this->m_rect.w = width;
}

int CDrawable::GetX() const
{
	return m_rect.x;
}

int CDrawable::GetY() const
{
	return m_rect.y;
}

void CDrawable::Draw(SDL_Renderer* gRenderer, double angle,
		SDL_RendererFlip flip)
{
	if (m_texture)
	{
		SDL_RenderCopyEx(gRenderer, m_texture, 0, &m_rect, angle, 0, flip);
	}
}

void CDrawable::Free()
{
	if (m_texture)
	{
		SDL_DestroyTexture(m_texture);
		m_texture = 0;
	}
}

bool CDrawable::LoadFromFile(SDL_Renderer* gRenderer, const string& path)
{
	if (path != "")
	{
		SDL_Surface * loadedSurface = IMG_Load(path.c_str());
		m_texture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		this->SetWidth(loadedSurface->w);
		this->SetHeight(loadedSurface->h);
		SDL_FreeSurface(loadedSurface);
		loadedSurface = NULL;
	}
	return m_texture != NULL;
}

void CDrawable::SetPosition(int x, int y)
{
	this->m_rect.x = x;
	this->m_rect.y = y;
}

void CDrawable::SetColor(Uint8 red, Uint8 green, Uint8 blue)
{
	//Modulate texture
	SDL_SetTextureColorMod(m_texture, red, green, blue);
}

void CDrawable::ChangeColor()
{
	//set random color scheme for button
	srand(time(0));
	int r, g, b;
	r = rand() % 0xFF;
	g = rand() % 0xFF;
	b = rand() % 0xFF;
	this->SetColor(r, g, b);

}

