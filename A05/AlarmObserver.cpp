// AlarmObserver.cpp
// Purpose: To illustrate the Observer Pattern 
// F D'Angelo


#include "AlarmObserver.h"


AlarmObserver::AlarmObserver ( string name) 
{ 
    this->name = name;
}

string AlarmObserver::getName()
{
    return name;
}

string AlarmObserver::toString()
{
    return "\nAlarm Observer " + name + "\n";
}

void AlarmObserver::update( string notif )
{
    cout << notif; //Takes notification from notfy() method and displays it
}