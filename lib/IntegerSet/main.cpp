/*
 * main.cpp
 *
 *  Created on: 19.05.2017 г.
 *      Author: sim4o
 */
#include <iostream>
using namespace std;
#include "IntegerSet.h"

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	IntegerSet set1, set2, set3;
	int array [20] = {1, 3, 5, 7, 9, 11, 13, 15, 17 ,19, 21,
			23, 25, 27, 29, 31, 33, 35, 37, 39};
	int array2[20] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24,
			26, 28, 30, 32, 34, 36, 38, 40};
	int array3[40] = {1, 2, 3, 4, 5, 6 , 7, 8, 9, 10,
			11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
			21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
			31, 32, 33, 34, 35 ,36, 37, 38, 39, 40};
	int array4[40] = {
			21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
			31, 32, 33, 34, 35 ,36, 37, 38, 39, 40,
			41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
			51, 52, 53, 54, 55, 56, 57, 58, 58, 60};
	int array5[2] = {200, 2012};
	cout << set1;
	cout << set2;
	cout << set3;
	set1.setNewSet(array, 20);
	set2.setNewSet(array2, 20);
	set3.setNewSet(array3, 40);
	cout << set1;
	cout << set2;
	cout << set3;
	IntegerSet set4, set5, set6, set7;
	set4 = set1 + set2;
	set4.printSet();

	cout << "Set4" << set4;
	if(set3 == set4){
		cout << "Set1+Set2: " << set4;
		cout << "Sets are equal" << endl;
	}
	set5.setNewSet(array4, 40);
	cout << set5;
	set6.setNewSet(array5, 40);
	set6 = set4.intersectionOfSets(set5);
	cout << "Set4 U Set5 = " << set6;
	return 0;
}




