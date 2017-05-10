/*
 * Discipline.cpp
 *
 *  Created on: 9.05.2017 г.
 *      Author: sim4o
 */

#include "Discipline.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using std::endl;
using std::cout;
int Discipline::id = 0;

Discipline::Discipline() :
		worldRecord(), competitionRecord() {
	// TODO Auto-generated constructor stub
	srand(time(0) + id);
	setName(DefaultInfo::getDisciplineNamesVector()[rand() % 31]);
	id++;
}
Discipline::Discipline(const string& name, const Time& worldRecord,
		const Time& competitionRecord) :
		worldRecord(worldRecord), competitionRecord(competitionRecord) {
	setName(name);
	id++;
}

Discipline::Discipline(const Discipline& old_D) {
	this->setName(old_D.getName());
	this->setWorldRecord(old_D.getWorldRecord());
	this->setCompetitionRecord(old_D.getCompetitionRecord());
}

Discipline::~Discipline() {
	// TODO Auto-generated destructor stub
}

const Time& Discipline::getCompetitionRecord() const {
	return competitionRecord;
}

void Discipline::setCompetitionRecord(const Time& competitionRecord) {
	this->competitionRecord = competitionRecord;
}

const string& Discipline::getName() const {
	return name;
}

void Discipline::setName(const string& name) {
	this->name = name;
}

const Time& Discipline::getWorldRecord() const {
	return worldRecord;
}

void Discipline::setWorldRecord(const Time& worldRecord) {
	this->worldRecord = worldRecord;
}

ostream& operator <<(ostream& out, const Discipline& d) {
	out << "--Discipline Info--\n" << "Name: " << d.getName() <<
	"\nWorld Record: " << d.getWorldRecord() << "\nCompetition Record: "
			<< d.getCompetitionRecord();
	return out;
}

istream& operator >>(istream& in, Discipline& d) {
	cout << "--Input Info for Discipline--" << endl;
	cout << "Enter name: ";
	in >> d.name;
	cout << "Enter competition record: ";
	in >> d.competitionRecord;
	return in;
}

Discipline& Discipline::operator =(const Discipline& old_D) {
	this->setName(old_D.getName());
	this->setWorldRecord(old_D.getWorldRecord());
	this->setCompetitionRecord(old_D.getCompetitionRecord());
	return *this;
}

