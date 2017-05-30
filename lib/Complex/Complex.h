/*
 * Complex.h
 *
 *  Created on: 30.05.2017 г.
 *      Author: sim4o
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
using std::istream;
using std::ostream;
class Complex
{
private:
	double m_dRe;
	double m_dIm;
public:
	Complex(double dRe = 0.0, double dIm = 0.0);
	friend istream& operator >>(istream&, Complex&);
	friend ostream& operator <<(ostream&, const Complex&);
	void operator = (const Complex&);
	Complex operator + (const Complex&);
	Complex operator - (const Complex&);
	Complex operator * (const Complex&);
	Complex operator / (const Complex&);

	virtual ~Complex();
	double getDIm() const;
	void setDIm(double dIm);
	double getDRe() const;
	void setDRe(double dRe);
};

#endif /* COMPLEX_H_ */
