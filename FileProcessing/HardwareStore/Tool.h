/*
 * Tool.h
 *
 *  Created on: 17.05.2017 г.
 *      Author: sim4o
 */

#ifndef TOOL_H_
#define TOOL_H_
#include <string>
using std::string;
#include <iostream>
using std::ostream;
class Tool {
private:
	int id;
	char toolName[15];
	double price;
	int quantity;

public:
	Tool();
	Tool(int, const string&, double, int);
	virtual ~Tool();
	int getId() const;
	void setId(int id);
	const string getToolName() const;
	void setToolName(const string& name);
	double getPrice() const;
	void setPrice(double price);
	int getQuantity() const;
	void setQuantity(int quantity);
	friend ostream& operator << (ostream&, const Tool&);
};

#endif /* TOOL_H_ */
