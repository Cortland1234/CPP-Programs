/*
** Program	: A02Basics.hpp
**
** Purpose	: To declare the properties and methods of the City base class.
**
** Cortland Diehm
**/

#ifndef _CITY
#define _CITY

#include <string>
#include <iostream>

using namespace std;

class City
{
private:
    int cityID = 0;
    string cityName = "";
    int population = 0;
    string originCountry = "";
    double surfaceArea = 0.0;


public:
    City();

    City(int, string, int, string, double);

    void setCityID(int);

    void setCityName(string);

    void setPopulation(int);

    void setCountry(string);

    void setSurfaceArea(double);

    int getCityID();

    string getCityName();

    int getPopulation();

    string getCountry();

    double getSurfaceArea();

    City(const City & other);

    void operator=(City& city);

    virtual string toString();
};

#endif