/*
 * MouseBtn.cpp
 *
 *  Created on: Jun 15, 2017
 *      Author: SimoAngelov
 */

#include "MouseBtn.h"
#include "globals.h"

MouseBtn::MouseBtn(int x, int y) :
		CDrawable(x, y) {
	// TODO Auto-generated constructor stub

}

bool MouseBtn::isClicked(int x, int y) {
	if (x >= getX() && x <= getWidth() + getX() && y >= getY()
			&& y <= getY() + getHeight()) {
		return true;
	}

	return false;
}

bool MouseBtn::loadBtn(const string& fileName, SDL_Renderer* renderer) {
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

void MouseBtn::EventHandle(SDL_Event& e) {
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
		//move sprite based on key press
		switch (e.key.keysym.sym) {
		case SDL_SCANCODE_UP:
			m_velocity.y += gSpeed;
			break;
		case SDL_SCANCODE_DOWN:
			m_velocity.y -= gSpeed;
			break;
		case SDL_SCANCODE_LEFT:
			m_velocity.x += gSpeed;
			break;
		case SDL_SCANCODE_RIGHT:
			m_velocity.x -= gSpeed;
			break;
		default:
			this->setPosition(0, 0);
			m_velocity = {0, 0};
			break;
		}
	}
}

void MouseBtn::Move() {
	static bool goRight = false;
	static bool goUp = false;

	if (this->getX() <= 0) {
		goRight = true;
	} else if (this->getX() + this->getWidth() >= SCREEN_WIDTH) {
		goRight = false;
	}

	if (this->getY() <= 0) {
		goUp = false;
	} else if (this->getY() + this->getHeight() >= SCREEN_HEIGHT) {
		goUp = true;
	}

	this->m_rect.x += (goRight) ? gSpeed : (-1) * gSpeed;
	this->m_rect.y += (goUp) ? ((-1) * gSpeed) : gSpeed;

}

bool MouseBtn::IsInside() {
	return (this->getX() >= 0)
			&& (this->getX() + this->getWidth() <= SCREEN_WIDTH)
			&& (this->getY() >= 0)
			&& (this->getY() + this->getHeight() <= SCREEN_HEIGHT);
}

MouseBtn::~MouseBtn() {
	// TODO Auto-generated destructor stub
}

