/*
Library.h

Header file to declare Libray attributes and function prototypes.

*/

#include <string>

#include "Address.h"

#include "Material.h"

using std::string;



class Library
{
private:
	string name;
	Address address;
	int currentItemCount;
	
	static constexpr int MAX_ITEM_COUNT = 100;

	static int currrentItemCount;

	Material* materialsList[MAX_ITEM_COUNT]; // polymorphic list

public:
	Library(string, Address&);
	void setName(string);
	void setAddress(Address&);
	void addItem(Material*);

	int getItemCount();
	static int getMaxItemCount();

	void displayMaterials();
};