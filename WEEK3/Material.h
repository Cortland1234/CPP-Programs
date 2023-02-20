#pragma once

/*
Material.h

Header file to declare Material attributes and function prototypes.

*/

#include <string>
#include <iostream>

using std::string;
using std::cout;

class Material
{
private:
	string id; // IMDB # for films, ISBN for books
	string title;
	string subject;
	int copyrightYear;
	double cost;

public:
	Material(string, string, string, int, double); // id, title, subject, copyrightYear, cost

	void setID(string);
	void setTitle(string);
	void setSubject(string);
	void setCopyRightYear(int);
	void setCost(double);

	virtual string toString();

	virtual ~Material();
};