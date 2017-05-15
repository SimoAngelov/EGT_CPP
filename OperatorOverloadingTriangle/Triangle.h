/*
 * Triangle.h
 *
 *  Created on: 15.05.2017 г.
 *      Author: sim4o
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <iostream>
using std::istream;
using std::ostream;
class Triangle {
private:
	double a; //side a
	double b; //side b
	double c; //side c
	double h; //height
public:
	Triangle();
	Triangle(double, double, double, double);

	virtual ~Triangle();
	double getA() const;
	void setA(double a);
	double getB() const;
	void setB(double b);
	double getC() const;
	void setC(double c);
	double getH() const;
	void setH(double h);
	void setSides(double a, double b, double c, double h);
	bool exists(double a, double b, double c) const;

	bool operator ==(const Triangle&);
	bool operator !=(const Triangle&);
	friend istream& operator >>(istream&, Triangle&);
	friend ostream& operator <<(ostream&,const Triangle&);

};

#endif /* TRIANGLE_H_ */
