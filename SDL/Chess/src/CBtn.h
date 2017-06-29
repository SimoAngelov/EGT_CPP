/*
 * CBtn.h
 *
 *  Created on: Jun 26, 2017
 *      Author: SimoAngelov
 */

#ifndef CBTN_H_
#define CBTN_H_

#include "CDrawable.h"
#include <iostream>
using std::string;
using std::cout;
using std::cerr;
using std::endl;

class CBtn: public CDrawable
{
public:
	CBtn(int x = 0, int y = 0);
	virtual bool IsClicked(int x, int y);
	virtual bool LoadBtn(const string&, SDL_Renderer*);
	void Move();

	virtual ~CBtn();
};

#endif /* CBTN_H_ */
