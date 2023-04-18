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
	Student (int, string, string, string, int, float ) ;

	// Custom constructor 2.
	Student (int, string, string ) ;
/*
    // copy constructor
    Student( Student& );

    // move constructor
    Student (Student&& student);
*/
	// Declare public methods.
	// "setter" a.k.a mutator methods.
	void setStudentID( int ) ;
	void setLastName( string ) ;
	void setFirstName( string ) ;
	void setMajor( string ) ;
	void setCreditsEarned( int ) ;
	void setGPA( float ) ;

	// "getter" a.k.a accesor methods.
	int    getStudentID();
	string getLastName() ;
	string getFirstName() ;
	string getMajor() ;
	int    getCreditsEarned() ;
	float  getGPA() ;

    string toString();

	string simpleToString();

private:
	// Declare private data members.

	int studentID;

	string lastName, firstName, major;
    
    int creditsEarned ;

	float gpa ;
} ;