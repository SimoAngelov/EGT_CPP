//============================================================================
// Name        : CinemaProject.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Cinema.h"
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Cinema cinema("cinema1.xml");
	for(int i = 0; (int) i < cinema.getScreenings().size(); ++i)
	{
		cout << *cinema.getScreenings()[i] << endl;
	}
//	cout << "Expensive screeningL " << cinema.extremeScreeningProfit(true) << endl;
//	cout << "Cheap screening: " << cinema.extremeScreeningProfit(false) << endl;



	return 0;
}
