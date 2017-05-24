//============================================================================
// Name        : LibraryFunctions.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "LibraryFunctions.h"
using namespace std;
#include <string>
#include <locale>
#include <sstream>

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	double amount;
	string currency;
	cout << "Enter amount ";
	cin >> amount;
	cout << "Enter currency: ";
	cin >> currency;
	string result;
	result = formatCurrency(currency, amount);
	cout << result;
	return 0;
}

template <typename T> string formatCurrency(const string& currency,
		T amount){
	ostringstream input;
	string sign = currency;
	string result;
	input << amount;
	result = input.str();

	while(sign.length() != 3){
		cout << "Currency must have three characters. Input a valid currency!";
		getline(cin, sign);
		cin.clear();
	}
	sign = camelCase(sign);

	result.append(" ");
	result.append(sign);
	return result;
}

string camelCase(string& input){
	string result = "";
	for(unsigned int i = 0; i < input.length(); i++){
		result.append(1, toupper(input[i]));
	}
	return result;
}
