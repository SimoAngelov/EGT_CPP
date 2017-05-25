/*
 * Exam.h
 *
 *  Created on: 25.05.2017 г.
 *      Author: sim4o
 */

#ifndef EXAM_H_
#define EXAM_H_

#include<string>
using std::string;

class Exam {
private:
	string name;
	string lecturer;
	double grade;
public:
	Exam(const string& name = "", const string& lecturer = "", double grade = 0.0);

	virtual ~Exam();
	//getters
	double getGrade() const;
	const string& getLecturer() const;
	const string& getName() const;
	//setters
	void setGrade(double grade);
	void setLecturer(const string& lecturer);
	void setName(const string& name);
	void print() const;
};

#endif /* EXAM_H_ */
