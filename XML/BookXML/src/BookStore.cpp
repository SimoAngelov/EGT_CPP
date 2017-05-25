/*
 * BookStore.cpp
 *
 *  Created on: 24.05.2017 г.
 *      Author: sim4o
 */

#include "BookStore.h"
#include <iostream>
using std::cout;
using std::endl;
vector<Book*> BookStore::books;
BookStore::BookStore() {
	// TODO Auto-generated constructor stub

}

void BookStore::addBook(Book& book){
	BookStore::books.push_back(&book);
}

void BookStore::showAllBooks(){
	cout << "List of books in the bookstore: " << endl;
	for(unsigned int i = 0; i < BookStore::books.size(); i++){
		cout << *BookStore::books[i] << endl;
		//BookStore::books[i]->print();
		cout << endl;
	}
	cout << "End of list." << endl;
}

vector<Book*> BookStore::getBooks(){
	return BookStore::books;
}

void BookStore::traverseXML(){
	string title, author;
	int year;
	double price;
	pugi::xml_document doc;
	const char* fileName = "Book.xml";
	const char* rootNode = "bookstore";
	if(!(doc.load_file(fileName))){
		cout << "error opening file!" << endl;
	}
	pugi::xml_node books = doc.child(rootNode);

	Book* book;
	for(pugi::xml_node currentBook = books.first_child(); currentBook;
			currentBook = currentBook.next_sibling()){
		book = new Book;
		title = currentBook.child("title").text().as_string();
		author = currentBook.child("author").text().as_string();
		year = currentBook.child("year").text().as_int();
		price = currentBook.child("price").text().as_double();
		book = new Book(title, author, year, price);
//		book->setTitle(title);
//		book->setAuthor(author);
//		book->setPrice(price);
//		book->setYear(year);

		BookStore::addBook(*book);


//		cout << "Current Bok:" << endl;
//		book->print();

//		cout << "added book" << endl;
//		BookStore::getBooks()[BookStore::getBooks().size()-1]->print();


	}

	book = NULL;
	delete book;

//	//pugi::xml_node books = doc.child("bookstore");
//	int j = 0;
//	for (pugi::xml_node i = books.first_child(); i; i = i.next_sibling()) {
//		cout << "current book" << endl;
//		Book *b = new Book;
//		b->setTitle(i.child("title").text().as_string());
//		b->setAuthor(i.child("author").text().as_string());
//		b->setYear(i.child("year").text().as_int());
//		b->setPrice(i.child("price").text().as_double());
//		b->print();
//		BookStore::addBook(*b);
//		BookStore::books[j]->print();
//		b = NULL;
//		delete b;
//	}



}

BookStore::~BookStore() {
	// TODO Auto-generated destructor stub
}

