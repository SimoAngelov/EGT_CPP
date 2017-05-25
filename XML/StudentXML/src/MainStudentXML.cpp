//============================================================================
// Name        : StudentXML.cpp
// Author      : 
// Version     :
// Copyleft   : Your copyleft notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "University.h"
#include "FileProcessing.h"
#include <fstream>
#include <cstdlib>
#include <iomanip>

int main() {
	FileProcessing::traverseXML();
	University::showAllStudents();
	FileProcessing::createTextFile();
	return 0;
}
