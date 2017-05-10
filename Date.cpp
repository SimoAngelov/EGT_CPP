/*
 * Date.cpp
 *
 *  Created on: Apr 24, 2017
 *      Author: SimoAngelov
 */

#include "Date.h"

#include "Date.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int Date::id = 0;
Date::Date() {
	// TODO Auto-generated constructor stub
	srand(time(0) + id);
	setYear(1900 + rand() % 200);
	setMonth(1 + rand() % 12);
	setDay(1 + rand()%31);
	id++;
}

Date::Date(int day, int month, int year) {
	//cout << "Date Constructor with parameters called" << endl;
	setYear(year);
	setMonth(month);
	setDay(day);
	id++;
}

int Date::getDay() const {
	return day;
}

void Date::setDay(int day) {
	if( (this->month==1)||(getMonth()==3)||(getMonth()==5)||(getMonth()==7)||(getMonth()==8)||(getMonth()==10)||(getMonth()==12)){
		if (day >= 1 && day <= 31) {
					this->day = day;
				} else {
					cout
							<< "Invalid day for month " << this->month <<". Entered values is below zero or above 31. The value will be set to 1!"
							<< endl;
					this->day = 1;
				}
	} else if((getMonth()==4)||(getMonth()==6)||(getMonth()==9)||(getMonth()==11)){
		if (day >= 1 && day <= 30) {
					this->day = day;
				} else {
					cout
							<< "Invalid day for month " << this->month <<". Entered values is below zero or above 30. The value will be set to 1!"
							<< endl;
					this->day = 1;
				}
	} else if(getMonth()==2){
		if(isLeapYear()==true){
			if (day >= 1 && day <= 29) {
				this->day = day;
			} else {
				cout
						<< "Invalid day for month " << this->month <<". Entered values is below zero or above 29. The value will be set to 1!"
						<< endl;
				this->day = 1;
			}
		}
		if(isLeapYear()==false){
			if (day >= 1 && day <= 28) {
				this->day = day;

			} else {
				cout
						<< "Invalid day for a non-leap year.Entered values is below zero or above 28. The value will be set to 1!"
						<< endl;
				this->day = 1;
			}
		}
	} else{
		cout << "ERROR! ERROR!" << endl;
		this->day = 1;
	}
}

int Date::getMonth() const {
	return month;
}

void Date::setMonth(int month) {
	if (month >= 1 && month <= 12) {
		this->month = month;
	} else {
		cout << "Invalid month. The value will be set to 1" << endl;
		this->month = 1;
	}
}

int Date::getYear() const {
	return this->year;
}

void Date::setYear(int year) {
	if (year >= 0) {
		this->year = year;
	} else {
		cout << "The year will be set to 2017." << endl;
		this->year = 2017;
	}
}

bool Date::isLeapYear() {
	if (getYear() % 4 == 0) {
		return true;
	} else if (getYear() % 100 == 0) {
		if (getYear() % 400 == 0) {
			return true;
		} else {
			return false;
		}
	} else {
		return true;
	}
}

ostream& operator << (ostream& out, const Date& date){
	out << date.getDay() << "/" << date.getMonth() << "/" << date.getYear();
	return out;
}
istream& operator >>(istream& in, Date& date){
	int d,m,y;
	cout << "--Input Date Info--";
	cout << "\nEnter day: ";
	in >> d;
	cout << "\nEnter month: ";
	in << m;
	cout << "\nEnter year: ";
	cin << y;
	date.setYear(y);
	date.setMonth(m);
	date.setDay(d);
	return in;
}
Date::~Date() {
	// TODO Auto-generated destructor stub
	//cout << "Date object destroyed!" << endl;
}



