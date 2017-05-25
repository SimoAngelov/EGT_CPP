/*
 * FileProcessing.h
 *
 *  Created on: 25.05.2017 г.
 *      Author: sim4o
 */

#ifndef FILEPROCESSING_H_
#define FILEPROCESSING_H_
#include "University.h"
#include "pugixml.hpp"
class FileProcessing {
public:
	FileProcessing();
	static void traverseXML();
	static void createTextFile();
	virtual ~FileProcessing();
};

#endif /* FILEPROCESSING_H_ */
