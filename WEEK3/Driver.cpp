/*
Driver.cpp

Run the Library process

Cortland Diehm
*/

#include <string>
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::to_string;

#include "Library.h"
#include "Material.h"
#include "Book.h"
#include "Film.h"
#include "Address.h"

using std::ifstream;

void loadFilms(Library&, const string&);
void loadBooks(Library&, const string&);

int main()
{
	Address addressObj("1510", "E.University Blvd", "Tucson", "AZ", "85721-0055");

	Library mainLibrary("UA Main", addressObj);

	loadBooks(mainLibrary, "books_for_main.txt");
	loadFilms(mainLibrary, "films_for_main.txt");

	mainLibrary.displayMaterials();
}

void loadBooks( Library& myLibrary, const string& bookFile)
{
	string id, title, subject, author, publisher;

	int copyrightYear;
	
	double cost;

	ifstream inputFile;

	inputFile.open(bookFile);

	if (!inputFile.good())
	{
		cout << "\n\nFailed to open " << bookFile << ".";
		cout << "\nfailbit = " << inputFile.failbit << " badbit = " << inputFile.badbit;
		cout << "\nExiting the program.";

		printf("\n\nPress any key to continue...\n\n");
		cin.get();

		exit(EXIT_FAILURE); // EXIT_FAILURE and EXIT_SUCCESS are builtin constants in cstdlib.
	}

	string inputRecStr{};

	while (!inputFile.eof() )
	{
		// read data for the current Book.

		getline(inputFile, inputRecStr);
		
		// some possibly helpfully debugging statements that you can expand on"
		/*
		cout << "\nloadBooks: inputRecStr = " << inputRecStr << " length = " << inputRecStr.length();
		cout << "\ninputRecStr.substr(73, 4).c_str() = " << inputRecStr.substr(73, 4).c_str();
		cout << "\ninputRecStr.substr(78, 6).c_str() = " << inputRecStr.substr(78, 6).c_str();
		*/

		id = inputRecStr.substr(0, 5);

		title = inputRecStr.substr(6, 50);

		subject = inputRecStr.substr(57, 15);

		copyrightYear = atoi(inputRecStr.substr(73, 4).c_str());

		cost = atof(inputRecStr.substr(78, 6).c_str());

		author = inputRecStr.substr(85, 20);

		publisher = inputRecStr.substr(106, 12);

		// Polymorphic Book object to add to array of Material*

		Material* newBook = new Book(id, title, subject, copyrightYear, cost, author, publisher);

		myLibrary.addItem(newBook);

	} // end while

	inputFile.close(); // Always close whatever you open.
}

void loadFilms( Library& myLibrary, const string& filmFile)
{
	string id, title, subject, director, writer, productionCo;

	int copyrightYear;
	
	double cost;

	ifstream inputFile;

	inputFile.open(filmFile);

	if (!inputFile.good())
	{
		cout << "\n\nFailed to open " << filmFile << ".";
		cout << "\nfailbit = " << inputFile.failbit << " badbit = " << inputFile.badbit;
		cout << "\nExiting the program.";

		printf("\n\nPress any key to continue...\n\n");
		cin.get();

		exit(EXIT_FAILURE); // EXIT_FAILURE and EXIT_SUCCESS are builtin constants in cstdlib.
	}

	string inputRecStr{};

	while (!inputFile.eof() )
	{
		// read data for the current Film.

		getline(inputFile, inputRecStr);

		id = inputRecStr.substr(0, 5);

		title = inputRecStr.substr(6, 24);

		subject = inputRecStr.substr(31, 20);

		copyrightYear = atoi(inputRecStr.substr(52, 4).c_str());

		cost = atof(inputRecStr.substr(57, 5).c_str());

		director = inputRecStr.substr(63, 16);

		writer = inputRecStr.substr(80, 24);

		productionCo = inputRecStr.substr(105, 25);

		// Polymorphic Book object to add to array of Material*

		Material* newFilm = new Film(id, title, subject, copyrightYear, cost, director, writer, productionCo);

		myLibrary.addItem(newFilm);

	} // end while

	inputFile.close(); // Always close whatever you open.
}


