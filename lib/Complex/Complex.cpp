/*
 * Complex.cpp
 *
 *  Created on: 30.05.2017 г.
 *      Author: sim4o
 */

#include "Complex.h"
#include <iostream>

using std::cout;
using std::endl;
Complex::Complex(double dRe, double dIm)
{
	// TODO Auto-generated constructor stub
	setDRe(dRe);
	setDIm(dIm);
}

double Complex::getDIm() const
{
	return m_dIm;
}

void Complex::setDIm(double dIm)
{
	m_dIm = dIm;
}

double Complex::getDRe() const
{
	return m_dRe;
}

void Complex::operator =(const Complex& compRight)
{
	this->setDRe(compRight.getDRe());
	this->setDIm(compRight.getDIm());
}

Complex Complex::operator +(const Complex& compRight)
{
	Complex result;
	double dRe = 0, dIm = 0;
	dRe = this->getDRe() + compRight.getDRe();
	dIm = this->getDIm() + compRight.getDIm();
	result.setDRe(dRe);
	result.setDIm(dIm);
	return result;
}

Complex Complex::operator -(const Complex& compRight)
{
	Complex result;
	double dRe = 0, dIm = 0;
	dRe = this->getDRe() - compRight.getDRe();
	dIm = this->getDIm() - compRight.getDIm();
	result.setDRe(dRe);
	result.setDIm(dIm);
	return result;
}

Complex Complex::operator *(const Complex& compRight)
{
	//(x+i*y)*(u+i*v) = (x*u - y*v) + i * (x*v - y*u)
	Complex result;
	double dRe = (this->getDRe() * compRight.getDRe()) -
			(this->getDIm() * compRight.getDIm());
	double dIm = (this->getDRe() * compRight.getDIm()) -
			(this->getDIm() * compRight.getDRe());
	result.setDRe(dRe);
	result.setDIm(dIm);
	return result;
}

Complex Complex::operator /(const Complex& compRight)
{
	// z1 = a + i * b
	// z2 = c + i * d
	//z1/z2 = {[(a*c + b*d) / [(c * c)] + (d *d)]} +
	//i * {[(b * c) - (a * d)] /[(c * c) + (d * d)]}
	Complex result;
	double dReNom = ((this->getDRe() * compRight.getDRe()) +
			(this->getDIm() * compRight.getDIm()));
	double dReDenom = (compRight.getDRe() * compRight.getDRe()) +
			(compRight.getDIm() * compRight.getDIm());
	double dImNom = (this->getDIm() * compRight.getDRe()) +
			(this->getDRe() * compRight.getDIm());
	double dImDenom = dReDenom;
	result.setDRe(dReNom/dReDenom);
	result.setDIm(dImNom/dImDenom);
	return result;
}

void Complex::setDRe(double dRe)
{
	m_dRe = dRe;
}

istream& operator >>(istream& in, Complex& complexNum)
{	cout << "Complex Number Z" << endl;
	double dRe, dIm;
	cout << "Enter Real part: ";
	in >> dRe;
	cout << "Enter Imaginary part: ";
	in >> dIm;
	complexNum.setDRe(dRe);
	complexNum.setDIm(dIm);
	cout << endl;
	return in;
}

ostream& operator <<(ostream& out, const Complex& complexNum)
{
	out << "z = " << complexNum.getDRe() << " + i * " << complexNum.getDIm() << "\n";
	return out;
}

Complex::~Complex()
{
	// TODO Auto-generated destructor stub
}

