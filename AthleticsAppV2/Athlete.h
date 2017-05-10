/*
 * Athlete.h
 *
 *  Created on: 5.05.2017 г.
 *      Author: sim4o
 */

#ifndef ATHLETE_H_
#define ATHLETE_H_
#include "Time.h"
#include "DefaultInfo.h"
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>
using std::ostream;
using std::istream;

class Athlete {
private:
	static int id;
	string firstName;
	string lastName;
	Time bestTime;
	string nationality;
	void setNameVectors();
public:
	Athlete();
	Athlete(const string&, const string&, const Time&, const string&);
	Athlete(const Athlete&);
	virtual ~Athlete();
	const Time& getBestTime() const;
	void setBestTime(const Time& bestTime);
	void setRandomBestTime();
	const string& getFirstName() const;
	void setFirstName(const string& firstName);
	const string& getLastName() const;
	void setLastName(const string& lastName);
	const string& getNationality() const;
	void setNationality(const string& nationality);
	friend istream& operator >>(istream&, Athlete&);
	friend ostream& operator <<(ostream&, const Athlete&);

	bool operator <(const Athlete& athleteArg) const;
	bool operator >(const Athlete& athleteArg) const;
	bool operator ==(const Athlete& athleteArg) const;

};

#endif /* ATHLETE_H_ */
