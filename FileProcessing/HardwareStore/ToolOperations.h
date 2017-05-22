/*
 * ToolOperations.h
 *
 *  Created on: 20.05.2017 г.
 *      Author: sim4o
 */

#ifndef TOOLOPERATIONS_H_
#define TOOLOPERATIONS_H_
#include <vector>
using std::vector;

#include "Tool.h"
class ToolOperations {
private :
	static vector<Tool> tools;
public:
	ToolOperations();
	static void addTool(const Tool&);
	static void removeTool(int id);
	static void showMostExpensiveTool();
	static void showLeastExpensiveTool();
	static void showLargerstQuantity();
	static void showSmalestQuantity();
	virtual ~ToolOperations();
};

#endif /* TOOLOPERATIONS_H_ */
