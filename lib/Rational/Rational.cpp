//============================================================================
// Name        : Rational.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Rational.h"
using namespace std;

Rational::Rational() {
	setFraction(1, 1);
}

Rational::Rational(int p, int q) {
	setFraction(p, q);
}

void Rational::setFraction(int p, int q) {
	setNumerator(p);
	setDenominator(q);
	setWhole(p, q);
	setNumber();
}

int Rational::getDenominator() const {
	return denominator;
}

void Rational::setDenominator(int denominator) {
	this->denominator = (denominator != 0) ? denominator : 1;
}

int Rational::getNumerator() const {
	return numerator;
}

void Rational::setNumerator(int numerator) {
	this->numerator = numerator;
}

int Rational::getNumber() const {
	return number;
}

void Rational::setNumber(){
	if(this->isWhole()){
		this->number = this->getNumerator() / this->getDenominator();
	} else {
		this->number = -1;
	}
}
bool Rational::isWhole() const {
	return whole;
}

void Rational::setWhole(int p, int q){
	if((p >= q) && (p % q == 0)){
		whole = true;
	} else{
		whole = false;
	}
}
Rational::~Rational() {
	// TODO Auto-generated destructor stub
}

bool Rational::operator ==(const Rational& right) {
	bool result = false;
	if (this->isWhole() && right.isWhole()) {
		result = this->getNumber() == right.getNumber();
	} else {
		result = (this->getDenominator() == right.getDenominator())
				&& (this->getNumerator() == right.getNumerator());
	}

	return result;
}

bool Rational::operator !=(const Rational& right) {
	bool result = !(*this == right);
	return result;
}

bool Rational::operator <(const Rational& right) {
	bool result = false;

	if (this->getDenominator() == right.getDenominator()) {
		if (this->getNumerator() < right.getNumerator()) {
			result = true;
		} else {
			result = false;
		}
	} else if (this->getDenominator() > right.getDenominator()) {
		result = true;
	} else {
		result = false;
	}
	return result;
}

bool Rational::operator >(const Rational& right) {
	bool result = !(*this == right) && !(*this < right);
	return result;
}

bool Rational::operator <=(const Rational& right) {
	return (*this < right) || (*this ==  right);
}

bool Rational::operator >=(const Rational& right) {
	return(*this > right) || (*this == right);
}

void Rational::operator =(const Rational& right) {
	this->setFraction(right.getNumerator(), right.getDenominator());
}

Rational& Rational::operator +(const Rational& right) {
	Rational* result;

}

Rational& Rational::operator -(const Rational& right) {
}

Rational& Rational::operator *(const Rational& right) {
}

Rational& Rational::operator /(const Rational& right) {
}

istream& operator >>(istream& in, Rational& fraction) {
	int p, q;
	cout << "Enter numerator P: ";
	in >> p;
	cout << "Enter denominator Q: ";
	in >> q;
	fraction.setFraction(p, q);
	return in;
}

ostream& operator <<(ostream& out, const Rational& fraction) {
	if ((fraction.getNumerator() >= fraction.getDenominator())
			&& (fraction.getNumerator() % fraction.getDenominator() == 0)) {
		out << "P/Q = " << fraction.getNumerator() << "/"
				<< fraction.getDenominator() << " = "
				<< fraction.getNumerator() / fraction.getDenominator();
	} else {
		out << "P/Q = " << fraction.getNumerator() << "/"
				<< fraction.getDenominator();
	}
	return out;
}
