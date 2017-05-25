/*
 * Student.h
 *
 *  Created on: 25.05.2017 г.
 *      Author: sim4o
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include<vector>
using std::vector;
#include <iostream>
#include <string>
using std::string;
#include "Exam.h"
class Student {
private:
	string firstName;
	string lastName;
	string gender;
	string birthDate;
	string phone;
	string email;
	int course;
	string specialty;
	int facultyNumber;
	vector<Exam*> examList;

public:
	Student(const string& firstName = "", const string& lastName = "", const string& gender = "",
			const string& birthDate = "", const string& phone = "", const string& email = "",
			int course = 0, const string& specialty = "", int facultyNumber = 0, const vector<Exam*>& examList = vector<Exam*>());

	virtual ~Student();
	//getters
	const string& getBirthDate() const;
	int getCourse() const;
	const string& getEmail() const;
	const vector<Exam*>& getExamList() const;
	int getFacultyNumber() const;
	const string& getFirstName() const;
	const string& getGender() const;
	const string& getLastName() const;
	const string& getPhone() const;
	const string& getSpecialty() const;

	//setters
	void setBirthDate(const string& birthDate);
	void setCourse(int course);
	void setEmail(const string& email);
	void setExamList(const vector<Exam*>& examList);
	void setFacultyNumber(int facultyNumber);
	void setFirstName(const string& firstName);
	void setGender(const string& gender);
	void setLastName(const string& lastName);
	void setPhone(const string& phone);
	void setSpecialty(const string& specialty);

	//print
	void print() const;
};

#endif /* STUDENT_H_ */
