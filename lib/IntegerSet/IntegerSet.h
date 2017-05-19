/*
 * IntegerSet.h
 *
 *  Created on: 19.05.2017 г.
 *      Author: sim4o
 */

#ifndef INTEGERSET_H_
#define INTEGERSET_H_

#include <iostream>
using std::ostream;
class IntegerSet {
	int set[101];
public:
	IntegerSet();
	IntegerSet(int*, int);
	virtual ~IntegerSet();

	bool isValidSet(const int*, int) const;
	bool isValidElement(int) const;
	bool isEmpty() const;
	void setEmptySet();
	const int* getSet() const;
	void setNewSet(const int*, int);
	void insertElement(int);
	void deleteElement(int);
	void printSet() const;
	IntegerSet& unionOfSets(const IntegerSet&);
	IntegerSet& intersectionOfSets(const IntegerSet&);
	bool isEqualTo(const IntegerSet&);
	IntegerSet& operator + (const IntegerSet&);
	void operator = (const IntegerSet&);
	bool operator == (const IntegerSet&);
	bool operator != (const IntegerSet&);
	friend ostream& operator << (ostream&, const IntegerSet&);

};

#endif /* INTEGERSET_H_ */
