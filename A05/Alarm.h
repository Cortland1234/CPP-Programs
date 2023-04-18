// AlarmObserver
// Purpose: To illustrate the Observer Pattern 
// F D'Angelo

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <iterator>

using std::cout;   // prefered to: using namespace std;
using std::endl;
using std::setprecision;
using std::string;
using std::list;


#include "AlarmObserver.h"


class Alarm
{ 
private:

    int id;

    string name;

    string location;

    int status;

    float maxTempAllowed;
    
    float minTempAllowed;

    float maxChangeAllowed;

    float currentTemp;

    float previousTemp;
      
    list<AlarmObserver*> observers;

public:

    Alarm( int id, string name, string location, float maxTempAllowed, float minTempAllowed, float maxChangeAllowed); 

    // Note: destructor body shown to provide a place to add 
    // anything else that needs to be done.

    ~Alarm(){ }  ;

    int getId() ;

    string getLocation() ;

    float getPreviousTemp();

    float getCurrentTemp();

    void setNewTemp( float );

    string getName();

    string toString();

    void printObservers();

    void registerObserver(AlarmObserver*);

    void unregisterObserver(AlarmObserver* );

    void notify() ;
}; 