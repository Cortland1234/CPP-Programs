/*
Library.h

cpp file to implement Library functions.

*/

#include <string>
#include <iostream>

using std::string;
using std::cout;

#include "Library.h"

Library::Library(string name, Address& address)
{
	setName(name);

	setAddress(address);

	currentItemCount = 0;

	for (int i = 0; i < MAX_ITEM_COUNT; i++)
	{
		materialsList[i] = nullptr; // initialize items in list to nullptr
	}
}

void Library::setName(string name)
{
	this->name = name;
}

void Library::setAddress(Address& address)
{
	this->address = address;
};

void Library::addItem(Material* item)
{
	cout << "\naddItem currentItemCount = " << currentItemCount;

	if (currentItemCount < MAX_ITEM_COUNT - 1)
	{
		materialsList[currentItemCount++] = item;	// I don't usually use ++ or -- in another operation,
													// but the alternative shown below seems more confusing.
		/*
		currentItemCount++;

		materialsList[currentItemCount - 1] = item; // - 1 because the array starts at zero.
		*/
	}
}

int Library::getItemCount()
{
	return currentItemCount;
}

int Library::getMaxItemCount()
{
	return MAX_ITEM_COUNT;
}

void Library::displayMaterials()
{
	for (int i = 0; i < currentItemCount; i++)
	{
		cout << materialsList[i]->toString();
	}
}