/*
 * FileProcessing.cpp
 *
 *  Created on: 25.05.2017 г.
 *      Author: sim4o
 */

#include "FileProcessing.h"
#include <iostream>
using std::ios;
using std::cerr;
using std::endl;
using std::cout;
#include <fstream>
using std::ofstream;
#include <cstdlib>
using std::exit;
#include <iomanip>
using std::setw;
using std::right;
using std::left;
#include <vector>
using std::vector;
FileProcessing::FileProcessing() {
	// TODO Auto-generated constructor stub

}

void FileProcessing::traverseXML(){
	pugi::xml_document doc;
	if (!(doc.load_file("students.xml"))) {
		cout << "Error opening file" << endl;
	}
	pugi::xml_node students = doc.child("students");
	Student* student;
	Exam* exam;
	vector<Exam*> examList;

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

} // end function traverse

void FileProcessing::createTextFile(){
	vector<Student*> students = University::getStudents();
	ofstream outputStudent("stud.txt", ios::out);
	if(!outputStudent){
		cerr << "Error opening stud.txt" << endl;
		exit(-1);
	}
	vector<Student*>::iterator studIterator;
	int count = 0;
	for(studIterator = students.begin(); studIterator != students.end();
			++studIterator){
		outputStudent << "Student No." << ++count << " Info{";
		outputStudent << setw(17) << "\nFirst name:" << left << setw(17) << (*studIterator)->getFirstName() <<
				setw(17) << "\nLast name:" << left << setw(17) << (*studIterator)->getLastName() <<
				setw(17) << "\nGender:" << left << setw(17) << (*studIterator)->getGender() <<
				setw(17) << "\nBirthDate:" << left << setw(17) << (*studIterator)->getBirthDate() <<
				setw(17) << "\nPhone:" << left << setw(17) << (*studIterator)->getPhone() <<
				setw(17) << "\nEmail: " << left << setw(17) << (*studIterator)->getEmail() <<
				setw(17) << "\nCourse:" << left << setw(17) << (*studIterator)->getCourse() <<
				setw(17) << "\nSpecialty:" << left << setw(17) << (*studIterator)->getSpecialty() <<
				setw(17) << "\nFaculty Number:" << left << setw(17) << (*studIterator)->getFacultyNumber() << "\n";
		vector<Exam*>::const_iterator examIterator;
		vector<Exam*>::const_iterator examBegin = (*studIterator)->getExamList().begin();
		vector<Exam*>::const_iterator examEnd = (*studIterator)->getExamList().end();
		outputStudent << setw(17) << "Exam List{";
		int examCount = 0;
		for(examIterator = examBegin; examIterator != examEnd; ++examIterator){
			outputStudent << "\nExam No." << ++examCount << "{";
			outputStudent << setw(17) << "\nName:" << left << setw(17) << (*examIterator)->getName() <<
					setw(17) << "\nLecturer:" << left << setw(17) << (*examIterator)->getLecturer() <<
					setw(17) << "\nGrade:" << left << setw(17) << (*examIterator)->getGrade() << "\n";
			outputStudent << "}\n";
		}
		outputStudent << "\t}//End of Exam list\n}End of Student Info\n\n\n";
	}
	outputStudent.close();
} // end function create text file

FileProcessing::~FileProcessing() {
	// TODO Auto-generated destructor stub
}

