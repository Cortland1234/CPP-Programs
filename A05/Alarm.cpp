// Alarm.cpp
// Purpose: To illustrate the Observer Pattern 
// F D'Angelo

#include "Alarm.h"


Alarm::Alarm( int id, string name, string location, float maxTempAllowed, float minTempAllowed, float maxChangeAllowed) 
{
    this->id = id;

    this->name = name;

    this->location = location;

    this->maxTempAllowed = maxTempAllowed;

    this->minTempAllowed = minTempAllowed;

    this->maxChangeAllowed = maxChangeAllowed;
}

void Alarm::registerObserver(AlarmObserver* observerObj)
{
    observers.push_back(observerObj);
}


void Alarm::unregisterObserver(AlarmObserver* observerObj)
{
    bool found = false;

    // note: auto iter below will be: list<Observer *>::iterator  We can also use: 
    // for (list<Observer *>::iterator iter = observers.begin(); iter != observers.end() && !found; iter++) 
    
    for (auto iter = observers.begin(); iter != observers.end() && !found; ++iter)
    {
        if (*iter == observerObj)    // if we found observer which we seek
        {
            // erase element, iterator is now corrupt; save off good iterator, we'll need it later
            // newIter = observers.erase(iter);  
            observers.erase(iter);
            found = true;  // no need to loop after we've found our desired observer, !found condition fails
        }
    }
}

int Alarm::getId()
{ 
    return id;
}

string Alarm::getName()
{
    return name;
}

string Alarm::getLocation()
{
    return location;
}

void Alarm::setNewTemp( float newTemp )
{
    previousTemp = currentTemp;
    currentTemp = newTemp;

    float changeInTemp = abs(currentTemp - previousTemp);

    if ( newTemp > maxTempAllowed || newTemp < minTempAllowed || changeInTemp > maxChangeAllowed)
    {
        notify(); // tell the observers that the Temp has changed.
    }
}

float Alarm::getPreviousTemp() 
{ 
    return previousTemp; 
}

float Alarm::getCurrentTemp() 
{ 
    return currentTemp; 
}


void Alarm::printObservers()
{
    cout << "\n\nObservers for " << name << ": \n";

    for (auto observerObj : observers ) 
    {
        cout << observerObj ->getName() << "\n";
    }
}

void Alarm::notify()
{   
    std::string str; //variable that stores message containing information to pass to update()

    for (auto iter = observers.begin(); iter != observers.end(); ++iter)
    {
        str = "\nNotifying " + (*iter)->getName() + " that\n" + this->getName()
         + " in " + this->getLocation() + " changed Temp from " + std::to_string( this->getPreviousTemp() ) + " to " +
         std::to_string( this->getCurrentTemp() ) + "\n";

        (*iter)->update( str );   
    }
}

string Alarm::toString()
{
    cout << "\nAlarm::toString()\n";

    return
        "\n\nAlarm name        : " + name +
        "\nLocation          : " + location +
        "\nCurrent Temp      : " + std::to_string( currentTemp) + // convert numeric to string
        "\nPrevious Temp     : " + std::to_string( previousTemp) + 
        "\nMax Allowed Temp  : " + std::to_string( maxTempAllowed) + 
        "\nMin Allowed Temp  : " + std::to_string( minTempAllowed) + 
        "\nMax Allowed Change: " + std::to_string( maxChangeAllowed) + 
        "\n";
}