/*
 * UserDefinedFunctions.h
 *
 *  Created on: Jun 9, 2017
 *      Author: SimoAngelov
 */

#ifndef USERDEFINEDFUNCTIONS_H_
#define USERDEFINEDFUNCTIONS_H_

#include "UserDefinedTypes.h"
VCityTempPairs CitiesWithHighestTemp(const VTempCityPairs& vectTempToCity);
VCityTempPairs ColdestTempPerCities(const VTempsPerCities& vectTempPerCities);
VCityTempPairs Top5HottestCities(const VTempCityPairs& vectTempToCity);
VCityTempPairs TimesAbove15DegPerCity(const VTempsPerCities& vectTempPerCities);
VDaysToTemps DaysToTempFunc(const VTempCityPairs& vectTempToCity);



#endif /* USERDEFINEDFUNCTIONS_H_ */
