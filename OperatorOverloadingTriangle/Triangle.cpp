/*
 * Triangle.cpp
 *
 *  Created on: 15.05.2017 г.
 *      Author: sim4o
 */

#include "Triangle.h"
#include <iostream>
using std::cout;
using std::endl;
Triangle::Triangle() {
	// TODO Auto-generated constructor stub
	setA(3);
	setB(4);
	setC(5);
	setH(10);
}

Triangle::Triangle(double a, double b, double c, double h){
	setSides(a, b, c, h);

}

void Triangle::setSides(double a, double b, double c, double h){
	if(this->exists(a, b, c)){
		this->setA(a);
		this->setB(b);
		this->setC(c);
		this->setH(h);
	} else {
		cout << "Triangle has invalid values, they will be set to default." << endl;
		this->setA(3);
		this->setB(4);
		this->setC(5);
		this->setH(10);
	}
}

double Triangle::getA() const {
	return a;
}

void Triangle::setA(double a) {
	this->a = a;
}

double Triangle::getB() const {
	return b;
}

void Triangle::setB(double b) {
	this->b = b;
}

double Triangle::getC() const {
	return c;
}

void Triangle::setC(double c) {
	this->c = c;
}

double Triangle::getH() const {
	return h;
}

void Triangle::setH(double h) {
	this->h = h;
}

bool Triangle::exists(double a, double b, double c) const{
	bool sideA = (a < b + c);
	bool sideB = (b < a + c);
	bool sideC = (c < a + b);
//	cout << "triangle exists: " << sideA && sideB && sideC;
//	cout << endl;
	return sideA && sideB && sideC;
}
//overloaded operators
bool Triangle::operator ==(const Triangle& right){
	bool result = (this->getA() == right.getA()) &&
					(this->getB() == right.getB()) &&
					(this->getC() == right.getC()) &&
					(this->getH() == right.getH());
	return result;
}

bool Triangle::operator !=(const Triangle& right){
	return !(*this == right);
}

istream& operator >>(istream& in, Triangle& triangle){
	double a, b, c, h;
	cout << "Input triangle in format -a-b-c-h" << endl;
	in.ignore();
	in >> a;
	in.ignore();
	in >> b;
	in.ignore();
	in >> c;
	in.ignore();
	in >> h;
	triangle.setSides(a, b, c, h);
	return in;
}

ostream& operator <<(ostream& out, const Triangle& triangle){
	out << "=>" << triangle.getA() << "," << triangle.getB()
			<< "," << triangle.getC() << "," << triangle.getH();
	return out;
}

Triangle::~Triangle() {
	// TODO Auto-generated destructor stub
}

