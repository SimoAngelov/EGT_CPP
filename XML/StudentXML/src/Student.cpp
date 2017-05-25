/*
 * Student.cpp
 *
 *  Created on: 25.05.2017 г.
 *      Author: sim4o
 */

#include "Student.h"
#include <iostream>
using std::cout;
using std::endl;
Student::Student(const string& firstName, const string& lastName, const string& gender,
		const string& birthDate, const string& phone, const string& email,
		int course, const string& specialty, int facultyNumber, const vector<Exam*>& examList) {
	// TODO Auto-generated constructor stub
	setFirstName(firstName);
	setLastName(lastName);
	setGender(gender);
	setBirthDate(birthDate);
	setPhone(phone);
	setEmail(email);
	setCourse(course);
	setSpecialty(specialty);
	setFacultyNumber(facultyNumber);
	setExamList(examList);
}

//getters
const string& Student::getBirthDate() const {
	return birthDate;
}

int Student::getCourse() const {
	return course;
}

const string& Student::getEmail() const {
	return email;
}

const vector<Exam*>& Student::getExamList() const {
	return examList;
}

int Student::getFacultyNumber() const {
	return facultyNumber;
}

const string& Student::getFirstName() const {
	return firstName;
}

const string& Student::getGender() const {
	return gender;
}

const string& Student::getLastName() const {
	return lastName;
}

const string& Student::getPhone() const {
	return phone;
}

const string& Student::getSpecialty() const {
	return specialty;
}


//setters
void Student::setBirthDate(const string& birthDate) {
	this->birthDate = birthDate;
}

void Student::setCourse(int course) {
	this->course = course;
}

void Student::setEmail(const string& email) {
	this->email = email;
}

void Student::setExamList(const vector<Exam*>& examList) {
	this->examList = examList;
}

void Student::setFacultyNumber(int facultyNumber) {
	this->facultyNumber = facultyNumber;
}

void Student::setFirstName(const string& firstName) {
	this->firstName = firstName;
}

void Student::setGender(const string& gender) {
	this->gender = gender;
}

void Student::setLastName(const string& lastName) {
	this->lastName = lastName;
}

void Student::setPhone(const string& phone) {
	this->phone = phone;
}

void Student::setSpecialty(const string& specialty) {
	this->specialty = specialty;
}

//print

void Student::print() const {
	cout << "--Student Info--" << endl;
	cout << "First name: " << this->getFirstName() << endl;
	cout << "Last name: " << this->getLastName() << endl;
	cout << "Gender: " << this->getGender() << endl;
	cout << "Birthdate: " << this->getBirthDate() << endl;
	cout << "Phone: " << this->getPhone() << endl;
	cout << "E-mail: " << this->getEmail() << endl;
	cout << "Course: " << this->getCourse() << endl;
	cout << "Specialty: " << this->getSpecialty() << endl;
	cout << "Faculty Number: " << this->getFacultyNumber() << endl;
	cout << "Exam List: " << endl;
	for(unsigned int i = 0; i < this->getExamList().size(); i++){
		this->getExamList()[i]->print();
	}
	cout << "End of exam list@" << endl;
}

Student::~Student(){
	// TODO Auto-generated destructor stub
}

