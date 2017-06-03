/*
 * Cinema.cpp
 *
 *  Created on: Jun 3, 2017
 *      Author: SimoAngelov
 */

#include "Cinema.h"
#include "pugixml.hpp"
#include <iostream>
using std::cerr;
using std::endl;
#include <cstdlib>
using std::exit;
#include <algorithm>
Cinema::Cinema(const string& filePath)
{
	pugi::xml_document doc;
	if (!(doc.load_file(filePath.c_str())))
	{
		cerr << "Error opening " << filePath.c_str() << endl;
		exit(-1);
	}

	pugi::xml_node cinema = doc.child("cinema");

	for (pugi::xml_node currentScreening = cinema.child("screening");
			currentScreening;
			currentScreening = currentScreening.next_sibling("screening"))
	{
		string filmName = currentScreening.child("filmName").text().as_string();
		int hallId = currentScreening.child("hall").attribute("id").as_int();
		string hallName = currentScreening.child("hall").text().as_string();
		int capacity = currentScreening.child("capacity").text().as_int();
		int soldTickets = currentScreening.child("soldTickets").text().as_int();
		int pricePerTicket =
				currentScreening.child("pricePerTicket").text().as_double();
		Hall* hall = new Hall(hallId, hallName);
		Screening* screening = new Screening(filmName, hall, capacity, soldTickets,
				pricePerTicket);
		m_screenings.push_back(screening);

	}

//	delete hall;
//	hall = NULL;
//	delete screening;
//	screening = NULL;

}

const vector<Screening*>& Cinema::getScreenings() const
{
	return m_screenings;
}

void Cinema::setScreenings(const vector<Screening*>& screenings)
{
	this->m_screenings = screenings;
}

//screeningToProfit Cinema::revenueForAllScreenings()
//{
//
//	screeningToProfit result;
//	for (int i = 0; i < m_screenings.size(); ++i)
//	{
//		string screening = m_screenings[i].getId();
//		double revenue = m_screenings[i].getRevenue();
//		if (isKeyInMap(result, screening))
//		{
//			putInMap(result, screening, revenue);
//		}
//	}
//	return result;
//
//}
//
//filmToProfit Cinema::revenueForAllFilms()
//{
//	filmToProfit result;
//	for (int i = 0; i < m_screenings.size(); i++)
//	{
//		string filmName = m_screenings[i].getFilmName();
//		double currentRevenue = m_screenings[i].getRevenue();
//		if (isKeyInMap(result, filmName))
//		{
//			putInMap(result, filmName, currentRevenue);
//		}
//		else
//		{
//			putInMap(result, filmName,
//					getFromMap(result, filmName) + currentRevenue);
//		}
//	}
//	return filmToProfit;
//}
//
//void Cinema::sortByScreeningRevenue()
//{
//	int i, j;
//	Screening key;
//	for (i = 1; i < (int) this->m_screenings.size(); ++i)
//	{
//		key = m_screenings[i];
//		j = i - 1;
//		while (j > 0 && m_screenings[j].getRevenue() > key.getRevenue())
//		{
//			m_screenings[j + 1] = m_screenings[j];
//			--j;
//		}
//		m_screenings[j + 1] = key;
//	}
//}
//
//const pair<string, double> Cinema::extremeScreeningProfit(bool max)
//{
//	this->sortByScreeningRevenue();
//	Screening result;
//	if (max)
//	{
//		result = this->m_screenings[this->m_screenings.size() - 1];
//		return make_pair(result.getId(), result.getRevenue());
//	}
//	else
//	{
//		result = this->m_screenings[0];
//		return make_pair(result.getId(), result.getRevenue());
//	}
//}

Cinema::~Cinema()
{
	// TODO Auto-generated destructor stub
	for (int i = 0; i < (int) this->m_screenings.size(); ++i)
	{
		delete this->m_screenings[i];
	}
	this->m_screenings.resize(0);
}

