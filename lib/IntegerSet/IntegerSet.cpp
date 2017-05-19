//============================================================================
// Name        : IntegerSet.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "IntegerSet.h"
#include <iostream>
using std::endl;
using std::cout;
using std::cerr;

IntegerSet::IntegerSet():set({0}) {
	// TODO Auto-generated constructor stub;
}

IntegerSet::IntegerSet(int* newSet, int size){
	this->setNewSet(newSet, size);
}

const int* IntegerSet::getSet() const {
	return set;
}

bool IntegerSet::isValidSet(const int* newSet, int size) const{
	bool result = false;
	for(int i = 0; i < size; i++){
		if(this->isValidElement(newSet[i])){
			result = true;
		} else {
			result = false;
			break;
		}
	}
	return result;
}

bool IntegerSet::isValidElement(int element) const{
	return (element >= 0) && (element <= 100);
}

bool IntegerSet::isEmpty() const {
    bool result = true;
	for(int i = 0; i < 101; i++){
		if(set[i] != 0){
			result = false;
			break;
		} else{
			result = true;
		}
	}
	return result;
}


void IntegerSet::setEmptySet(){
	for(int i = 0; i < 101; i++){
		this->deleteElement(i);
	}
}

void IntegerSet::setNewSet(const int* newSet, int size){
	if(!this->isEmpty()){
		this->setEmptySet();
	}

	if(this->isValidSet(newSet, size)){
		for(int i = 0; i < size; i++){
			this->insertElement(newSet[i]);
		}
	} else {
		cerr << "New set contains invalid elements." << endl;
	}
}

void IntegerSet::insertElement(int element){
	if(this->isValidElement(element)){
		this->set[element] = 1;
	}
}

void IntegerSet::deleteElement(int element){
	if(this->isValidElement(element)){
		this->set[element] = 0;
	}
}

void IntegerSet::printSet() const {
	cout << "Set: ";
	if(!this->isEmpty()){
		for(int i = 0; i < 101; i++){
			if(set[i]!= 0){
				cout << i << "; ";
			}
		}
		cout << endl;
	} else {
		cout << "empty" << endl;
	}

}


IntegerSet::~IntegerSet() {
	// TODO Auto-generated destructor stub
}

IntegerSet& IntegerSet::unionOfSets(const IntegerSet& setArg) {
	IntegerSet* result = new IntegerSet();
	for(int i = 0; i < 101; i++){
		if((this->getSet()[i] != 0) || (setArg.getSet()[i] != 0)){
			result->insertElement(i);
		}
	}
	return *result;
}



IntegerSet& IntegerSet::intersectionOfSets(const IntegerSet& setArg) {
	IntegerSet* result = new IntegerSet();
	for(int i = 0; i < 101; i++){
		if((this->getSet()[i] == setArg.getSet()[i])
				&& (setArg.getSet()[i] != 0)){
			result->insertElement(i);
		}
	}
	return *result;
}

bool IntegerSet::isEqualTo(const IntegerSet& right){
	bool result;
	for(int i = 0; i < 101; i++){
		if(right.getSet()[i] == this->getSet()[i]){
			result = true;
		} else {
			result = false;
			break;
		}
	}
	return result;
}

IntegerSet& IntegerSet::operator +(const IntegerSet& right){
	return this->unionOfSets(right);
}

void IntegerSet::operator =(const IntegerSet& right){
	for(int i = 0; i < 101; i++){
		if(right.getSet()[i] != 0){
		this->insertElement(i);
	}
	}
}

bool IntegerSet::operator ==(const IntegerSet& right){
	return this->isEqualTo(right);
}

bool IntegerSet::operator !=(const IntegerSet& right){
	return !(*this == right);
}

ostream& operator << (ostream& out, const IntegerSet& set){
	set.printSet();
	return out;
}
