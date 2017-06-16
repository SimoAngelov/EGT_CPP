/*
 * main.cpp
 *
 *  Created on: Jun 16, 2017
 *      Author: SimoAngelov
 */

#include <iostream>
#include "itos.h"
using namespace std;

int main() {
	cout << "enter number: " << endl; // prints !!!Hello World!!!
	int n;
	cin >> n;
	string strNum = itos(n);
	cout << "The number as a string is: " << strNum << endl;
	cout << "Enter a double: ";
	double d;
	cin >> d;
	strNum = itos(d);
	cout << "Double num is: " << strNum << endl;
	return 0;

}


