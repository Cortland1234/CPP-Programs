/*
Book.cpp

cpp file to implement Book functions.

*/

#include "Book.h"

Book::Book(string id, string title, string subject, int copyrightYear,
	double cost, string author, string publisher) : Material(id, title, subject, copyrightYear, cost)
{
	setAuthor( author);

	setPublisher(publisher);
}

void Book::setAuthor(string author)
{
	this->author = author;
}

void Book::setPublisher(string publisher)
{
	this->publisher = publisher;
}

Book::~Book()
{
	delete this;
}

string Book::toString()
{
	return Material::toString() +
		"\nAuthor         : " + author +
		"\nPublisher      : " + publisher +
		"\n";
}