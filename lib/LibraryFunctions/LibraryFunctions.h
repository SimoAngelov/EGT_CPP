/*
 * LibraryFunctions.h
 *
 *  Created on: 23.05.2017 г.
 *      Author: sim4o
 */

#ifndef LIBRARYFUNCTIONS_H_
#define LIBRARYFUNCTIONS_H_

#include <string>
using std::string;

template <typename T> string formatCurrency(const string&, T);
string camelCase(string&);

double RoundDouble(double, int);

typedef struct{
	int quotient;
	int remainder;
} structDiv;

structDiv Divide(int, int);
#endif /* LIBRARYFUNCTIONS_H_ */
