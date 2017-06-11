/*
 * UserDefinedFunctions.h
 *
 *  Created on: Jun 9, 2017
 *      Author: SimoAngelov
 */

#ifndef USERDEFINEDFUNCTIONS_H_
#define USERDEFINEDFUNCTIONS_H_

#include "UserDefinedTypes.h"
VCityTempPairs CitiesWithHighestTemp(const VCityTempPairs&);
VCityTempPairs ColdestTempPerCities(const cityToTemps&);
VCityTempPairs Top5HottestCities(const VCityTempPairs&);
VCityTempPairs TimesAbove15DegPerCity(const cityToTemps&);
VDaysToTemps DaysToTempFunc(const VCityTempPairs&);



#endif /* USERDEFINEDFUNCTIONS_H_ */
