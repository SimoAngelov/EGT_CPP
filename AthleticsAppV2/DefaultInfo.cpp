/*
 * DefaultInfo.cpp
 *
 *  Created on: 9.05.2017 г.
 *      Author: sim4o
 */

#include "DefaultInfo.h"

DefaultInfo::DefaultInfo() {
	// TODO Auto-generated constructor stub
}

static const char* firstNameArr[] = { "Tom", "Jerry", "Goofy", "Donald",
		"Chuck", "Bruce", "Peter", "Homer", "Barney", "Mickey", "Frank",
		"Patrick", "Henry", "Stuart", "Steven", "Clark", "Jason", "Kenneth",
		"Nick", "Josh" }; //20 names
vector<string> DefaultInfo::firstNamesVector(firstNameArr, firstNameArr + 20);

static const char* lastNameArr[] = { "Mouse", "Cat", "Dog", "Duck", "Wayne",
		"Kent", "Norris", "Parker", "Johnson", "Springsteen", "Anderson",
		"Stark", "Smith", "Johnson", "Simpson", "Sinatra", "Bjorn", "Amdahl",
		"Samokov", "Petrikov", "Straustrub" }; //21 names
vector<string> DefaultInfo::lastNamesVector(lastNameArr, lastNameArr + 21);

static const char* nationalityArr[] = { "Bulgarian", "American", "Russian",
		"French", "English", "German", "Australian", "Chinese", "Japanese",
		"South Korean", "North Korean", "Swiss", "Italinan", "Spanish",
		"Portuguese", "Ukranian", "Estonian", "Lithuanian" }; //18 nationalities

vector<string> DefaultInfo::nationalitiesVector(nationalityArr,
		nationalityArr + 18);

static const char* disciplineNameArr[] =
		{ "60 metres", "100 metres", "200 metres", "400 metres", "800 metres",
				"1500 metres", "3000 metres", "5000 metres", "10,000 metres",
				"60 metres hurdles", "100 metres hurdles", "110 metres hurdles",
				"400 metres hurdles", "3000 metres steeplechase",
				"Half marathon (road)", "Marathon (road)",
				"20 kilometres race walk (road)",
				"50 kilometres race walk (road)", "Cross country running",
				"4×100 metres relay", "4×400 metres relay", "Pole vault",
				"High jump", "Long jump", "Triple jump", "Shot put",
				"Discus throw", "Javelin throw", "Pentathlon", "Heptathlon",
				"Decathlon" }; //32 disciplines
vector<string> DefaultInfo::disciplineNamesVector(disciplineNameArr,
		disciplineNameArr + 31);

DefaultInfo::~DefaultInfo() {
	// TODO Auto-generated destructor stub
}

vector<string> DefaultInfo::getFirstNamesVector() {
	return DefaultInfo::firstNamesVector;
}

vector<string> DefaultInfo::getLastNamesVector() {
	return DefaultInfo::lastNamesVector;
}

vector<string> DefaultInfo::getNationalitiesVector() {
	return DefaultInfo::nationalitiesVector;
}

vector<string> DefaultInfo::getDisciplineNamesVector() {
	return DefaultInfo::disciplineNamesVector;
}



