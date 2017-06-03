/*
 * Screening.cpp
 *
 *  Created on: Jun 3, 2017
 *      Author: SimoAngelov
 */

#include "Screening.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
Screening::Screening(const string& filmName, const Hall* hall, int capacity,
		int soldTickets, double pricePerTicket): m_filmName(filmName), m_hall(hall),
		m_capacity(capacity), m_soldTickets(soldTickets),
		m_pricePerTicket(pricePerTicket)
{
	// TODO Auto-generated constructor stub
	m_id.append(filmName);
	m_id.append(hall->getName());
}

const string& Screening::getId() const {
	return this->m_id;
}

int Screening::getCapacity() const
{
	return m_capacity;
}

void Screening::setCapacity(int capacity)
{
	m_capacity = capacity;
}

const Hall* Screening::getHall() const
{
	return m_hall;
}

void Screening::setHall(const Hall* hall)
{
	m_hall = hall;
}

const string& Screening::getFilmName() const
{
	return m_filmName;
}

void Screening::setFilmName(const string& filmName)
{
	m_filmName = filmName;
}

double Screening::getPricePerTicket() const
{
	return m_pricePerTicket;
}

void Screening::setPricePerTicket(double pricePerTicket)
{
	m_pricePerTicket = pricePerTicket;
}

int Screening::getSoldTickets() const
{
	return m_soldTickets;
}

void Screening::setSoldTickets(int soldTickets)
{
	m_soldTickets = soldTickets;
}

double Screening::getRevenue() const {
	return this->m_pricePerTicket * this->m_soldTickets;
}

double Screening::getCostEffective() const
{
	return this->m_soldTickets / this->m_capacity;
}
ostream& operator << (ostream& out , const Screening& screening){
	out << "--Screening--" <<
			"\nFilm Name: " << screening.getFilmName() <<
			"\n" << *screening.getHall() <<
			"\nCapacity: " << screening.getCapacity() <<
			"\nSold Tickets: " << screening.getSoldTickets() <<
			"\nPrice per Ticket: " << screening.getPricePerTicket();
	return out;
}
Screening::~Screening()
{
	// TODO Auto-generated destructor stub
	cout << "Screening destructor called. address " << this << endl;
	if(m_hall !=NULL)
	{
		delete m_hall;
	}
}

