// Fig. 9.9: Time.cpp
// Member-function definitions for class Time.
#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setfill;
using std::setw;

#include "Time.h" // include definition of class Time from Time.h
#include <ctime>
#include <string>
using std::string;
// Time constructor initializes each data member to zero;
// ensures that Time objects start in a consistent state
Time::Time( int hr, int min, int sec )
{
   setTime( hr, min, sec ); // validate and set time
} // end Time constructor

// set new Time value using universal time; ensure that
// the data remains consistent by setting invalid values to zero

Time::Time() {
	setCurrentTime();
}
void Time::setTime( int h, int m, int s )
{
   setHour( h ); // set private field hour
   setMinute( m ); // set private field minute
   setSecond( s ); // set private field second
} // end function setTime

// set hour value
void Time::setHour( int h )
{
   hour = ( h >= 0 && h < 24 ) ? h : 0; // validate hour
} // end function setHour

// set minute value
void Time::setMinute( int m )
{
   minute = ( m >= 0 && m < 60 ) ? m : 0; // validate minute
} // end function setMinute

// set second value
void Time::setSecond( int s )
{
   second = ( s >= 0 && s < 60 ) ? s : 0; // validate second
} // end function setSecond

// return hour value
int Time::getHour()
{
   return hour;
} // end function getHour

// return minute value
int Time::getMinute()
{
   return minute;
} // end function getMinute

// return second value
int Time::getSecond()
{
   return second;
} // end function getSecond

// print Time in universal-time format (HH:MM:SS)
void Time::printUniversal()
{
   cout << setfill( '0' ) << setw( 2 ) << getHour() << ":"
      << setw( 2 ) << getMinute() << ":" << setw( 2 ) << getSecond();
} // end function printUniversal



// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard()
{
   cout << ( ( getHour() == 0 || getHour() == 12 ) ? 12 : getHour() % 12 )
      << ":" << setfill( '0' ) << setw( 2 ) << getMinute()
      << ":" << setw( 2 ) << getSecond() << ( hour < 12 ? " AM" : " PM" );
} // end function printStandard

void Time::printYear() const {
	cout << "current year: " << currentTime->tm_year + 1900 << endl;
}

void Time::printMonth() const {
	string month = "";
	switch(getMonth()){
	case 0: month = "January"; break;
	case 1: month ="February"; break;
	case 2: month ="March"; break;
	case 3: month ="April"; break;
	case 4: month ="May"; break;
	case 5: month ="June"; break;
	case 6: month ="July"; break;
	case 7: month ="August"; break;
	case 8: month ="September"; break;
	case 9: month ="October"; break;
	case 10: month ="November"; break;
	case 11: month ="December"; break;
	default: month ="Invalid"; break;
	}
	cout << "Current month: " << month << endl;;
}

void Time::printDateOfMonth() const{
	cout << "Current date of month: " << getDateOfMonth() << endl;
}

void Time::printDate() const{
	cout << getDateOfMonth() << "." << getMonth() << "." << getYear() << endl;
}
void Time::setCurrentTime() {
	time_t ct = time(0);
	currentTime = localtime(&ct);
	setSecond(currentTime->tm_sec);
	setMinute(currentTime->tm_min);
	setHour(currentTime->tm_hour);
	setDateOfMonth(currentTime->tm_mday);
	setMonth(currentTime->tm_mon);
	setYear(currentTime->tm_year + 1900);
}

int Time::getMonth() const {
	return month;
}

void Time::setMonth(int month) {
	this->month = month;
}

int Time::getUnixTimeStamp() const {
	return unixTimeStamp;
}

void Time::setUnixTimeStamp() {
	this->unixTimeStamp = time(0);
}

int Time::getYear() const {
	return year;
}

void Time::setYear(int year) {
	this->year = year;
}

int Time::getDateOfMonth() const {
	return dateOfMonth;
}

void Time::setDateOfMonth(int dateOfMonth) {
	this->dateOfMonth = dateOfMonth;
}
