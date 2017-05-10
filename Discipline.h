/*
 * Discipline.h
 *
 *  Created on: 9.05.2017 г.
 *      Author: sim4o
 */

#ifndef DISCIPLINE_H_
#define DISCIPLINE_H_
#include "Time.h"
#include "DefaultInfo.h"
#include <string>
using std::string;
#include <vector>
using std::vector;
class Discipline {
private:
	static int id;
	string name;
	Time worldRecord;
	Time competitionRecord;
	static vector<string> disciplineNamesVector;

public:
	Discipline();
	Discipline(const string&, const Time&, const Time&);
	Discipline(const Discipline&);
	virtual ~Discipline();
	const Time& getCompetitionRecord() const;
	void setCompetitionRecord(const Time& competitionRecord);
	const string& getName() const;
	void setName(const string& name);
	const Time& getWorldRecord() const;
	void setWorldRecord(const Time& worldRecord);
	friend ostream& operator << (ostream&, const Discipline&);
	friend istream& operator >> (istream&, Discipline&);
	Discipline& operator =(const Discipline&);
};

#endif /* DISCIPLINE_H_ */
