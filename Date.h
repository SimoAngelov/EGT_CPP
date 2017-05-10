/*
 * Date.h
 *
 *  Created on: Apr 24, 2017
 *      Author: SimoAngelov
 */

#ifndef DATE_H_
#define DATE_H_

#include <iostream>
using namespace std;
class Date {
private:
	static int id;
	int day;
	int month;
	int year;

public:
	Date();
	Date(int day, int month, int year);
	int getDay() const;
	void setDay(int day);
	int getMonth() const;
	void setMonth(int month);
	int getYear() const;
	void setYear(int year);
	bool isLeapYear();
	friend ostream& operator <<(ostream& out, const Date& date);
	friend istream& operator >>(istream& in, Date& date);
	virtual ~Date();
};

#endif /* DATE_H_ */
