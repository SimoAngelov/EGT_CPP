//============================================================================
// Name        : BookXML.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "pugixml.hpp"
#include "Book.h"
#include "BookStore.h"

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	BookStore::traverseXML();

	//cout << BookStore::getBooks()[3]->getAuthor();
	BookStore::showAllBooks();
	return 0;
}
