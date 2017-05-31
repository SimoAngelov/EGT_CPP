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
#include <cmath>
#include <iomanip>

void TestCurrency();
void TestRound();
void TestDivide();
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	TestRound();
	//TestDivide();
	return 0;
}

template <typename T> string FormatCurrency(const string& currency,
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

double RoundDouble(double dNum, int iDecimalPlaces){
	int iBeforeComma = dNum;
	double dAfterComma = dNum - iBeforeComma;
	int iPowOfTen = (iDecimalPlaces > 0) ? (iDecimalPlaces - 1):
			(iDecimalPlaces);
	if(iPowOfTen >= 0)
	{
		structDiv structNum = Divide(iBeforeComma, pow(10,iPowOfTen));
		if(structNum.remainder >= pow(10,iPowOfTen) / 2)
		{
			dNum = structNum.quotient;
			dNum += 1;
		} else
		{
			dNum = structNum.quotient;
		}

		for(int i = 1; i <= iPowOfTen; i++)
		{
			dNum *= 10;
		}
		dNum += ((dAfterComma * 100) >= 50.0) ? 1 : 0;
	}
	else
	{
		long lNum = dAfterComma * pow(10, -1*iPowOfTen);
		dNum = round(lNum)/ pow(10, -1 * iPowOfTen);
	}
	return dNum;
}

structDiv Divide (int iNum1, int iNum2){
	structDiv structNum;
	structNum.quotient = iNum1 / iNum2;
	structNum.remainder = iNum1 % iNum2;
	return structNum;
}


//test

void TestCurrency(){
	double amount;
	string currency;
	cout << "Enter amount ";
	cin >> amount;
	cout << "Enter currency: ";
	cin >> currency;
	string result;
	result = FormatCurrency(currency, amount);
	cout << result;
}

void TestRound(){
	cout << "Enter a double" << endl;
	double dNum;
	cin >> dNum;
	cout << "Most Original DNUm: " << dNum << endl;
	cout << "Enter number of decimal places before comma" << endl;
	int iBeforeComma;
	cin >> iBeforeComma;
	cout << "Original number: " << dNum << endl;
	dNum = RoundDouble(dNum, iBeforeComma);
	cout << "Rounded number: " << dNum << endl;
}

void testDivide()
{
	int iNum1 = 0, iNum2 = 0;
	cout << "Enter first int " << endl;
	cin >> iNum1;
	cout << "Enter second int " << endl;
	cin >> iNum2;
	structDiv result = Divide(iNum1, iNum2);
}
