/*
** File StudentDriver.cpp
**
** Uses the Student class to demonstrate stuff. MODIFIED FOR QUIZ #5!
**
** Cortland Diehm
**
** Shell Sort code by Donald Knuth, taken from "The C++ Programming Language" by Bjarne Stroustrup
**/

#include "Student.h"

#include <vector>

template<typename T>
void shellSort( vector<T>&, int (*compare_to)(T& var1, T& var2) );

template<typename T>
void displayVector( vector<T>& );

template<typename T>
void getHighest( vector<T>&, int (*compare_to)(T& var1, T& var2) );

template<typename T>
void getLowest( vector<T>&, int (*compare_to)(T& var1, T& var2) );

//int (*compare_to)  ( Student* var1, Student* var2 );

int compare_credits( Student& var1, Student& var2 ); // has same interface as compare_to prototype.

int compare_gpa    ( Student& var1, Student& var2 ); // has same interface as compare_to prototype.

using namespace std;

int main()
{
    vector< Student >studentVector;

	// Set values of data members using a custom constructor.
	Student student1( "van gogh", "vincent", "art", 117, 3.7F ) ;

    studentVector.push_back( student1 );

    Student student2( "zimbardo", "phillip", "psyc", 90, 3.8F ) ;

    studentVector.push_back( student2 );

    Student student3( "von neumann", "jon", "math, phys", 81, 4.0F ) ;

    studentVector.push_back( student3 );

    Student student4( "dickens", "charles", "lit", 72, 3.9F ) ;

    studentVector.push_back( student4 );

    Student student5( "javanbakht", "taraneh", "bio", 105, 3.9F ) ;

    studentVector.push_back( student5 );

	cout << "\n\n***** Display unsorted students *****\n\n";

    displayVector( studentVector );

    shellSort( studentVector, compare_credits);

    cout << "\n\n***** Display students sorted by creditsEarned ascending *****\n\n";

    displayVector( studentVector );

    shellSort( studentVector, compare_gpa);

    cout << "\n\n***** Display students sorted by gpa ascending *****\n\n";

    displayVector( studentVector );

    cout << "\n\n***** Display student with the HIGHEST GPA *****\n\nstudentWithHighestGPA = ";

    getHighest( studentVector, compare_gpa);

    cout << "\n\n***** Display student with the LOWEST GPA *****\n\nstudentWithLowestGPA = ";

    getLowest( studentVector, compare_gpa);

    cout << "\n\n***** Display student with the HIGHEST credits earned *****\n\nstudentWithHighestCE = ";

    getHighest( studentVector, compare_credits);

    cout << "\n\n***** Display student with the LOWEST credits earned *****\n\nstudentWithLowestCE = ";

    getLowest( studentVector, compare_credits);

	return 0 ;
}

template<typename T>
void shellSort( vector<T>& v, int (*compare_to)( T& var1, T& var2))
{
    const size_t n = v.size(); // just for brevity

    for (int gap = n/2 ; 0 < gap ; gap /= 2 )
    {
        for ( int i = gap ; i < n ; i++ )
        {
            for ( int j = i - gap ; 0 <= j ; j -= gap )
            {
                if ( compare_to( v[ j + gap ], v[ j ] ) < 0 ) 
                {
                    std::swap( v[ j ],  v[ j + gap ]); // built-in swap function
                }
            } 
        }
    }
}


template<typename T>
void getHighest( vector<T>& v, int (*compare_to)(T& var1, T& var2) )
{
    const size_t n = v.size(); // just for brevity

    for (int gap = n/2 ; 0 < gap ; gap /= 2 )
    {
        for ( int i = gap ; i < n ; i++ )
        {
            for ( int j = i - gap ; 0 <= j ; j -= gap )
            {
                if ( compare_to( v[ j + gap ], v[ j ] ) < 0 ) 
                {
                    std::swap( v[ j ],  v[ j + gap ]); // built-in swap function
                }
            } 
        }
    }
    auto var = v.back(); // After sorting, this will go to the last element of the vector, and thus the highest value
    cout << var.toString();

}

template<typename T>
void getLowest( vector<T>& v, int (*compare_to)(T& var1, T& var2) )
{
    const size_t n = v.size(); // just for brevity

    for (int gap = n/2 ; 0 < gap ; gap /= 2 )
    {
        for ( int i = gap ; i < n ; i++ )
        {
            for ( int j = i - gap ; 0 <= j ; j -= gap )
            {
                if ( compare_to( v[ j + gap ], v[ j ] ) < 0 ) 
                {
                    std::swap( v[ j ],  v[ j + gap ]); // built-in swap function
                }
            } 
        }
    }
    auto var = v.front(); // After sorting, this will go to the first element of the vector, and thus the lowest value
    cout << var.toString();

}

template<typename T>
void displayVector( vector<T>& v)
{
    for ( auto obj : v )
    {
        cout << obj.toString();
    }
}

int compare_credits( Student& s1, Student& s2 ) // has same interface as compare_to prototype.
{
	if ( s1.getCreditsEarned() < s2.getCreditsEarned() ) return -1;

	else if ( s1.getCreditsEarned() > s2.getCreditsEarned() ) return 1;

	else return 0 ;
}

int compare_gpa( Student& s1, Student& s2 ) // has same interface as compare_to prototype.
{
	if ( s1.getGPA() < s2.getGPA() ) return -1;

	else if ( s1.getGPA() > s2.getGPA() ) return 1;

	else return 0 ;
}