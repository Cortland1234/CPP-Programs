/*
** File Student.h
**
** Defines member functions of the Student class.
**
** F. D'Angelo
**/

#include "Student.h"

// Define constructors.
// Default constructor.
Student::Student()
{
	setLastName( "" );
	setFirstName( "" );
	setMajor( "" ) ;
	setCreditsEarned( 0 ) ;
	setGPA( 0.0 );
}
// Custom constructor.
Student::Student(string lastName, string firstName, string major, int creditsEarned, float gpa )
{
	setLastName( lastName );
	setFirstName( firstName );
	setMajor( major) ;
	setCreditsEarned( creditsEarned ) ;
	setGPA( gpa );
}
// Define "setter" a.k.a. mutator methods.
void Student::setLastName( string lastName ) 
{
	this->lastName = lastName ;
}

void Student::setFirstName( string firstName ) 
{
	this->firstName = firstName ;
}

void Student::setMajor( string major ) 
{
	this->major = major ;
}

void Student::setCreditsEarned( int creditsEarned ) 
{
	this->creditsEarned = creditsEarned ;
}

void Student::setGPA( float gpa ) 
{
	this->gpa = gpa ;
}

// Define "getter" a.k.a. accessor methods.
string Student::getLastName() 
{
	return lastName ;
}

string Student::getFirstName() 
{
	return firstName ;
}

string Student::getMajor() 
{
	return major ;
}

int Student::getCreditsEarned() 
{
	return creditsEarned ;
}

float Student::getGPA() 
{
	return gpa ;
}

string Student::toString()
{
    return
        "\n\nLast name     : " + lastName +
        "\nFirst name    : " + firstName +
        "\nMajor         : " + major +
        "\nCredits earned: " + std::to_string( creditsEarned ) +
        "\nGPA           : "+ std::to_string( gpa ) +
        "\n";
}

bool Student::cmpGpaLessThan( Student& rhStudent )
{
    if (this->gpa < rhStudent.gpa) return true;

    return false;
}

bool Student::cmpGpaGreaterThan( Student& rhStudent )
{
    if (this->gpa > rhStudent.gpa) return true;

    return false;
}

bool Student::cmpCreditsLessThan( Student& rhStudent )
{
    if (this->creditsEarned < rhStudent.creditsEarned) return true;

    return false;
}

bool Student::cmpCreditsGreaterThan( Student& rhStudent )
{
    if (this->creditsEarned > rhStudent.creditsEarned) return true;

    return false;
}
