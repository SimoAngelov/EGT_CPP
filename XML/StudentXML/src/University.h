/*
 * University.h
 *
 *  Created on: 25.05.2017 г.
 *      Author: sim4o
 */

#ifndef UNIVERSITY_H_
#define UNIVERSITY_H_
#include "pugixml.hpp"

#include <vector>
using std::vector;
#include "Student.h"
class University {
	static vector<Student*> students;
public:
	University();
	static void addStudent(Student&);
	static void showAllStudents();
	static void traverseXML();
	static vector<Student*> getStudents();
	virtual ~University();
};

#endif /* UNIVERSITY_H_ */
