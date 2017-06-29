/*
 * CBtn.cpp
 *
 *  Created on: Jun 26, 2017
 *      Author: SimoAngelov
 */

#include "CBtn.h"
#include "globals.h"
CBtn::CBtn(int x, int y): CDrawable(x, y)
{
	// TODO Auto-generated constructor stub
}


bool CBtn::IsClicked(int x, int y)
{
	if (x >= GetX() && x <= GetWidth() + GetX() && y >= GetY()
			&& y <= GetY() + GetHeight())
	{
		return true;
	}

	return false;
}

bool CBtn::LoadBtn(const string& fileName, SDL_Renderer* renderer)
{
	bool success = true;
	if (!this->LoadFromFile(renderer, fileName.c_str()))
	{
		cerr << "Failed to load button sprite texture!" << endl;
		success = false;
	}
	else
	{
		//Set sprites
		this->SetPosition(0, 0);
		this->SetWidth(50);
		this->SetHeight(50);
		this->ChangeColor();
	}
	return success;
}

void CBtn::Move()
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	//check if the next increase is in the limits of the screen
	bool limitX = this->GetWidth() < SCREEN_WIDTH;
	bool limitY = this->GetHeight() < SCREEN_HEIGHT;

	if(limitX)
	{
		//increase the width of the button by 10 pixels
		int increaseX = this->GetWidth() + BUTTON_GROWTH_X;
		this->SetWidth(increaseX);
	}
	if (limitY)
	{
		//increase the height of the button by 10 pixels
		int increaseY = this->GetHeight() + BUTTON_GROWTH_Y;
		this->SetHeight(increaseY);
	}
}




CBtn::~CBtn()
{
	// TODO Auto-generated destructor stub
}

