/*
 * Book.cpp
 *
 *  Created on: 24.05.2017 г.
 *      Author: sim4o
 */

#include "Book.h"
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

Book::Book(const string& title, const string& author, int year, double price) {
	// TODO Auto-generated constructor stub
	setTitle(title);
	setAuthor(author);
	setYear(year);
	setPrice(price);
}

const string& Book::getAuthor() const {
	return author;
}

double Book::getPrice() const {
	return price;
}

const string& Book::getTitle() const {
	return title;
}

int Book::getYear() const {
	return year;
}

void Book::setAuthor(const string& author) {
	this->author = author;
}

void Book::setPrice(double price) {
	this->price = price;
}

void Book::setTitle(const string& title) {
	this->title = title;
}

void Book::setYear(int year) {
	this->year = year;
}

ostream& operator <<(ostream& out, const Book& book){
	out << "--Book Info--\n" <<
			"Title: " << book.getTitle() <<
			"\nAuthor: " << book.getAuthor() <<
			"\nYear: " << book.getYear() <<
			"\nPrice: " << book.getPrice() << "\n";
	return out;
}

void Book::print() const{
	cout << "--Book Info --" << endl;
	cout << "Title: " << this->getTitle() << endl;
	cout << "Author: " << this->getAuthor() << endl;
	cout << "Year: " << this->getYear() << endl;
	cout << "Price: " << this->getPrice() << endl;
	cout << endl;
}
Book::~Book() {
	// TODO Auto-generated destructor stub
}

