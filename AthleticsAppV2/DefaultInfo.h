/*
 * DefaultInfo.h
 *
 *  Created on: 9.05.2017 г.
 *      Author: sim4o
 */

#ifndef DEFAULTINFO_H_
#define DEFAULTINFO_H_

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>
using std::ostream;
using std::istream;

class DefaultInfo {
private:
	static vector<string> firstNamesVector;
	static vector<string> lastNamesVector;
	static vector<string> nationalitiesVector;
	static vector<string> disciplineNamesVector;
public:
	DefaultInfo();
	virtual ~DefaultInfo();
	static vector<string> getFirstNamesVector();
	static vector<string> getLastNamesVector();
	static vector<string> getNationalitiesVector();
	static vector<string> getDisciplineNamesVector();
};

#endif /* DEFAULTINFO_H_ */
