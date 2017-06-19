/*
 * MouseBtn.cpp
 *
 *  Created on: Jun 15, 2017
 *      Author: SimoAngelov
 */

#include "MouseBtn.h"

MouseBtn::MouseBtn(int x, int y): CDrawable(x, y)
{
	// TODO Auto-generated constructor stub

}


bool MouseBtn::isClicked(int x, int y)
{
	if (x >= getX() && x <= getWidth() + getX() && y >= getY()
			&& y <= getY() + getHeight()) {
		return true;
	}

return false;
}


bool MouseBtn::loadBtn(const string& fileName, SDL_Renderer* renderer)
{
	bool success = true;
	if (!this->loadFromFile(renderer, fileName.c_str())) {
		cerr << "Failed to load button sprite texture!" << endl;
		success = false;
	} else {
		//Set sprites
		this->setPosition(0, 0);
		this->setWidth(200);
		this->setHeight(200);
	}
	return success;
}

void MouseBtn::Move()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (this->isClicked(0, 0))
	{
		this->setPosition(40, 40);
	}
	else
	{
		this->setHeight(100);
		this->setWidth(100);
	}

}


MouseBtn::~MouseBtn() {
	// TODO Auto-generated destructor stub
}

