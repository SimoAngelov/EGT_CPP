/*
 * UserDefinedTypes.h
 *
 *  Created on: Jun 9, 2017
 *      Author: SimoAngelov
 */

#ifndef USERDEFINEDTYPES_H_
#define USERDEFINEDTYPES_H_

#include <iostream>
using std::string;
using std::pair;
#include <vector>
using std::vector;
#include <map>
using std::map;
using std::multimap;

typedef map<string, vector<int> > cityToTemps;
typedef multimap<string, int> cityToTemp;
typedef multimap<int, string> tempToCity;
typedef vector<pair<string, int> > VCityTempPairs;
typedef vector<pair<int, string> > VTempCityPairs;
typedef vector<VTempCityPairs> VTempsPerCities;

typedef vector<pair<string, int> > VCitiesToCounts;
typedef vector<pair<int, int> > VDaysToTemps;



#endif /* USERDEFINEDTYPES_H_ */
