/*
** File Student.h
**
** Declares attributes and member functions of the Student class.
**
** F. D'Angelo
**/

#include <iostream>
#include <string>

using namespace std ;

class Student
{
public:
	// Declare constructors
	// Default constructor.
	Student () ;

	// Custom constructor.
	Student (string, string, string, int, float ) ;
/*
    // copy constructor
    Student( Student& );

    // move constructor
    Student (Student&& student);
*/
	// Declare public methods.
	// "setter" a.k.a mutator methods.
	void setLastName( string ) ;
	void setFirstName( string ) ;
	void setMajor( string ) ;
	void setCreditsEarned( int ) ;
	void setGPA( float ) ;

	// "getter" a.k.a accesor methods.
	string getLastName() ;
	string getFirstName() ;
	string getMajor() ;
	int    getCreditsEarned() ;
	float  getGPA() ;

    string toString();

    bool cmpGpaLessThan( Student& rhStudent );
    bool cmpGpaGreaterThan( Student& rhStudent );

    bool cmpCreditsLessThan( Student& rhStudent );
    bool cmpCreditsGreaterThan( Student& rhStudent );

private:
	// Declare private data members.
	string lastName, firstName, major;
    
    int creditsEarned ;

	float gpa ;
} ;