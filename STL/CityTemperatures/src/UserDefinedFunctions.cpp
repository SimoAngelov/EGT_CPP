/*
 * UserDefinedFunctions.cpp
 *
 *  Created on: Jun 9, 2017
 *      Author: SimoAngelov
 */
#include "UserDefinedFunctions.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::make_pair;
#include <vector>
using std::vector;

VCityTempPairs CitiesWithHighestTemp(const VCityTempPairs& vectCityTemp)
{
	int maxTemp = (vectCityTemp.rbegin())->second;
	cout << "maxtemp : " << maxTemp << endl;
	VCityTempPairs result;
	VCityTempPairs::const_reverse_iterator cityTempIt;
	for(cityTempIt = vectCityTemp.rbegin(); cityTempIt != vectCityTemp.rend();
			++cityTempIt)
	{
		string currentCity = cityTempIt->first;
		int currentTemp = cityTempIt->second;
		if (maxTemp == currentTemp)
		{
			result.push_back(make_pair(currentCity, currentTemp));
		}
		else
		{
			break;
		}
	}
	return result;
}

VCityTempPairs ColdestTempPerCities(const cityToTemps& cityTemps)
{
	VCityTempPairs result;
	cityToTemps::const_iterator it;
	for(it = cityTemps.begin(); it != cityTemps.end(); ++it)
	{
		string currentCity = it->first;
		int currentTemp = it->second[0];
		result.push_back(make_pair(currentCity, currentTemp));
	}

	return result;
}

VCityTempPairs Top5HottestCities(const VCityTempPairs& cityTemp)
{
	VCityTempPairs result;
	VCityTempPairs::const_reverse_iterator it;
	int n = 1;
	for(it = cityTemp.rbegin(); it != cityTemp.rend(); ++it)
	{
		string currentCity = it->first;
		int currentTemp =  it->second;
		result.push_back(make_pair(currentCity, currentTemp));
		if(++n >= 6)
		{
			break;
		}
	}
	return result;
}

VCitiesToCounts TimesAbove15DegPerCity(const cityToTemps& cityTempsVect)
{
	VCitiesToCounts result;
	string city[3] =
	{ "Sofia", "Plovdiv", "Varna" };
	int count[3] =
	{ 0 };
	int i = 0;
	cityToTemps::const_iterator cityTempsIt;
	vector<int>::const_iterator vectIt;

	for(cityTempsIt = cityTempsVect.begin(); cityTempsIt != cityTempsVect.end();
			++cityTempsIt){
		vector<int> vectorV = cityTempsIt->second;
		for(vectIt = vectorV.begin(); vectIt != vectorV.end(); ++vectIt)
		{
			int currentTemp = *vectIt;
			if (15 < currentTemp)
			{
				count[i]++;
			}
		}
		result.push_back(make_pair(city[i], count[i]));
		++i;
	}

	return result;
}



VDaysToTemps DaysToTempFunc(const VCityTempPairs& cityTemp)
{
	VDaysToTemps result;
	// temp <10
	// temp <20
	// temp >=20
	int days[3] = {0};
	int temps[2] = {10, 20};

	VCityTempPairs::const_iterator it;

	for(it = cityTemp.begin(); it != cityTemp.end(); ++it)
	{

		string currentCity = it->first;
		int currentTemp = it->second;
	//	cout << currentCity << "\t" << currentTemp << " is ";
		switch(currentTemp / 10){
		case 0:
		//	cout << " <= 10" << endl;
			days[0]++;
			break;
		case 1:
			//cout << " > 10 and <= 20" << endl;
			days[1]++;
			break;

		default:
			//cout << " > 20" << endl;
			days[2]++;
			//cout << "what did you do?!?" << endl;
			break;
		}

	}
	result.push_back(make_pair(days[0], temps[0]));
	result.push_back(make_pair(days[1], temps[1]));
	result.push_back(make_pair(days[2], temps[1]));
	return result;
}



