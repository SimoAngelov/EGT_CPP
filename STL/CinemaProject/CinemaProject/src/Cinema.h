/*
 * Cinema.h
 *
 *  Created on: Jun 3, 2017
 *      Author: SimoAngelov
 */

#ifndef CINEMA_H_
#define CINEMA_H_
#include <vector>
using std::vector;
#include <string>
using std::string;
#include "Screening.h"
#include <map>
using std::map;
#include <memory>
#include "MapOperations.h"
using std::pair;
//using std::shared_ptr;
typedef map <string, double> screeningToProfit;
typedef map <string, double> filmToProfit;

class Cinema
{
private:
	vector<Screening*> m_screenings;
	//vector<shared_ptr<Screening> > s;
	void sortByScreeningRevenue();
	void sortByFilmRevenue();
public:
	Cinema(const string& fileName = "");
	virtual ~Cinema();
	const vector<Screening*>& getScreenings() const;
	void setScreenings(const vector<Screening*>& screenings);
	const pair<string, double> extremeScreeningProfit(bool max);
	screeningToProfit revenueForAllScreenings();
	filmToProfit revenueForAllFilms();

};

#endif /* CINEMA_H_ */
