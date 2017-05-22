//============================================================================
// Name        : HardwareStore_FileExercise.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Tool.h"
#include "ToolOperations.h"
#include "FileProcessing.h"
#include <cstdlib>
#include <iostream>
using namespace std;

enum Choices{PRINT = 1, UPDATE, NEW, DELETE, END};
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	createEmptyDatFile();

	fstream inOutTool("tool.dat", ios::in | ios::out);
	if(!inOutTool){
		cerr << "Error opening tool.dat!" << endl;
		exit (1);
	}
	int choice;
	// enable user to specify action
	while ( ( choice = enterChoice() ) != END )
	{
	switch ( choice ) {
	case PRINT: // create text file from record file
		createTextFile(inOutTool);
	break;
	case UPDATE: // update record
	updateRecord( inOutTool );
	break;
	case NEW: // create record
	newRecord( inOutTool );
	break;
	case DELETE: // delete existing record
	deleteRecord( inOutTool);
	break;
	default: // display error if user does not select valid choice
	cerr << "Incorrect choice" << endl;
	break;
	} // end switch

	inOutTool.clear(); // reset end-of-file indicator
	} // end while
	inOutTool.close();
	return 0;
}
