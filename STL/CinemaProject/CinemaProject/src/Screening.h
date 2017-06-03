/*
 * Screening.h
 *
 *  Created on: Jun 3, 2017
 *      Author: SimoAngelov
 */

#ifndef SCREENING_H_
#define SCREENING_H_
#include <string>
using std::string;
#include "Hall.h"
class Screening
{
private:
	string m_id;
	string m_filmName;
	const Hall* m_hall;
	int m_capacity;
	int m_soldTickets;
	double m_pricePerTicket;
public:
	Screening(const string& filmName, const Hall* hall,
			int capacity, int soldTickets, double pricePerTicket);

	virtual ~Screening();
	const string& getId() const;
	int getCapacity() const;
	void setCapacity(int capacity);
	const Hall* getHall() const;
	void setHall(const Hall* hall);
	const string& getFilmName() const;
	void setFilmName(const string& filmName);
	double getPricePerTicket() const;
	void setPricePerTicket(double pricePerTicket);
	int getSoldTickets() const;
	void setSoldTickets(int soldTickets);
	double getRevenue() const;
	double getCostEffective() const;
	friend ostream& operator << (ostream&, const Screening&);
};

#endif /* SCREENING_H_ */
