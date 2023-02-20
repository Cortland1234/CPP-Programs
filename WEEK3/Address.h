#pragma once
/*
Address.h

Header file to declare Address attributes and function prototypes.

*/

#include <string>

using std::string;

class Address
{
private:
	string streetNo;
	string street;
	string city;
	string state;
	string zip;

public:
	Address();
	Address(string, string, string, string, string);

	void setStreetNo(string);
	void setStreet(string);
	void setCity(string);
	void setState(string);
	void setZip(string);

	// I don't intend to use any "get" methods.
};