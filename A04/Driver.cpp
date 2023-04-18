/*
** File StudentDriver.cpp
**
** Uses the Student class to demonstrate stuff.
**
** F. D'Angelo
**/

#include <fstream>
#include <vector>
#include <unordered_map>

#include "Student.h"

using namespace std;

struct studentQuizType  // using a struct with public members for simplicity.
{                       // "simple" is often the best way to go.
public:
    int     studentID ;
    string  quizID;
    int     grade;

    studentQuizType( int studentID, string quizID, int grade ) // constructor
    {
        this->studentID = studentID;
        this->quizID = quizID;
        this->grade = grade;
    }
};

template<typename T>
void shellSort( vector<T>&, int (*compare_to)(T& var1, T& var2) );

template<typename T>
void displayVector( vector<T>& );

void loadStudents(unordered_map<int, Student>& , const char* );

void loadQuizzes(vector<studentQuizType>& , const char* );

void displayStudentScores( unordered_map< int, Student >&, vector< studentQuizType >& );

int main()
{
    const char* studentFile = "students.txt";

    const char* quizFile = "quizzes.txt";

    vector< studentQuizType >studentQuizVector;

    unordered_map< int, Student> studentMap;

    loadStudents( studentMap, studentFile);

    loadQuizzes( studentQuizVector, quizFile);

    cout << "\n\n***** Display Student Scores on Quizzes *****\n\n";

    displayStudentScores( studentMap, studentQuizVector );

	cout << "\n" ;

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
void displayVector( vector<T>& v)
{
    for ( auto obj : v )
    {
        cout << obj.toString();
    }
}

void loadStudents(unordered_map<int, Student>& studentMap, const char* studentFile)
{
	const char delimiter = '|';

	const int NUMBER_OF_ATTRBS = 3;

	double cost;

	ifstream inputFile;

	inputFile.open(studentFile);

	if (!inputFile.good())
	{
		cout << "\n\nFailed to open " << studentFile << ".";
		cout << "\nfailbit = " << inputFile.failbit << " badbit = " << inputFile.badbit;
		cout << "\nExiting the program.";

		printf("\n\nPress enter to continue...\n\n");
		cin.get();

		exit(EXIT_FAILURE); // EXIT_FAILURE and EXIT_SUCCESS are builtin constants in cstdlib.
	}

	string inputRecStr{};

	while (!inputFile.eof())
	{
		string attributes[ NUMBER_OF_ATTRBS ] {};

		// read data for the current film.

		getline(inputFile, inputRecStr);

		int attrbIndex = 0;

		for ( auto iter = inputRecStr.begin() ; iter != inputRecStr.end() ; iter++ )
		{
			if ( *iter != delimiter ) attributes[ attrbIndex ] += *iter ;

			else attrbIndex++;
		}

        int studentID = atoi(attributes[ 0 ].c_str());

		Student studentObj( studentID, attributes[ 1 ], attributes[ 2 ] );

        studentMap.emplace ( studentID, studentObj); 
	} // end while

	inputFile.close(); // Always close whatever you open.

    cout << "\n\nloadStudents: done map size = " << studentMap.size() << "\n\n";
}

void loadQuizzes(vector<studentQuizType>& studentQuizVector, const char* quizFile)
{
	const char delimiter = '|';

	const int NUMBER_OF_ATTRBS = 3;

	double cost;

	ifstream inputFile;

	inputFile.open(quizFile);

	if (!inputFile.good())
	{
		cout << "\n\nFailed to open " << quizFile << ".";
		cout << "\nfailbit = " << inputFile.failbit << " badbit = " << inputFile.badbit;
		cout << "\nExiting the program.";

		printf("\n\nPress enter to continue...\n\n");
		cin.get();

		exit(EXIT_FAILURE); // EXIT_FAILURE and EXIT_SUCCESS are builtin constants in cstdlib.
	}

	string inputRecStr{};

	while (!inputFile.eof())
	{
		string attributes[ NUMBER_OF_ATTRBS ] {};

		// read data for the current film.

		getline(inputFile, inputRecStr);

		int attrbIndex = 0;

		for ( auto iter = inputRecStr.begin() ; iter != inputRecStr.end() ; iter++ )
		{
			if ( *iter != delimiter ) attributes[ attrbIndex ] += *iter ;

			else attrbIndex++;
		}

        int studentID = atoi(attributes[ 0 ].c_str());

        int grade = atoi(attributes[ 2 ].c_str());

		studentQuizType studentQuizObj( studentID, attributes[ 1 ], grade );

        studentQuizVector.push_back ( studentQuizObj ); 
	} // end while

	inputFile.close(); // Always close whatever you open.

    cout << "\n\nloadQuizzes: done vector size = " << studentQuizVector.size() << "\n\n";
}

void displayStudentScores( unordered_map< int, Student >& studentMap, vector< studentQuizType >& studentQuizVector )
{
	// add your code here.
	for (auto map_iter = studentMap.begin(); map_iter != studentMap.end(); map_iter++ ) //iterate through map
	{
		for (auto& obj : studentQuizVector) //iterate through quiz vector
		{
			if (map_iter->first == obj.studentID) //if the IDs match up
			{
				cout << "\nStudent #" << map_iter->first << " " << //Then the student will be displayed with their grades
				map_iter->second.getLastName() << ", " << map_iter->second.getFirstName()
				<< " earned " << obj.grade << " on Quiz #" << obj.quizID;
			}
		}
	}
}