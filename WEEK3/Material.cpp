/*
Material.h

Header file to declare Material attributes and function prototypes.

*/

#include "Material.h"

Material::Material(string id, string title, string subject, int copyrightYear, double cost)
{
	setID(id);

	setTitle(title);

	setSubject(subject);

	setCopyRightYear(copyrightYear);

	setCost(cost);
}

void Material::setID(string id)
{
	this->id = id;
}

void Material::setTitle(string title)
{
	this->title = title;
}

void Material::setSubject(string subject)
{
	this->subject = subject;
}

void Material::setCopyRightYear(int copyrightYear)
{
	this->copyrightYear = copyrightYear;
}

void Material::setCost(double cost)
{
	this->cost = cost;
}

string Material::toString()
{
	return 
		"\n\nID             : " + id +
		"\nTitle          : " + title +
		"\nSubject        : " + subject +
		"\nCopyright Year : " + std::to_string(copyrightYear) +
		"\nCost           : " + std::to_string(cost) ;
}

Material::~Material()
{
	cout << "\nDeleting Material object";
}

