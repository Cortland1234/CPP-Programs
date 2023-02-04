/*
* Program   : A-01 Basics
* Programmer: Cortland Diehm
* Purpose   : Demonstrate:
*				- Read binary data from a file into a user-defined structure and display it on the console
*				- Test for eof on binary files
*				- Use "priming" read before the loop that conitnues reading a binary file
*				- Check for errors during the read operation
*             
*/

#include <fstream> // needed for input file stream
#include <iostream>
#include <iomanip> // needed for cout format manipulation
#include <cstdlib> // needed for ext and EXIT_FAILURE


using std::cout;
using std::cin;
using std::string;
using std::setw;
using std::showpoint;
using std::ifstream;

struct gradeDataStruct
{
	char studentName[16]{};
	double testScore[4]; // Array for four test scores
};

double calcSumOfGradesForStudent(const int NUMBER_OF_TESTS, double sumOfGrades);
void calcAvgOfGradesForTest(double sumOfGradesForTest[], int testCount);

int main()
{
	const char* GRADE_FILE_NAME = "grade_dataNew.dat";

	const int NUMBER_OF_TESTS = 4;

	gradeDataStruct gradeData;

	double sumOfGradesForTest[4];
	double avgGradesForTest[4];

	int testCount = 0;

	double sumOfGrades = 0.0;
	double sumOfTest1 = 0.0;
	double sumOfTest2 = 0.0;
	double sumOfTest3 = 0.0;
	double sumOfTest4 = 0.0;

	double avgGrade;

	ifstream gradeFile(GRADE_FILE_NAME);

	if (gradeFile.fail())
	{
		cout << "Cannot open " << GRADE_FILE_NAME << ". Program will terminate. \n";

		cout << "\n\nPress any key to continue...\n\n";
		char ch = getchar();

		exit(EXIT_FAILURE);
	}

	// Notice the "priming" read before the loop that conitnues reading a binary file

	gradeFile.read((char*)&gradeData, sizeof gradeData);

	cout << "\n\n*** Student Grades ***\n\n";

	while (!gradeFile.eof())
	{
		// Check to see if an error occcurred while reading the file.
		
		if (gradeFile.bad())
		{
			cout << "An error occurred reading the grade data file, " << GRADE_FILE_NAME << ". \n";
			exit(EXIT_FAILURE);
		}
		
		sumOfGrades = 0.0; //sumOfGrades is reset each iteration so the sums of each student don't stack 
		

		for (int i = 0; i < NUMBER_OF_TESTS; i++)
		{
			sumOfGrades += gradeData.testScore[i];
		}

		//Here we are adding each individual test score to its own variable
		sumOfTest1 += gradeData.testScore[0];
		sumOfTest2 += gradeData.testScore[1];
		sumOfTest3 += gradeData.testScore[2];
		sumOfTest4 += gradeData.testScore[3];

		//After each iteration of the loop, we increment the test count variable
		testCount += 1;

		//Calling calcSumOfGradesForStudent to get the average test grade of an individual
		avgGrade = calcSumOfGradesForStudent(NUMBER_OF_TESTS, sumOfGrades);

		// set IO manipulators for cout:
		cout << showpoint << setw(6); 

		cout << "Student: " << gradeData.studentName
			<< "\n   Test score 1 : " << gradeData.testScore[0]
			<< "\n   Test score 2 : " << gradeData.testScore[1]
			<< "\n   Test score 3 : " << gradeData.testScore[2]
			<< "\n   Test score 4 : " << gradeData.testScore[3]
			<< "\n   Average test score: " << avgGrade
			<< "\n\n";

		gradeFile.read((char*)&gradeData, sizeof gradeData);
	}

	gradeFile.close();

	//Here we are taking the sumofTest variables and using these valeus to populate the sumOfGradesForTest array
	sumOfGradesForTest[0] = sumOfTest1;
	sumOfGradesForTest[1] = sumOfTest2;
	sumOfGradesForTest[2] = sumOfTest3;
	sumOfGradesForTest[3] = sumOfTest4;

	//Calling calcAvgOfGradesForTest to display the class testing averages
	calcAvgOfGradesForTest(sumOfGradesForTest, testCount);

}

//This function takes the sumOfGrades calculation from main and calculates the average test score of each student
double calcSumOfGradesForStudent(const int NUMBER_OF_TESTS, double sumOfGrades) 
{
	double avgGrade = 0.0;

	avgGrade = sumOfGrades / NUMBER_OF_TESTS;

	return avgGrade;
}

//This function takes the sumOfGradesForTest array populated in main along with the testCount variable and uses them to calculate class averages for each test
//These averages are then displayed to standard output
void calcAvgOfGradesForTest(double sumOfGradesForTest[], int testCount)
{
	double avgOfGradesForTest[4];

	avgOfGradesForTest[0] = sumOfGradesForTest[0] / testCount;
	avgOfGradesForTest[1] = sumOfGradesForTest[1] / testCount;
	avgOfGradesForTest[2] = sumOfGradesForTest[2] / testCount;
	avgOfGradesForTest[3] = sumOfGradesForTest[3] / testCount;

	cout << "\nClass Average for Each Test:"
		<< "\n   Test 1 : " << avgOfGradesForTest[0]
		<< "\n   Test 2 : " << avgOfGradesForTest[1]
		<< "\n   Test 3 : " << avgOfGradesForTest[2]
		<< "\n   Test 4 : " << avgOfGradesForTest[3]
		<< "\n\n";
}
