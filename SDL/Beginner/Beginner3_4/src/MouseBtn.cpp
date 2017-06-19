/*
 * MouseBtn.cpp
 *
 *  Created on: Jun 15, 2017
 *      Author: SimoAngelov
 */

#include "MouseBtn.h"
#include "globals.h"
#include "MoveOptions.h"

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

void MouseBtn::Move() {
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (this->isClicked(0, 0)) {
		this->setPosition(40, 40);
	} else {
		this->setHeight(100);
		this->setWidth(100);
	}

}

void MouseBtn::Move(SDL_Event& e) {
	if (e.type == SDL_KEYDOWN) {
		//move sprite based on key press
		switch (e.key.keysym.sym) {
		case SDLK_UP:
			MoveUp();
			break;
		case SDLK_DOWN:
			MoveDown();
			break;
		case SDLK_LEFT:
			MoveLeft();
			break;
		case SDLK_RIGHT:
			MoveRight();
			break;
		default:
			this->setPosition(0, 0);
			break;
		}
	}
}

void MouseBtn::MoveLeft() {
	this->SetNewCurrent();
	newX = moveLeft;
	if (inLeft) {
		this->setPosition(newX, currentY);
	} else {
		newX = SCREEN_WIDTH - this->getWidth();
		this->setPosition(newX, currentY);
	}
}

void MouseBtn::MoveRight() {
	this->SetNewCurrent();
	newX = moveRight;
	if (inRight) {
		this->setPosition(newX, currentY);
	} else {
		newX = 0;
		this->setPosition(newX, currentY);
	}

}

void MouseBtn::MoveUp() {
	this->SetNewCurrent();
	newY = moveUp;
	if (underTop) {
		this->setPosition(currentX, newY);
	} else {
		newY = SCREEN_HEIGHT - this->getHeight();
		this->setPosition(currentX, newY);
	}
}

void MouseBtn::MoveDown() {
	this->SetNewCurrent();
	newY = moveDown;
	if (aboveBottom) {
		this->setPosition(currentX, newY);
	} else {
		newY = 0;
		this->setPosition(currentX, newY);
	}
}

void MouseBtn::SetNewCurrent() {
	currentX = this->getX();
	currentY = this->getY();
	newX = currentX;
	newY = currentY;

	aboveBottom = (newY + gButton.getHeight()) <= SCREEN_HEIGHT;
	underTop = (newY) >= 0;
	inRight = (newX + gButton.getWidth()) <= SCREEN_WIDTH;
	inLeft = (newX) >= 0;

	moveUp = currentY - 5;
	moveDown = currentY + 5;
	moveRight = currentX + 5;
	moveLeft = currentX - 5;
}

MouseBtn::~MouseBtn() {
	// TODO Auto-generated destructor stub
}

