/*
 * CinemaChain.h
 *
 *  Created on: Jun 3, 2017
 *      Author: SimoAngelov
 */

#ifndef CINEMACHAIN_H_
#define CINEMACHAIN_H_
#include <vector>
using std::vector;
#include "Cinema.h"
#include <map>

class CinemaChain
{
private:
	vector<Cinema> cinemas;
public:
	CinemaChain();

	virtual ~CinemaChain();
};

#endif /* CINEMACHAIN_H_ */
