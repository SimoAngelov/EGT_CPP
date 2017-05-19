//============================================================================
// Name        : Rational.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Rational.h"

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Rational f1, f2;
	cin >> f1 >> f2;
	cout << f1 << endl;
	cout << f2 << endl;
	if(f1 == f2){
		cout << f1 << " is equal to " << f2 << endl;
	}
	if(f1 != f2){
		cout << f1 << " is  NOT equal to " << f2 << endl;
	}
	if(f1 < f2){
		cout << f1 << " is less than " << f2 << endl;
	}
	if(f1 > f2){
		cout << f1 << " is bigger than " << f2 << endl;
	}
	if(f1 <= f2){
		cout << f1 << " is less than or equal to " << f2 << endl;
	}
	if(f1 >= f2){
		cout << f1 << " is bigger than or equal to " << f2 << endl;
	}
	return 0;
}
