//============================================================================
// Name        : AthleticsApp.cpp
// Author      : Simo Angelov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Time.h"
#include "Athlete.h"
#include "Discipline.h"
#include <vector>
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Athlete* athlete;
	Discipline* discipline;
	vector<Athlete*> athletes;
	vector<Discipline*> disciplines;

	for(int i = 0; i < 5; i++){
		athlete = new Athlete();
		athletes.push_back(athlete);
		discipline = new Discipline();
		disciplines.push_back(discipline);
	}
	for(int i = 0; i < 5; i++){
		cout << *athletes[i] << endl;
		cout << *disciplines[i] << endl;
		cout << endl;
	}
	delete athlete;
	athlete = NULL;
	delete discipline;
	discipline = NULL;
	return 0;
}
