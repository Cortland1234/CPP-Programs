/*
* Program   : A-02 Basics Driver
*
* Purpose: Driver program for A02Basics.hpp and A02Implement.cpp
*
* Programmer: Cortland Diehm
*             
*/

#include "A02Basics.hpp"
#include <cstdio>
#include <iostream>

int main()
{
    cout << "***INSTANTIATING CITY OBJECT \"lasVegas\"***\n";

    City lasVegas(0, "Las Vegas", 646790, "United States", 135.9);

    cout << lasVegas.toString() << "\n\n";

    cout << "***INSTANTIATING CITY OBJECT \"tokyo\"***\n";

    City tokyo(1, "Tokyo", 13960000, "Japan", 847);

    cout << tokyo.toString() << "\n\n";

    cout << "***SETTER FUNCTION DEMONSTRATION FOR \"tokyo\" CITY OBJECT***\n";

    tokyo.setCityID(2);
    tokyo.setCityName("Tokyo (post-setter)");
    tokyo.setPopulation(1);
    tokyo.setCountry("The Moon");
    tokyo.setSurfaceArea(146000);

    cout << tokyo.toString() << "\n\n";

    cout << "***GETTER FUNCTION DEMONSTRATION FOR \"lasVegas\" CITY OBJECT***\n";

    cout << lasVegas.getCityID() << "\n";
    cout << lasVegas.getCityName() << "\n";
    cout << lasVegas.getPopulation() << "\n";
    cout << lasVegas.getCountry() << "\n";
    cout << lasVegas.getSurfaceArea() << "\n";
    cout << "\n";

    cout << "***INSTANTIATING CITY OBJECT \"lasVegasCopy\" VIA COPY CONSTRUCTOR***\n";
    
    City lasVegasCopy(lasVegas);

    cout << lasVegasCopy.toString() << "\n\n";

    cout << "***INSTANTIATING CITY OBJECT \"lasVegasOverload\" VIA OVERLOAD OPERATOR***\n";

    City lasVegasOverload = lasVegas;

    cout << lasVegasOverload.toString() << "\n\n";

    cout << "END OF PROGRAM. GOODBYE\n";

    return 0;
}