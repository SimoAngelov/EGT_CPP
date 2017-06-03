/*
 * Hall.cpp
 *
 *  Created on: Jun 3, 2017
 *      Author: SimoAngelov
 */

#include "Hall.h"
#include <iostream>
using std::cout;
using std::endl;
Hall::Hall(int id, const string& name):m_id(id), m_name(name) {
	// TODO Auto-generated constructor stub

}


int Hall::getId() const {
	return m_id;
}

void Hall::setId(int id) {
	m_id = id;
}

const string& Hall::getName() const {
	return m_name;
}

void Hall::setName(const string& name) {
	m_name = name;
}

ostream& operator << (ostream& out, const Hall& hall){
	out << "Hall ID: " << hall.getId() <<
			"\nHall Name: " << hall.getName();
	return out;
}
Hall::~Hall() {
	// TODO Auto-generated destructor stub
	cout << "Hall destructor called .address:" << this << endl;
}

