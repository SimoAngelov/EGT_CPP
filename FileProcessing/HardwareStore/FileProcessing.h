/*
 * FileProcessing.h
 *
 *  Created on: 20.05.2017 г.
 *      Author: sim4o
 */

#ifndef FILEPROCESSING_H_
#define FILEPROCESSING_H_
#include <iostream>
using std::ostream;
#include <fstream>
using std::fstream;

int enterChoice();
void createEmptyDatFile();
void createTextFile(fstream&);
void outputLine(ostream&, const Tool&);
int getRecordNumber();
void updateRecord(fstream&);
void newRecord(fstream&);
void deleteRecord(fstream&);


#endif /* FILEPROCESSING_H_ */
