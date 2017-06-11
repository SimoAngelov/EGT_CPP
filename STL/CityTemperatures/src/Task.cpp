/*
 * Task.cpp
 *
 *  Created on: 11.06.2017 г.
 *      Author: sim4o
 */
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "UserDefinedFunctions.h"
#include "MapOperations.h"

const string g_keyName = "City";
const string g_valName = "Temperature";

void testSort1(cityToTemps& cityTempsMap)
{
	cout << "map<string, vector<int> before sort" << endl;
	PrintMapVector(cityTempsMap, g_keyName, g_valName);
	cout << "\nmap<string, vector<int> after sort" << endl;
	SortMapByVector(cityTempsMap);
	PrintMapVector(cityTempsMap, "City", "Temperature");
}

void testSort2(const cityToTemp& cityTempMap)
{
	cout << "multimap<string, int> before sort " << endl;
	PrintMultimap(cityTempMap, g_keyName, g_valName);
	cout << "\nafter sort (vector<pair<string, int> >): " << endl;
	VCityTempPairs cityTempPairs = SortMultimapByValue(cityTempMap);
	PrintVectorOfPairs(cityTempPairs, g_keyName, g_valName);
}

void task1(const VCityTempPairs& cityTempPairs)
{
	cout << "\n1. В кой град е било най-топло: град/градове" << endl;
	VCityTempPairs citiesWithHighestTemp = CitiesWithHighestTemp(cityTempPairs);
	PrintVectorOfPairs(citiesWithHighestTemp, g_keyName, g_valName);
	cout << endl;
}

void task2(const cityToTemps& cityTemps)
{
	cout << "\n2. В кой град е било най-студено, за всеки от градовете" << endl
			<< "град -> най-ниска температура" << endl;
	VCityTempPairs coldestTempPerCities = ColdestTempPerCities(cityTemps);
	PrintVectorOfPairs(coldestTempPerCities, g_keyName, g_valName);
	cout << endl;
}

void task3(const VCityTempPairs& cityTempPairs)
{
	cout << "\n3. петте най-високи температурии за страната: град - температура"
			<< endl;
	//pass the sorted vector of city-temp pairs as an argument
	VCityTempPairs top5HottestCities = Top5HottestCities(cityTempPairs);
	PrintVectorOfPairs(top5HottestCities, g_keyName, g_valName);
}

void task4(const cityToTemps& cityTempsVect)
{
	//task4
	cout
			<< "\n4. Kолко пъти във всеки град е било повече от 15 градуса: град-бройка"
			<< endl;
	VCitiesToCounts timesAbove15DegPerCity = TimesAbove15DegPerCity(
			cityTempsVect);
	PrintVectorOfPairs(timesAbove15DegPerCity, g_keyName, g_valName);
	cout << endl;

}

void task5(const VCityTempPairs& cityTemp)
{
	//task5
	cout << "5. Kолко дни е било по-малко или равно на 10 градуса, " << endl
			<< "колко дни е било по-малко или равно на 20 градуса, " << endl
			<< "колко дни е било над 20: брой дни-гранична температура\n" << endl;
	VDaysToTemps daysToTemp = DaysToTempFunc(cityTemp);
	cout << daysToTemp[0].first << " days with a temperature below or equal to "
			<< daysToTemp[0].second << " degrees." << endl;
	cout << daysToTemp[1].first
			<< " days with a temperature above 10 and below or equal to "
			<< daysToTemp[1].second << " degrees." << endl;
	cout << daysToTemp[2].first << " days with a temperature above "
			<< daysToTemp[1].second << " degrees." << endl;
}
