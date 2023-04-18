// AlarmObserver
// Purpose: To illustrate the Observer Pattern 
// F D'Angelo

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

#include "Alarm.h"
#include "AlarmObserver.h"

int main()
{
    // Create Alarm objects as pointers
    Alarm* Alarm1 = new Alarm( 10, "E1", "East Zone", 95.0, 55.0, 20.0 );
    Alarm* Alarm2 = new Alarm( 20, "W1", "West Zone", 95.0, 55.0, 20.0 );
    Alarm* Alarm3 = new Alarm( 30, "C1", "Central Zone", 95.0, 55.0, 20.0 );

    cout << "\n======= Display Initial Values for the Alarms ========\n";

   cout << Alarm1->toString();

    cout << Alarm2->toString();

    cout << Alarm3->toString();

    cout << "\n===============================\n";

    // Create AlarmObserver objects
    AlarmObserver observer1( "Central Console Monitor" );
    AlarmObserver observer2( "Auxillary Console Monitor" );

    // Register the AlarmObservers with Alarms
    Alarm1->registerObserver( &observer1 );
    Alarm1->registerObserver( &observer2 );

    Alarm2->registerObserver( &observer1 );
    Alarm2->registerObserver( &observer2 );

    Alarm3->registerObserver( &observer1 );
    Alarm3->registerObserver( &observer2 );   

    cout << "\n\nDEBUG: main &observer1 " << &observer1 << " &observer2 " << &observer2 << "\n";

/*
    // Add Alarms to the Observers
    observer1.addAlarm( Alarm1 );
    observer2.addAlarm( Alarm1 );

    observer1.addAlarm( Alarm2 );
    observer2.addAlarm( Alarm2 );

    observer1.addAlarm( Alarm3 );
    observer2.addAlarm( Alarm3 );
*/
    // Change Temps to trigger the notify & update actions

    cout << "\n===== First Round of Changes - Too High =====\n";

    Alarm1->setNewTemp( 110.0 );
    Alarm2->setNewTemp( 120.0 );
    Alarm3->setNewTemp( 130.0 );

    cout << "\n===== Second Round of Changes - Too Low =====\n";

    Alarm1->setNewTemp( 45.0 );
    Alarm2->setNewTemp( 50.0 );
    Alarm3->setNewTemp( 30.0 );

    cout << "\n===== Third Round of Changes - Back to Allowed =====\n";

    Alarm1->setNewTemp( 80.0 );
    Alarm2->setNewTemp( 80.0 );
    Alarm3->setNewTemp( 80.0 );

    // test the unregisterObserver function
    
    // Alarm3->unregisterObserver( &observer3 );

    // Alarm3->printObservers(); // did unregisterObserver work?

    delete Alarm1;
    delete Alarm2;
    delete Alarm3;

    return 0;
}