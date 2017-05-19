/*
 * Rational.h
 *
 *  Created on: 19.05.2017 г.
 *      Author: sim4o
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_

#include <iostream>
using std::istream;
using std::ostream;
class Rational {
private:
	int numerator;
	int denominator;
	bool whole;
	int number;
public:
	Rational();
	Rational(int, int);
	virtual ~Rational();
	void setFraction(int p, int q);
	int getDenominator() const;
	void setDenominator(int denominator);
	int getNumerator() const;
	void setNumerator(int numerator);
	int getNumber() const;
	void setNumber();
	bool isWhole() const;
	void setWhole(int, int);

	bool operator==(const Rational&);
	bool operator!=(const Rational&);
	bool operator<(const Rational&);
	bool operator>(const Rational&);
	bool operator<=(const Rational&);
	bool operator>=(const Rational&);
	void operator=(const Rational&);
	Rational& operator+(const Rational&);
	Rational& operator-(const Rational&);
	Rational& operator*(const Rational&);
	Rational& operator/(const Rational&);
	friend istream& operator >> (istream&, Rational&);
	friend ostream& operator << (ostream&, const Rational&);
};

#endif /* RATIONAL_H_ */
