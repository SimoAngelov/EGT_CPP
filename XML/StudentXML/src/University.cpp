/*
 * University.cpp
 *
 *  Created on: 25.05.2017 г.
 *      Author: sim4o
 */

#include "University.h"
#include <iostream>
using std::cout;
using std::endl;
vector<Student*> University::students;
University::University() {
	// TODO Auto-generated constructor stub

}

void University::addStudent(Student& student) {
	University::students.push_back(&student);
}

void University::showAllStudents() {
	for (unsigned int i = 0; i < University::students.size(); i++) {
		University::students[i]->print();
		cout << endl;
	}
}

vector<Student*> University::getStudents() {
	return University::students;
}
University::~University() {
	// TODO Auto-generated destructor stub
}

