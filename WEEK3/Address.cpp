/*

*/

#include "Address.h"

Address::Address()
{
	setStreetNo("");
	setStreet("");
	setCity("");
	setState("");
	setZip("");
}

Address::Address(string streetNo, string street, string city, string state, string zip)
{
	setStreetNo(streetNo);
	setStreet(street);
	setCity(city);
	setState(state);
	setZip(zip);
}

void Address::setStreetNo(string streetNo)
{
	this->streetNo = streetNo;
}

void Address::setStreet(string street)
{
	this->street = street;
}

void Address::setCity(string city)
{
	this->city = city;
}

void Address::setState(string state)
{
	this->state = state;
}

void Address::setZip(string zip)
{
	this->zip = zip;
}

// I don't intend to use any "get" methods.