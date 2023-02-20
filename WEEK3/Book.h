#pragma once

/*
Book.h

Header file to declare Book attributes and function prototypes.
*/

#include <string>

#include "Material.h"

using std::string;

class Book : public Material
{
private:
	// string title;		inherited from Material
	// int copyrightYear;	inherited from Material

	string author;
	string publisher;

public:
	Book(string, string, string, int, double, string, string ) ; // id, title, subject, copyrighYear, cost, author, publisher

	// void setTitle(string);		inherited from Material	We wouldn't normally include these
	// void setSubject(string);		inherited from Material commented out methods.
	// void setCopyRightYear(int);	inherited from Material I'm trying to make the situation clear.
	// void setCost(int);			inherited from Material
	
	void setAuthor(string);
	void setPublisher(string);

	string toString();

	~Book() override;
};
