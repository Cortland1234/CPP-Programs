// AlarmObserver.h
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

// #include "Alarm.h"


class AlarmObserver
{
private:
    string name;

public:
    AlarmObserver() = default;  // default constructor

    AlarmObserver ( string ); 

    ~AlarmObserver() { } ;  // empty destructor because I can't think of anything for it to do.

    string getName();
  
    string toString() ;  

    void update() ;        

    void update( string ) ;    
};