//============================================================================
// Name        : CityTemperatures.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "UserDefinedFunctions.h"
#include "MapOperations.h"
#include "Tasks.h"

const string g_keyName = "City";
const string g_valName = "Temperature";

int main()
{
	int arr1[5] =
	{ 12, 34, 17, 23, 23 };
	int arr2[5] =
	{ 15, 17, 19, 32, 12 };
	int arr3[4] =
	{ 34, 22, 8, 9 };

	//vector of temperatures
	vector<int> sofiaTemp(arr1, arr1 + 5);
	vector<int> plovdivTemp(arr2, arr2 + 5);
	vector<int> varnaTemp(arr3, arr3 + 4);

	//map of city-temperature vectors
	cityToTemps cityTempsMap;

	//initialize the map of city-temperature vectors
	cityTempsMap["Sofia"] = sofiaTemp;
	cityTempsMap["Plovdiv"] = plovdivTemp;
	cityTempsMap["Varna"] = varnaTemp;

	//sort the map of city-temperature vectors
	SortMapByVector(cityTempsMap);

	//map of city-temp pairs;
	cityToTemp cityTempMap;

	//push the temperatures from sofia, plovdiv and varna into a map of city-temp pairs
	cityTempMap = ValueFromVectorToElements(cityTempsMap);

	//sort the map of city-temp pairs
	VCityTempPairs cityTempPairs = SortMultimapByValue(cityTempMap);

	bool exitMenu = false;
	while (!exitMenu)
	{
		cout << "Press 0 to view options." << endl;
		cout << "Choose an option between 1 and 5" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "1. В кой град е било най-топло: град/градове" << endl
					<< "2. В кой град е било най-студено, за всеки от градовете" << endl
					<< "град -> най-ниска температура" << endl
					<< "3. петте най-високи температурии за страната: град - температура"
					<< endl
					<< "4. Kолко пъти във всеки град е било повече от 15 градуса: град-бройка"
					<< endl
					<< "5. Kолко дни е било по-малко или равно на 10 градуса, "
					<< endl << "колко дни е било по-малко или равно на 20 градуса, "
					<< endl
					<< "колко дни е било над 20: брой дни-гранична температура"
					<< endl;
			break;
		case 1:
			//task1
			task1(cityTempPairs);
			break;
		case 2:
			//task2
			task2(cityTempsMap);
			break;
		case 3:
			//task3
			task3(cityTempPairs);
			break;
		case 4:
			//task4
			task4(cityTempsMap);
			break;
		case 5:
			//task5
			task5(cityTempPairs);
			break;
		default:
			cout << "Exiting menu. Have a nice day!" << endl;
			exitMenu = true;
		}
	}




//	//task5
//	cout << "task5" << endl;
//	VDaysToTemps daysToTemp = DaysToTempFunc(tempCityPairs);
//	cout << daysToTemp[0].first << " days with a temperature below or equal to "
//			<< daysToTemp[0].second << " degrees." << endl;
//	cout << daysToTemp[1].first
//			<< " days with a temperature above 10 and below or equal to "
//			<< daysToTemp[1].second << " degrees." << endl;
//	cout << daysToTemp[2].first << " days with a temperature above "
//			<< daysToTemp[1].second << " degrees." << endl;
	return 0;
}

