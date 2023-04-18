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
	setStudentID( 0 );
	setLastName( "" );
	setFirstName( "" );
	setMajor( "" ) ;
	setCreditsEarned( 0 ) ;
	setGPA( 0.0 );
}
// Custom constructor.
Student::Student(int studentID, string lastName, string firstName, string major, int creditsEarned, float gpa )
{
	setStudentID( studentID );
	setLastName( lastName );
	setFirstName( firstName );
	setMajor( major) ;
	setCreditsEarned( creditsEarned ) ;
	setGPA( gpa );
}

// Custom constructor 2.
Student::Student(int studentID, string lastName, string firstName )
{
	setStudentID( studentID );
	setLastName( lastName );
	setFirstName( firstName );
}

// Define "setter" a.k.a. mutator methods.
void Student::setStudentID( int studentID )
{
	this->studentID = studentID;
}

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
int Student::getStudentID()
{
	return studentID;
}

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
        "\n\nStudent ID   : " + std::to_string( studentID ) +
		"\nLast name     : " + lastName +
        "\nFirst name    : " + firstName +
        "\nMajor         : " + major +
        "\nCredits earned: " + std::to_string( creditsEarned ) +
        "\nGPA           : " + std::to_string( gpa ) +
        "\n";
}

string Student::simpleToString()
{
    return
        "\n\nStudent ID   : " + std::to_string( studentID ) +
		"\nLast name     : " + lastName +
        "\nFirst name    : " + firstName +
        "\n";
}