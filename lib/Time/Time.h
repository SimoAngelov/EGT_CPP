// Fig. 9.8: Time.h
// Declaration of class Time.
// Member functions defined in Time.cpp.

// prevent multiple inclusions of header file
#ifndef TIME_H
#define TIME_H

#include <ctime>
// Time abstract data type definition
class Time {

public:
	Time(int, int, int);
	Time(); // default constructor to current time;

	// set functions
	void setTime(int, int, int); // set hour, minute, second
	void setHour(int); // set hour (after validation)
	void setMinute(int); // set minute (after validation)
	void setSecond(int); // set second (after validation)
	void setCurrentTime();

	// get functions
	int getHour(); // return hour
	int getMinute(); // return minute
	int getSecond(); // return second
	int getMonth() const;
	void setMonth(int month);
	int getUnixTimeStamp() const;
	void setUnixTimeStamp();
	int getYear() const;
	void setYear(int year);
	int getDateOfMonth() const;
	void setDateOfMonth(int dateOfMonth);

	void printUniversal(); // output time in universal-time format
	void printStandard(); // output time in standard-time format
	void printDate() const;
	void printYear() const;
	void printMonth() const;
	void printDateOfMonth() const;


private:
	int hour; // 0 - 23 (24-hour clock format)
	int minute; // 0 - 59
	int second; // 0 - 59
	int dateOfMonth;
	int month;
	int year;
	int unixTimeStamp;
	tm* currentTime;
};
// end class Time

#endif
