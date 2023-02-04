/*
** Program	: A02Implement.cpp
**
** Purpose	: To implement methods of the City base class.
**
** Cortland Diehm
**/

#include "A02Basics.hpp"
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

City::City()
{
    setCityID(0);
    setCityName("");
    setPopulation(0);
    setCountry("");
    setSurfaceArea(0.0);
}

//Copy constructor method
City::City(const City & other)
{
    this->cityID = other.cityID;
    this->cityName = other.cityName;
    this->population = other.population;
    this->originCountry = other.originCountry;
    this->surfaceArea = other.surfaceArea;
}

City::City(int cityID, string cityName, int population, string countryName, double surfaceArea)
{

    setCityID(cityID);
    setCityName(cityName);
    setPopulation(population);
    setCountry(countryName);
    setSurfaceArea(surfaceArea);
}

void City::setCityID(int cityID)
{
    this->cityID = cityID;
}

void City::setCityName(string cityName)
{
    this->cityName = cityName;
}

void City::setPopulation(int population)
{
    this->population = population;
}

void City::setCountry(string originCountry)
{
    this->originCountry = originCountry;
}

void City::setSurfaceArea(double surfaceArea)
{
    this->surfaceArea = surfaceArea;
}

int City::getCityID()
{
    return cityID;
}

string City::getCityName()
{
    return cityName;
}

int City::getPopulation()
{
    return population;
}

string City::getCountry()
{
    return originCountry;
}

double City::getSurfaceArea()
{
    return surfaceArea;
}

string City::toString()
{
    stringstream strm ;

    strm << "\n=================CITY DATA================="
    << "\nCity ID                     : " << cityID
    << "\nCity Name                   : " << cityName
    << "\nCity Population             : " << population
    << "\nCountry of Origin           : " << originCountry
    << "\nCity Surface Area (mi^2)    : " << surfaceArea
    << "\n==========================================="
    << "\n";

    return strm.str();           
}

//Operator overload method
void City::operator=(City& city)
{
    std::cout << "Operator Overload" << std::endl;
    this->cityID = city.cityID;
    this->cityName = city.cityName;
    this->population = city.population;
    this->originCountry = city.originCountry;
    this->surfaceArea = city.surfaceArea;
}