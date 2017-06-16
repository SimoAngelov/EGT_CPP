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
MouseBtn::~MouseBtn() {
	// TODO Auto-generated destructor stub
}

