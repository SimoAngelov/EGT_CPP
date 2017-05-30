//============================================================================
// Name        : Complex.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Complex.h"
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Complex z1, z2, z3;
	cout << z1 << z2 << z3;
	cin >> z1;
	cin >> z2;
	cout << "z1 + z2 " << endl;
	z3 = z1 + z2;
	cout << z3;
	cout << "z1 - z2" << endl;
	z3 = z1 - z2;
	cout << z3;
	cout << "z1 * z2" << endl;
	z3 = z1 * z2;
	cout << z3;
	cout << "z1/z2" << endl;
	z3 = z1 / z2;
	cout << z3;


	return 0;
}
