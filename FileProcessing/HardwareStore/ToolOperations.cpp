/*
 * ToolOperations.cpp
 *
 *  Created on: 20.05.2017 г.
 *      Author: sim4o
 */

#include "ToolOperations.h"
#include <iostream>
using std::cout;
using std::endl;

vector<Tool> ToolOperations::tools;
ToolOperations::ToolOperations() {
	// TODO Auto-generated constructor stub

}

void ToolOperations::addTool(const Tool& tool){
	tools.push_back(tool);
}

void ToolOperations::showLargerstQuantity(){
	Tool* result;
	int quantity = tools[0].getQuantity();
	for(unsigned int i = 1; i < tools.size(); i++){
		if(tools[i].getQuantity() > quantity){
			quantity = tools[i].getQuantity();
			result = &tools[i];
		}
	}
	cout << "Tool with largest quantity: " << result << endl;
}
ToolOperations::~ToolOperations() {
	// TODO Auto-generated destructor stub
}

