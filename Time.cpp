/*
 * Time.cpp
 *
 *  Created on: 5.05.2017 г.
 *      Author: sim4o
 */

#include "Time.h"
#include <iostream>
using std::istream;
using std::ostream;
using std::cout;
#include <cstdlib>

int Time::id = 0;
Time::Time(int milliseconds, int seconds, int minutes, int hours) {
	setTime(milliseconds, seconds, minutes, hours);
	id++;
}



Time::Time() {
	// TODO Auto-generated constructor stub
	srand(time(0) + id);
	int ms, s, m, h;
	ms = rand() % 999;
	s = rand() % 59;
	m = rand() % 59;
	h = rand() % 12;
	setTime(ms, s, m, h);
	id++;
}

Time::~Time() {
	// TODO Auto-generated destructor stub
}

int Time::getHours() const {
	return hours;
}

void Time::setHours(int hours) {
	this->hours = (hours >= 0) ? hours : 0;
}

int Time::getMilliseconds() const {
	return milliseconds;
}

void Time::setMilliseconds(int milliseconds) {
	this->milliseconds = (milliseconds >=0 && milliseconds <= 999) ? milliseconds : 0;

}

int Time::getMinutes() const {
	return minutes;
}

void Time::setMinutes(int minutes) {
	this->minutes = (minutes >=0 && minutes <=59) ? minutes : 0;
}

int Time::getSeconds() const {
	return seconds;
}
void Time::setSeconds(int seconds) {
	this->seconds = (seconds >=0 && seconds <= 59) ? seconds: 0;;
}

void Time::setTime(int milliseconds, int seconds, int minutes, int hours) {
	milliseconds = (milliseconds >=0 && milliseconds <= 999) ? milliseconds : 0;
	seconds = (seconds >=0 && seconds <= 59) ? seconds: 0;
	minutes = (minutes >=0 && minutes <=59) ? minutes : 0;
	hours = (hours >= 0) ? hours : 0;
	setMilliseconds(milliseconds);
	setSeconds(seconds);
	setMinutes(minutes);
	setHours(hours);
}

istream& operator >>(istream& in, Time& time){
	int h, m, s, ms;
	cout << "--Time in format H:M:S:MS--\n";
	cout << "Enter hours: ";
	in >> h;
	cout << "Enter minutes: ";
	in >> m;
	cout << "Enter seconds: ";
	in >> s;
	cout << "Enter milliseconds: ";
	in >> ms;
	time.setTime(ms, s, m, h);
	return in;
}

ostream& operator <<(ostream& out, const Time& time){
	out << time.hours << ":" << time.minutes << ":" << time.seconds << ":" << time.milliseconds;
	return out;
}

Time& Time::operator +(const Time& timeArg) {
	int msRemainder = 0, sRemainder = 0, mRemainder = 0, hRemainder = 0;
	int newMs, newS, newM, newH;
	newMs = this->getMilliseconds() + timeArg.getMilliseconds();
	newS = this->getSeconds() + timeArg.getSeconds();
	newM = this->getMinutes() + timeArg.getMinutes();
	newH = this->getHours() + timeArg.getHours();
	if(newMs >= 1000){
		newMs -= 1000;
		sRemainder++;
	}
	if(newS >= 60){
		newS -= 60 + sRemainder;
		mRemainder++;
	}
	if(newM >= 60){
		newM -=60 + mRemainder;
		hRemainder++;
		newH += hRemainder;
	}
	Time* newTime = new Time(newMs, newS, newM, newH);
	return *newTime;

}

bool Time::operator ==(const Time& timeArg) const{
	bool result = (this->getHours() == timeArg.getHours()) &&
					(this->getMinutes() == timeArg.getMinutes()) &&
					(this->getSeconds() == timeArg.getSeconds()) &&
					(this->getMilliseconds() == timeArg.getMilliseconds());
	return result;
}

bool Time::operator <(const Time& timeArg) const{
	if(this->getHours() < timeArg.getHours()){
		return true;
	} else if((this->getHours() == timeArg.getHours()) &&
			(this->getMinutes() < timeArg.getMinutes())){
		return true;
	} else if((this->getMinutes() == timeArg.getMinutes()) &&
			(this->getSeconds() < timeArg.getSeconds())){
		return true;
	} else if((this->getSeconds() == timeArg.getSeconds()) &&
			(this->getMilliseconds() < timeArg.getMilliseconds())){
		return true;
	} else{
		return false;
	}
}

bool Time::operator>(const Time& timeArg) const{
	return !(*this == timeArg) && !(*this < timeArg);
}
