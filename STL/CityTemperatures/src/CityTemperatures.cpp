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

typedef map<string, vector<int> > cityToTemps;
typedef multimap<int, string> tempToCity;
typedef vector<pair<string, int> > VCityTempPairs;
typedef vector<pair<int, string> > VTempCityPairs;
typedef vector<VTempCityPairs> VTempsPerCities;

typedef vector<pair<string, int> > VCitiesToCounts;
typedef vector<pair<int, int> > VDaysToTemps;

//function prototypes
VCityTempPairs CitiesWithHighestTemp(const VTempCityPairs& vectTempToCity);
VCityTempPairs ColdestTempPerCities(const VTempsPerCities& vectTempPerCities);
VCityTempPairs Top5HottestCities(const VTempCityPairs& vectTempToCity);
VCityTempPairs TimesAbove15DegPerCity(const VTempsPerCities& vectTempPerCities);
VDaysToTemps DaysToTempFunc(const VTempCityPairs& vectTempToCity);


int main()
{
	int arr1[] =
	{ 12, 34, 17, 23, 23 };
	int arr2[] =
	{ 15, 17, 19, 32, 12 };
	int arr3[] =
	{ 34, 22, 8, 9 };

	//vector of temperatures
	vector<int> sofiaTemp(arr1, arr1 + 5);
	vector<int> plovdivTemp(arr2, arr2 + 5);
	vector<int> varnaTemp(arr3, arr3 + 4);

	//initialize the map of city-temperatures
	cityToTemps sofiaTemps;
	sofiaTemps["Sofia"] = sofiaTemp;
	cityToTemps plovdivTemps;
	plovdivTemps["Plovdiv"] = plovdivTemp;
	cityToTemps varnaTemps;
	varnaTemps["Varna"] = varnaTemp;

	//map iterators
	cityToTemps::iterator cityIt;

	//vector of city-temperature pairs
	VCityTempPairs sofiaTempPairs;
	VCityTempPairs plovdivTempPairs;
	VCityTempPairs varnaTempPairs;

	//iterator to vectors of city-temperature pairs
	VCityTempPairs::iterator cityTempPairIt;

	//multi-map to store temp-city pairs;
	tempToCity mapTempToCity;
	tempToCity sofiaTempToCity;
	tempToCity plovdivTempToCity;
	tempToCity varnaTempToCity;

	//iterator for the above map
	tempToCity::iterator tempIt;

	//vector to store the three maps of temp-city pairs (one for each city)
	VTempsPerCities vectorTempPerCities;

	//vector to store the temp-city pairs for sofia
	VTempCityPairs vectorTempPerSofia;
	//vector to store the temp-city pairs for plovdiv
	VTempCityPairs vectorTempPerPlovdiv;
	//vector to store the temp-city pairs for varna
	VTempCityPairs vectorTempPerVarna;

	//push the temperatures from sofia into a vector of city-temp pairs
	for (cityIt = sofiaTemps.begin(); cityIt != sofiaTemps.end(); ++cityIt)
	{
		vector<int> vectorTemp = cityIt->second;
		vector<int>::iterator tempIt;
		for (tempIt = vectorTemp.begin(); tempIt != vectorTemp.end(); ++tempIt)
		{
			string cityName = cityIt->first;
			int temp = *tempIt;
			sofiaTempPairs.push_back(make_pair(cityName, temp));
		}
	}

	//push the temperatures from plovdiv into a vector of city-temp pairs
	for (cityIt = plovdivTemps.begin(); cityIt != plovdivTemps.end(); ++cityIt)
	{
		vector<int> vectorTemp = cityIt->second;
		vector<int>::iterator tempIt;
		for (tempIt = vectorTemp.begin(); tempIt != vectorTemp.end(); ++tempIt)
		{
			string cityName = cityIt->first;
			int temp = *tempIt;
			plovdivTempPairs.push_back(make_pair(cityName, temp));
		}
	}

	//push the temperatures from varna into a vector of city-temp pairs
	for (cityIt = varnaTemps.begin(); cityIt != varnaTemps.end(); ++cityIt)
	{
		vector<int> vectorTemp = cityIt->second;
		vector<int>::iterator tempIt;
		for (tempIt = vectorTemp.begin(); tempIt != vectorTemp.end(); ++tempIt)
		{
			string cityName = cityIt->first;
			int temp = *tempIt;
			varnaTempPairs.push_back(make_pair(cityName, temp));
		}
	}

	//push the city-temp pairs from sofia into the temp-city multimap
	for (cityTempPairIt = sofiaTempPairs.begin();
			cityTempPairIt != sofiaTempPairs.end(); ++cityTempPairIt)
	{
		int key = cityTempPairIt->second;
		string val = cityTempPairIt->first;
		mapTempToCity.insert(pair<int, string>(key, val));
		sofiaTempToCity.insert(pair<int, string>(key, val));
	}

	//push the city-temp pairs from plovdiv into the temp-city multimap
	for (cityTempPairIt = plovdivTempPairs.begin();
			cityTempPairIt != plovdivTempPairs.end(); ++cityTempPairIt)
	{
		int key = cityTempPairIt->second;
		string val = cityTempPairIt->first;
		mapTempToCity.insert(pair<int, string>(key, val));
		plovdivTempToCity.insert(pair<int, string>(key, val));
	}

	//push the city-temp pairs from varna into the temp-city multimap
	for (cityTempPairIt = varnaTempPairs.begin();
			cityTempPairIt != varnaTempPairs.end(); ++cityTempPairIt)
	{
		int key = cityTempPairIt->second;
		string val = cityTempPairIt->first;
		mapTempToCity.insert(pair<int, string>(key, val));
		varnaTempToCity.insert(pair<int, string>(key, val));
	}

	//push the temp-city pairs for sofia from the map into the vector
	for (tempIt = sofiaTempToCity.begin(); tempIt != sofiaTempToCity.end();
			++tempIt)
	{
		int key = tempIt->first;
		string val = tempIt->second;
		vectorTempPerSofia.push_back(make_pair(key, val));
	}

	//push the temp-city pairs for plovdiv from the map into the vector
	for (tempIt = plovdivTempToCity.begin(); tempIt != plovdivTempToCity.end();
			++tempIt)
	{
		int key = tempIt->first;
		string val = tempIt->second;
		vectorTempPerPlovdiv.push_back(make_pair(key, val));
	}

	//push the temp-city pairs for varna from the map into the vector
	for (tempIt = varnaTempToCity.begin(); tempIt != varnaTempToCity.end();
			++tempIt)
	{
		int key = tempIt->first;
		string val = tempIt->second;
		vectorTempPerVarna.push_back(make_pair(key, val));
	}

	//push the three vectors of temp-city pairs into one vector
	vectorTempPerCities.push_back(vectorTempPerSofia);
	vectorTempPerCities.push_back(vectorTempPerPlovdiv);
	vectorTempPerCities.push_back(vectorTempPerVarna);


	//push the temp-city pairs from the multimap into a single vector
	tempToCity::iterator sortedIt;
	VTempCityPairs tempCityPairs;
//	cout << "City\tTemp" << endl;
	for (sortedIt = mapTempToCity.begin(); sortedIt != mapTempToCity.end();
			++sortedIt)
	{
		int key = sortedIt->first;
		string val = sortedIt->second;
//		cout << sortedIt->second << "\t" << sortedIt->first << endl;
		tempCityPairs.push_back(make_pair(key, val));
	}

	//push the temp-city pairs from the sofia map into the sofia vector
	for (tempIt = sofiaTempToCity.begin(); tempIt != sofiaTempToCity.end();
			++tempIt)
	{
		int key = tempIt->first;
		string val = tempIt->second;
		vectorTempPerSofia.push_back(make_pair(key, val));
	}

	//push the temp-city pairs from the plovdiv map into the sofia vector
	for (tempIt = plovdivTempToCity.begin(); tempIt != plovdivTempToCity.end();
			++tempIt)
	{
		int key = tempIt->first;
		string val = tempIt->second;
		vectorTempPerPlovdiv.push_back(make_pair(key, val));
	}

	//push the temp-city pairs from the varna map into the sofia vector
	for (tempIt = plovdivTempToCity.begin(); tempIt != plovdivTempToCity.end();
			++tempIt)
	{
		int key = tempIt->first;
		string val = tempIt->second;
		vectorTempPerVarna.push_back(make_pair(key, val));
	}

//task1
	cout << "task1" << endl;
	VCityTempPairs citiesWithHighestTemp = CitiesWithHighestTemp(tempCityPairs);
	cout << "city\ttemp" << endl;
	for (unsigned int i = 0; i < citiesWithHighestTemp.size(); ++i)
	{
		string city = citiesWithHighestTemp[i].first;
		int temp = citiesWithHighestTemp[i].second;
		cout << city << "\t" << temp << endl;
	}
	cout << endl;

//task2
	cout << "task2" << endl;
	VCityTempPairs coldestTempPerCities = ColdestTempPerCities(
			vectorTempPerCities);
	cout << "city\ttemp" << endl;
	for (unsigned int i = 0; i < coldestTempPerCities.size(); ++i)
	{
		string city = coldestTempPerCities[i].first;
		int temp = coldestTempPerCities[i].second;
		cout << city << "\t" << temp << endl;
	}
	cout << endl;
//task3
	cout << "task3" << endl;
	VCityTempPairs top5HottestCities = Top5HottestCities(tempCityPairs);
	cout << "city\ttemp" << endl;
	for (unsigned int i = 0; i < top5HottestCities.size(); ++i)
	{
		string city = top5HottestCities[i].first;
		int temp = top5HottestCities[i].second;
		cout << city << "\t" << temp << endl;
	}
	cout << endl;

	//task4
	cout << "task4" << endl;
	VCitiesToCounts timesAbove15DegPerCity = TimesAbove15DegPerCity(
			vectorTempPerCities);
	cout << "City\tNumber of Days" << endl;
	for (unsigned int i = 0; i < timesAbove15DegPerCity.size(); ++i)
	{
		string city = timesAbove15DegPerCity[i].first;
		int count = timesAbove15DegPerCity[i].second;
		cout << city << "\t" << count << endl;
	}
	cout << endl;

	//task5
	cout << "task5" << endl;
	VDaysToTemps daysToTemp = DaysToTempFunc(tempCityPairs);
	cout << daysToTemp[0].first << " days with a temperature below or equal to "
			<< daysToTemp[0].second << " degrees." << endl;
	cout << daysToTemp[1].first
			<< " days with a temperature above 10 and below or equal to "
			<< daysToTemp[1].second << " degrees." << endl;
	cout << daysToTemp[2].first << " days with a temperature above "
			<< daysToTemp[1].second << " degrees." << endl;
	return 0;
}



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