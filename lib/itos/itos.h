/*
 * itos.h
 *
 *  Created on: Jun 16, 2017
 *      Author: SimoAngelov
 */

#ifndef ITOS_H_
#define ITOS_H_

#include <iostream>
#include <sstream>
using std::stringstream;
using std::ostringstream;
using std::string;


template <typename T> string itos(T num)
{
	ostringstream stream;
	stream << num;
	return stream.str();
}


#endif /* ITOS_H_ */
