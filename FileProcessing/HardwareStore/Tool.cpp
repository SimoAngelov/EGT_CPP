/*
 * Tool.cpp
 *
 *  Created on: 17.05.2017 г.
 *      Author: sim4o
 */

#include "Tool.h"
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

#include <iomanip>
using std::setw;
using std::setprecision;
#include <string.h>

Tool::Tool() {
	// TODO Auto-generated constructor stub
	setId(0);
	setToolName("");
	setPrice(0.0);
	setQuantity(0);
}

Tool::Tool(int id, const string& name, double price, int quantity){
	setId(id);
	setToolName(name);
	setPrice(price);
	setQuantity(quantity);
}

int Tool::getId() const {
	return id;
}

void Tool::setId(int id) {
	this->id = id;
}

const string Tool::getToolName() const {
	return toolName;
}

void Tool::setToolName(const string& name) {
	 // copy at most 15 characters from string to lastName
	   const char *toolNameValue = name.data();
	   int length = name.size();
	   length = ( length < 15 ? length : 14 );
	   strncpy( toolName, toolNameValue, length );
	   toolName[ length ] = '\0'; // append null character to lastName
}

double Tool::getPrice() const {
	return price;
}

void Tool::setPrice(double price) {
	this->price = (price >= 0)? price : 1;
}

int Tool::getQuantity() const {
	return quantity;
}

void Tool::setQuantity(int quantity) {
	this->quantity = (quantity >= 0) ? quantity: 1;
}

Tool::~Tool() {
	// TODO Auto-generated destructor stub
}

ostream& operator << (ostream& out, const Tool& tool){
	out <<  left << setw(10) << tool.getId() << setw(15) << tool.getToolName()
		<< setw( 10 ) << setprecision( 2 ) << right << fixed
		<< showpoint << tool.getPrice() << setw(10) << tool.getQuantity() << endl;
	return out;
}
