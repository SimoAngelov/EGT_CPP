/*
 * Time.h
 *
 *  Created on: 5.05.2017 г.
 *      Author: sim4o
 */

#ifndef TIME_H_
#define TIME_H_
#include <iostream>
using std::ostream;
using std::istream;

class Time {
private:
	static int id;
	int milliseconds;
	int seconds;
	int minutes;
	int hours;

public:
	Time(int, int, int, int);
	Time();
	virtual ~Time();
	int getHours() const;
	void setHours(int hours);
	int getMilliseconds() const;
	void setMilliseconds(int miliseconds);
	int getMinutes() const;
	void setMinutes(int minutes);
	int getSeconds() const;
	void setSeconds(int seconds);
	void setTime(int, int, int, int);
	friend ostream& operator << (ostream&, const Time&);
	friend istream& operator >> (istream&, Time&);
	Time& operator+(const Time&);
	bool operator==(const Time&) const;
	bool operator<(const Time&) const;
	bool operator>(const Time&) const;
};

#endif /* TIME_H_ */
