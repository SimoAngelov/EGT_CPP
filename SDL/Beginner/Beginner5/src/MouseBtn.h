/*
 * MouseBtn.h
 *
 *  Created on: Jun 15, 2017
 *      Author: SimoAngelov
 */

#ifndef MOUSEBTN_H_
#define MOUSEBTN_H_

#include "CDrawable.h"
#include <iostream>
using std::string;
using std::cout;
using std::cerr;
using std::endl;

typedef struct Velocity
{
	int x;
	int y;
} Velocity;

class MouseBtn: public CDrawable {
private:
	Velocity m_velocity;
	void SetNewCurrent();
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

public:
	MouseBtn(int x = 0, int y = 0);
	virtual bool isClicked(int x, int y);
	virtual bool loadBtn(const string&, SDL_Renderer*);
	void Move();
	void EventHandle(SDL_Event&);
	bool IsInside();
	virtual ~MouseBtn();
};

#endif /* MOUSEBTN_H_ */
