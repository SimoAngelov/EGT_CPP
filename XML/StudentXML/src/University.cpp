/*
 * University.cpp
 *
 *  Created on: 25.05.2017 г.
 *      Author: sim4o
 */

#include "University.h"
#include "pugixml.hpp"
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

void University::traverseXML() {
	pugi::xml_document doc;
	if (!(doc.load_file("students.xml"))) {
		cout << "Error opening file" << endl;
	}
	pugi::xml_node students = doc.child("students");
	Student* student;
	Exam* exam;
	vector<Exam*> examList;

//	for (pugi::xml_node currentStudent = students.child("students:student");
//			currentStudent;
//			currentStudent = student.next_sibling("students:student")) {
//		std::cout << student.child("students:firstName").text().as_string()
//				<< "\n";
//
//		for (pugi::xml_node exams = student.child("exams:examList"); exams;
//				exams = exams.next_sibling("exams:exam")) {
//			for (pugi::xml_node exam = exams.child("exams:exam"); exam; exam =
//					exam.next_sibling("exams:exam")) {
//				std::cout << "\t" << exam.child("exams:name").text().as_string()
//						<< "\n";
//			}
//		}
//	}

	for (pugi::xml_node currentStudent = students.child("students:student");
			currentStudent;
			currentStudent = currentStudent.next_sibling("students:student")) {
		string firstName = currentStudent.child("students:firstName").text().as_string();
		string lastName = currentStudent.child("students:lastName").text().as_string();
		string gender = currentStudent.child("students:gender").text().as_string();
		string birthDate = currentStudent.child("students:birthdate").text().as_string();
		string phone = currentStudent.child("students:phone").text().as_string();
		string email = currentStudent.child("students:email").text().as_string();
		int course = currentStudent.child("students:course").text().as_int();
		string specialty = currentStudent.child("students:specialty").text().as_string();
		int facultyNumber = currentStudent.child("students:facultyNumber").text().as_int();
		//Loop the exams of the current student
		for(pugi::xml_node currentExamList =
				currentStudent.child("exams:examList");
				currentExamList;
				currentExamList = currentExamList.next_sibling("exams:examList")){

				// loop through the elements of one exam
			for(pugi::xml_node currentExam = currentExamList.child("exams:exam");
					currentExam;
					currentExam = currentExam.next_sibling("exams:exam")){

				string name = currentExam.child("exams:name").text().as_string();
				string lecturer = currentExam.child("exams:lecturer").text().as_string();
				double grade = currentExam.child("exams:grade").text().as_double();
				exam = new Exam(name, lecturer, grade);
				examList.push_back(exam);
			} // second inner for
		} // inner for
		student = new Student(firstName, lastName, gender, birthDate,
				phone, email, course, specialty, facultyNumber, examList);
		University::addStudent(*student);
		int size = examList.size();
		examList.erase(examList.begin(), examList.begin() + size );
	} // outer for

	exam = NULL;
	delete exam;
	student = NULL;
	delete student;
} //function traverse

vector<Student*> University::getStudents() {
	return University::students;
}
University::~University() {
	// TODO Auto-generated destructor stub
}

