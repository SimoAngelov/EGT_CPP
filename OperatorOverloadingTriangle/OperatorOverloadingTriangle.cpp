//============================================================================
// Name        : OperatorOverloadingTriangle.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Triangle.h"
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Triangle t1, t2;
	cin >> t1;
	cin.get();
	cin.clear();
	cin >> t2;
	if(t1 != t2){
		cout << "Triangles are not equal" << endl;
		cout << "T1: " << t1 << endl;
		cout << "T2: " << t2 << endl;
	} else {
		cout << "Triangles are equal" << endl;
		cout << "T1: " << t1 << endl;
		cout << "T2: " << t2 << endl;
	}
	return 0;
}
