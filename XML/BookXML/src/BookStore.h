/*
 * BookStore.h
 *
 *  Created on: 24.05.2017 г.
 *      Author: sim4o
 */

#ifndef BOOKSTORE_H_
#define BOOKSTORE_H_
#include "Book.h"
#include "pugixml.hpp"
#include <vector>
using std::vector;
class BookStore {
private:
	static vector<Book*> books;
public:
	BookStore();
	static void addBook(Book& book);
	static void showAllBooks();
	static vector<Book*> getBooks();
	static void traverseXML();
	virtual ~BookStore();
};

#endif /* BOOKSTORE_H_ */
