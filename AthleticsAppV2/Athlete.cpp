/*
 * Athlete.cpp
 *
 *  Created on: 5.05.2017 г.
 *      Author: sim4o
 */

#include "Athlete.h"
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
#include <cstdlib>

#include <ctime>

int Athlete::id = 0;
Athlete::Athlete():bestTime() {
	// TODO Auto-generated constructor stub
	srand(time(0) + id);
	setFirstName(DefaultInfo::getFirstNamesVector()[rand() % 20]);
		setLastName(DefaultInfo::getLastNamesVector()[rand() % 21]);
		setNationality(DefaultInfo::getNationalitiesVector()[rand() % 18]);
		id++;
}
Athlete::Athlete(const string& firstName, const string& lastName,
		const Time& bestTime, const string& nationality):bestTime(bestTime){
	setFirstName(firstName);
	setLastName(lastName);
	setNationality(nationality);
	id++;
}

const Time& Athlete::getBestTime() const {
	return bestTime;
}

void Athlete::setBestTime(const Time& bestTime) {
	this->bestTime = bestTime;
}

const string& Athlete::getFirstName() const {
	return firstName;
}

void Athlete::setFirstName(const string& firstName) {
	this->firstName = firstName;
}

const string& Athlete::getLastName() const {
	return lastName;
}

void Athlete::setLastName(const string& lastName) {
	this->lastName = lastName;
}

const string& Athlete::getNationality() const {
	return nationality;
}

void Athlete::setNationality(const string& nationality) {
	this->nationality = nationality;
}

istream& operator >> (istream& in, Athlete& athlete){
	cout << "--Athlete Info -- " << endl;
	cout << "Enter first name: ";
	in >> athlete.firstName;
	cout << "Enter last name: ";
	in >> athlete.lastName;
	in >> athlete.bestTime;
	cout << "Enter nationality: ";
	in >> athlete.nationality;
	return in;
}

ostream& operator << (ostream& out, const Athlete& athlete){
	out << "--Athlete Info--\n" <<
			"First name: " << athlete.getFirstName() <<
			"\nLast name: " << athlete.getLastName() <<
			"\nBest time: " << athlete.getBestTime() <<
			"\nNationality: " << athlete.getNationality();
	return out;
}


Athlete::~Athlete() {
	// TODO Auto-generated destructor stub
}

Athlete::Athlete(const Athlete& oldAthlete) {
	this->setFirstName(oldAthlete.getFirstName());
	this->setLastName(oldAthlete.getLastName());
	this->setBestTime(oldAthlete.getBestTime());
	this->setNationality(oldAthlete.getNationality());
}

void Athlete::setRandomBestTime() {
	Time *time = new Time();
	this->setBestTime(*time);
	delete time;
	time = NULL;
}

bool Athlete::operator <(const Athlete& athleteArg) const {
	return this->getBestTime() < athleteArg.getBestTime();
}

bool Athlete::operator >(const Athlete& athleteArg) const {
	return this->getBestTime() > athleteArg.getBestTime();
}


bool Athlete::operator ==(const Athlete& athleteArg) const{
	return this->getBestTime() == athleteArg.getBestTime();
}
