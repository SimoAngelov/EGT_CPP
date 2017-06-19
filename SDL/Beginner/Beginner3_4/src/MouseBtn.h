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

class MouseBtn: public CDrawable {
private:
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
	void Move(SDL_Event&);
	virtual ~MouseBtn();
};

#endif /* MOUSEBTN_H_ */
