/*
 * Exam.cpp
 *
 *  Created on: 25.05.2017 г.
 *      Author: sim4o
 */

#include "Exam.h"
#include <iostream>
using std::cout;
using std::endl;
Exam::Exam(const string& name, const string& lecturer, double grade) {
	// TODO Auto-generated constructor stub
	setName(name);
	setLecturer(lecturer);
	setGrade(grade);
}

//getters
double Exam::getGrade() const {
	return grade;
}

const string& Exam::getLecturer() const {
	return lecturer;
}

const string& Exam::getName() const {
	return name;
}

//setters
void Exam::setGrade(double grade) {
	this->grade = grade;
}

void Exam::setLecturer(const string& lecturer) {
	this->lecturer = lecturer;
}

void Exam::setName(const string& name) {
	this->name = name;
}

void Exam::print() const{
	cout << "--Exam Info--" << endl;
	cout << "Name: " << this->getName() << endl;
	cout << "Lecturer: " << this->getLecturer() << endl;
	cout << "Grade: " << this->getGrade() << endl;
}
Exam::~Exam() {
	// TODO Auto-generated destructor stub
}

