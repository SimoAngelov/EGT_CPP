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

VCityTempPairs CitiesWithHighestTemp(const VTempCityPairs& vectTempToCity)
{
	int maxTemp = (vectTempToCity.end() - 1)->first;
	VCityTempPairs result;
	int size = vectTempToCity.size();
	for (int i = size - 1; i >= 0; --i)
	{
		string currentCity = vectTempToCity[i].second;
		int currentTemp = vectTempToCity[i].first;

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

VCityTempPairs ColdestTempPerCities(const VTempsPerCities& vectTempPerCities)
{
	VCityTempPairs result;
	int size = vectTempPerCities.size();
	for (int i = 0; i < size; ++i)
	{
		string currentCity = vectTempPerCities[i][0].second;
		int currentTemp = vectTempPerCities[i][0].first;
		result.push_back(make_pair(currentCity, currentTemp));
	}
	return result;
}

VCityTempPairs Top5HottestCities(const VTempCityPairs& vectTempToCity)
{
	VCityTempPairs result;
	int size = vectTempToCity.size();
	for (int i = size - 1; i > size - 6; --i)
	{
		string currentCity = vectTempToCity[i].second;
		int currentTemp = vectTempToCity[i].first;
		result.push_back(make_pair(currentCity, currentTemp));
	}

	return result;
}

VCitiesToCounts TimesAbove15DegPerCity(const VTempsPerCities& vectTempPerCities)
{
	VCityTempPairs result;
	string city[3] =
	{ "Sofia", "Plovdiv", "Varna" };
	int count[3] =
	{ 0 };
	int size = vectTempPerCities.size();
	for (int i = 0; i < size; i++)
	{
		int citySize = vectTempPerCities[i].size();
		for (int j = 0; j < citySize; j++)
		{
			int currentTemp = vectTempPerCities[i][j].first;
			if (15 < currentTemp)
			{
				count[i]++;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		result.push_back(make_pair(city[i], count[i]));
	}
	return result;
}

VDaysToTemps DaysToTempFunc(const VTempCityPairs& vectTempToCity)
{
	VDaysToTemps result;
	// temp <10
	// temp <20
	// temp >=20
	int days[3] = {0};
	int temps[2] = {10, 20};

	int size = vectTempToCity.size();

	for(int i = 0; i < size; ++i)
	{
		int currentTemp = vectTempToCity[i].first;
		string currentCity = vectTempToCity[i].second;
		cout << currentCity << "\t" << currentTemp << " is ";
		switch(currentTemp / 10){
		case 0:
			cout << " <= 10" << endl;
			days[0]++;
			break;
		case 1:
			cout << " > 10 and <= 20" << endl;
			days[1]++;
			break;

		default:
			cout << " > 20" << endl;
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



