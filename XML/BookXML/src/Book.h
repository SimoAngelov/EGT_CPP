/*
 * Book.h
 *
 *  Created on: 24.05.2017 г.
 *      Author: sim4o
 */

#ifndef BOOK_H_
#define BOOK_H_

#include <string>
using std::string;
#include <iostream>
using std::ostream;
class Book {
private:
	string title;
	string author;
	int year;
	double price;
public:
	Book(const string& title = "", const string& author = "",
			int year = 0, double price = 0.0);
	//getters
	const string& getAuthor() const;
	double getPrice() const;
	const string& getTitle() const;
	int getYear() const;
	//setters
	void setAuthor(const string& author);
	void setPrice(double price);
	void setTitle(const string& title);
	void setYear(int year);
	virtual ~Book();
	//operator out
	friend ostream& operator <<(ostream&, const Book&);
	void print() const;
};

#endif /* BOOK_H_ */
