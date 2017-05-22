/*
 * FileProcessing.cpp
 *
 *  Created on: 20.05.2017 г.
 *      Author: sim4o
 */
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::ios;
using std::left;
using std::right;
using std::showpoint;
using std::fixed;
using std::ostream;
using std::istream;

#include <cstdlib>
using std::exit;

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::fstream;

#include <iomanip>
using std::setw;
using std::setprecision;

#include "Tool.h"

 // enable user to input menu choice

int enterChoice()
{
 // display available options
cout << "\nEnter your choice" << endl
<< "1 - store a formatted text file of accounts" << endl
 << "called \"toolInfo.txt\" for printing" << endl <<
 "2 - update an account" << endl <<
 "3 - add a new account" << endl
 << "4 - delete an account" << endl
 << "5 - end program\n? ";

 int menuChoice;
cin >> menuChoice; // input menu selection from user
 return menuChoice;
 } // end function enterChoice


void createEmptyDatFile(){
	//create for reading and writing
	ofstream inOutTool("tool.dat", ios::out | ios::binary);

	//check if opens
	if(!inOutTool){
		cerr << "Error opening tool.dat" << endl;
		exit(1);
	}

	//fill it with 100 empty records
	Tool emptyTool;
	for(int i = 1; i <= 100; i++){
		cout << "Record " << i << endl;
		inOutTool.write(reinterpret_cast<char *> (&emptyTool), sizeof(Tool));
	}
	inOutTool.close();
}

void outputLine(ostream& out, const Tool& tool){
	out <<  left << setw(10) << tool.getId() << setw(15) << tool.getToolName()
		<< setw( 10 ) << setprecision( 2 ) << right << fixed
		<< showpoint << tool.getPrice() << setw(10) << tool.getQuantity() << endl;
}

int getRecordNumber(){
	int recordNumber;
	do{
		cout << "Enter a record number between 1 and 100" << endl;
		cin >> recordNumber;
	} while( recordNumber < 1 || recordNumber > 100);
	return recordNumber;
}
void createTextFile(fstream& readFromFile){ //fstream object argument
	//for inputing info from Tool.dat
	cout << "Printing" << endl;
	ofstream outToolTxt("toolInfo.txt", ios::out | ios::binary);

	if(!outToolTxt){
		cerr << "Error opening toolInfo.txt!" << endl;
		exit(1);
	}

	outToolTxt << left << setw(10) << "ID" << setw(15) << "Tool Name"
			<< right << setw(10) << "Price" << setw(10) << "Quantity" << endl;

	readFromFile.seekg(0); //set file pointer to beginning of file

	Tool tool;
	readFromFile.read(reinterpret_cast<char*> (&tool),
			sizeof(Tool)); // read first record from file

	while (!readFromFile.eof()){
		//write single non-empty record into toolInfo.txt
		if(tool.getId() != 0){
			outputLine(outToolTxt, tool);
			cout << "Writing" << endl;
			outputLine(cout, tool);
		}
		//read next record
		readFromFile.read(reinterpret_cast<char*> (&tool), sizeof(tool));
	}
}

void updateRecord(fstream& updateFile){
	int recordNumber = getRecordNumber();
	//position file pointer to the chosen record
	updateFile.seekg((recordNumber-1)*sizeof(Tool));

	Tool tool;
	updateFile.read(reinterpret_cast <char*> (&tool), sizeof(Tool));

	if(tool.getId() != 0){ //check if record contains information
		cout << "You chose: " << endl;
		outputLine(cout, tool);

		cout << "Choose (+) or (-) to change the price: ";
		double oldPrice = tool.getPrice();
		double newPrice;
		cin >> newPrice;
		tool.setPrice(oldPrice + newPrice);

		cout << "Choose (+) or (-) to change the quantity: ";
			double oldQuantity = tool.getQuantity();
			double newQuantity;
			cin >> newQuantity;
			tool.setPrice(oldQuantity + newQuantity);
		cout << "After changes: ";
		outputLine(cout, tool);

		updateFile.seekp((recordNumber-1) * sizeof(Tool));
		updateFile.write(reinterpret_cast <char*> (&tool), sizeof(Tool));

	} else{
		cout << "Tool record No." << recordNumber <<
				" has no information to be updated" << endl;
	}
}


void newRecord(fstream& insertInFile){
	cout << "Insert new record" << endl;
	int recordNumber = getRecordNumber();
	insertInFile.seekg((recordNumber - 1) * (sizeof(Tool)));

	Tool tool;
	insertInFile.read(reinterpret_cast <char*> (&tool), sizeof(Tool));
	if(tool.getId() == 0){ //the record is empty;
		string name;
		double price;
		int quantity;
		cout << "Enter tool name: ";
		cin >> name;
		cin.get();
		cin.clear();
		cout << "Enter price: ";
		cin >> price;
		cout << "Enter quantity: ";
		cin >> quantity;
		tool.setId(recordNumber);
		tool.setToolName(name);
		tool.setPrice(price);
		tool.setQuantity(quantity);
		//cout << tool.getToolName();
		cout << endl;
		cout << "Tool print method: " << endl;
		cout << tool << endl;
		cout << "Print using outputLine()" << endl;
		outputLine(cout, tool);
		//move pointer to correct record for writing
		insertInFile.seekp((recordNumber - 1) * sizeof(Tool));
		insertInFile.write(reinterpret_cast <char*> (&tool), sizeof(Tool));
	} else {
		cout << "Tool record No." << recordNumber << " already contains information" << endl;
	}

}

void deleteRecord(fstream& removeFromFile){
	cout << "Delete existing record." << endl;
	int recordNumber = getRecordNumber();

	removeFromFile.seekg((recordNumber - 1) * sizeof(Tool));

	Tool tool;
	removeFromFile.read(reinterpret_cast <char*> (&tool), sizeof(Tool));

	if(tool.getId() != 0){
		Tool blankTool;
		removeFromFile.seekp((recordNumber - 1) * sizeof(Tool));
		removeFromFile.write(reinterpret_cast <char*> (&blankTool), sizeof(Tool));
		cout << "Tool record No." << recordNumber << " is deleted";
	} else{
		cout << "Tool record No." << recordNumber << " is already empty." << endl;
	}
}

