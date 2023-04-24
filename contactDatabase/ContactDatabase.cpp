//
// ContactDatabase.cpp
//
// Utilizes MVC Design Pattern to create a database for all business contacts
// 
// Allows for adding, deleting, lookup of contacts in company database, which can then be saved to file. Contacts can be read from file into program as well.
//
// Author: Cortland Diehm
//


#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

class Model;

class View;

class Controller;

class StringUtilities // to implement functionality that C++ string doesn't do.
{
public:
    static void stringToCharsCopy(char destination[], string source, int destCapacity)
    {
        int i = 0; // we need to know i after the loop ends

        for ( ; i < destCapacity - 1 && i < source.length(); i++) // destCapacity - 1 to leave room for null terminator
        {
            destination[i] = source[i];
        }

        destination[i] = '\0'; // make the last char null
    }

    static string setStringSize( string& str, int requiredSize ) // inlined for convenience
    {
        if  (str.length() < requiredSize )
        {
            while (str.length() < requiredSize )
            {
                str += ' '; // right pad str if it is too small.
            }
        }

        else if (str.length() > requiredSize )
        {
            str = str.substr( 0, requiredSize - 1 ); // use substr to truncate str if it is too large.
        }

        return str;
    }

    static bool startsWith( string& str1, string& str2)
    {
        for ( int i = 0 ; i < str1.length() && i < str2.length(); i++ )
        {
            if ( str1[ i ] != str2[ i ] ) return false;
        }

        return true;
    }

    static bool isLetter( char ch )
    {
        bool itsOK ;

        if ( ch >= 'A' && ch <= 'Z' )
        {
            itsOK = true;
        }
        else if ( ch >= 'a' && ch <= 'z' )
        {
            itsOK = true;
        }
        else if ( (int) ch >= 129 && (int)ch <= 165 )
        {
            itsOK = true;
        }
        else
        {
            itsOK = false;
        }

        return itsOK;
    }

    static bool indexOf( string str, char ch )
    {
        int foundAt = -1 ; // representing not found

        for ( int i = 0 ; i < str.length(); i++ )
        {
            if ( str[ i ] == ch )
            {
                foundAt = i ;

                break;
            }
        }
        
        return foundAt;
    }

    static char toUpperCase( char ch )
    {
        if ( ch > 'Z') return ch - 32;
        else return ch;
    }

};


struct ContactData 
{
    static const int LAST_NAME_SIZE = 25;
    static const int FIRST_NAME_SIZE = 19;
    static const int PHONE_SIZE = 13;
    static const int EMAIL_SIZE = 41;
    static const int TITLE_SIZE = 6;
    static const int ADDRESS_SIZE = 96;

private:
    char lastName[LAST_NAME_SIZE] = "";
    char firstName[FIRST_NAME_SIZE] = "";
    char phone[PHONE_SIZE] = "";
    char email[EMAIL_SIZE] = "";
    char title[TITLE_SIZE] = "";
    char address[ADDRESS_SIZE] = "";

public:
    ContactData()
    {
        #pragma warning(suppress : 4996)
        strcpy(this->lastName, "" );
        #pragma warning(suppress : 4996)
        strcpy(this->lastName, "" );
        #pragma warning(suppress : 4996)
        strcpy(this->lastName, "" );
        #pragma warning(suppress : 4996)
        strcpy(this->lastName, "" );
    }

    ContactData( char* lastName, char* firstName, char* phone, char* email, char* title, char* address)
    {
        #pragma warning(suppress : 4996)
        strcpy(this->lastName, lastName ) ;
        #pragma warning(suppress : 4996)
        strcpy(this->firstName, firstName );
        #pragma warning(suppress : 4996)
        strcpy(this->phone, phone );
        #pragma warning(suppress : 4996)
        strcpy(this->email, email ) ;
        #pragma warning(suppress : 4996)
        strcpy(this->title, title ) ;
        #pragma warning(suppress : 4996)
        strcpy(this->address, address ) ;
    }

    void setLastName( char* lastName)
    {
        #pragma warning(suppress : 4996)
        strcpy(this->lastName, lastName) ;
    }

    string getLastName()
    {
        return this->lastName ;
    }

    void setFirstName(char* firstName)
    {
        #pragma warning(suppress : 4996)
        strcpy(this->firstName, firstName);
    }
	
	string getFirstName()
    {
        return this->firstName ;
    }

    void setPhone(char* phone)
    {
        #pragma warning(suppress : 4996)
        strcpy(this->phone, phone);
    }

    string getPhone()
    {
        return this->phone ;
    }

    void setEmail(char* email)
    {
        #pragma warning(suppress : 4996)
        strcpy(this->email, email);
    }
    
    string getEmail()
    {
        return this->email ;
    }

    //setting and getting title
    void setTitle(char* title)
    {
        #pragma warning(suppress : 4996)
        strcpy(this->title, title ) ;        
    }

    string getTitle()
    {
        return this->title ;
    }    

    void setAddress(char* address)
    {
        #pragma warning(suppress : 4996)
        strcpy(this->address, address ) ;        
    }

    //setting and getting address
    string getAddress()
    {
        return this->address ;
    }    

    string toString()
    {
        // string version of attributes
        string strLastName;
        string strFirstName;
        string strPhone;
        string strEmail;
        string strTitle;
        string strAddress;

        string state =
                    "\nLast name : " + strLastName.assign(lastName) +
					"\nFirst name: " + strFirstName.assign(firstName) +
                    "\nPhone     : " + strPhone.assign(phone) +
                    "\nEmail     : " + strEmail.assign(email) + 
                    "\nTitle     : " + strTitle.assign(title) +
                    "\nAddress   : " + strAddress.assign(address) + "\n";

        return state ;
    }
};

class Model
{
private:
    vector< ContactData > contactList ; 

    vector< ContactData > tempContactList ;

public:
    Model();

    bool addNewContact(ContactData );

    bool saveToFile( string );

    bool loadFromFile( string );

    void deleteContact( string );

    vector< ContactData > findContact( string , string );

    vector< ContactData > displayList();
};

Model::Model()
{
    // nothing to do, yet
}

bool Model::addNewContact(ContactData contact )
{
    contactList.push_back( contact ) ;

    return true;
}

bool Model::saveToFile( string CONTACT_FILE )
{
    bool contactsWritten = false ;

	ofstream contactFile( CONTACT_FILE ); // declare and instantiate an output stream object.

	if (contactFile.fail()) // check to see if opening the file succeeded. If it didn't, exit the program.
	{
		cout << "Cannot open " << CONTACT_FILE << " for input.\n";
	}

    for ( auto& contactObj : contactList ) // C26817 const
    {
        // cout << "\nDEBUG: Model::saveToFile contactObj " << contactObj.toString() << "\n";

        contactFile.write((char*)&contactObj, sizeof contactObj); // write the data to the file.

        if (contactFile.fail()) // check to see if writing to the file succeeded. if it didn't, exit the program.
        {
            cout << "An error occurred writing to " << CONTACT_FILE << '\n';

            cout << "\n\nPress any key to continue...\n\n";

            return false;
        }
    }

    return true ;
}

bool Model::loadFromFile( string CONTACT_FILE )
{
    ifstream contactFile( CONTACT_FILE );

    ContactData contactObj ;
    
    bool contactsRead = false ;

    // cout << "\nDEBUG: Model::loadFromFile before read\n";
        
    while ( contactFile.read( (char*) &contactObj, sizeof contactObj ) ) 
    {
        // cout << "\nDEBUG: Model::loadFromFile contactObj " << contactObj.toString() << "\n";

        contactList.push_back( contactObj ) ;   
    }

    return true ;
}

void Model::deleteContact( string emailKey )
{
    string contactObjEmail = "";

    for (int i = 0; i < contactList.size(); i++)
    {
        contactObjEmail = contactList[i].getEmail();

        cout << "\n\nModel::deleteContact: contactObjEmail = " << contactObjEmail << "\n";

        if (contactObjEmail == emailKey)
        {
            cout << "\n\ndeleting Contact with " << contactObjEmail << " equal to " << emailKey << "\n";

            contactList.erase(contactList.begin() + i);

            break;
        }
    }
}

vector< ContactData > Model::findContact( string lastNameToFind, string firstNameToFind  ) // returning a list in case we have more than one person with same name.
{
    tempContactList.clear() ; // clear the list so we can populate it with newly found values.

    for ( auto contactObj : contactList )
    {
        string contactLastName =  contactObj.getLastName() ;
        
        string contactFirstName =  contactObj.getFirstName() ;

        /* DEBUGGING CODE
        cout << "\n\n trying to find " << contactFirstName << " " << contactLastName << "\n";

        cout << "\n\n StringUtilities::startsWith( contactLastName, lastNameToFind ) " 
            << StringUtilities::startsWith(contactLastName, lastNameToFind) << " " << contactLastName << "\n";

        cout << "\n\n StringUtilities::startsWith( contactFirstName, firstNameToFind ) "
            << StringUtilities::startsWith(contactFirstName, firstNameToFind) << " " << contactFirstName << "\n";
        */

        if ( StringUtilities::startsWith( contactLastName, lastNameToFind ) &&  
            StringUtilities::startsWith( contactFirstName, firstNameToFind ) )
        {
            tempContactList.push_back( contactObj ) ; // add found objects to the vector tempContactList
        }
    }

    return tempContactList;
}

//returns list of all contacts
vector< ContactData > Model::displayList()
{
    return contactList;
}

class Controller
{
private:
    Model model ;

public:
    Controller();

    void setModel( Model );

    static bool isNameValid( string );

    static bool isPhoneValid( string );

    static bool isEmailValid( string );

    static bool isTitleValid( string );

    static bool isAddressValid( string );
};

Controller::Controller()
{
    // pass
}

void Controller::setModel( Model model )
{
    this->model = model ;
}

bool Controller::isNameValid( string name )
{
    if ( name[0] == '-' || name[0] == ',' || name[0] == '\'' ) return false ;

    for ( int i = 0 ; i < name.length(); i++ )
    {
        if ( ! StringUtilities::isLetter(  name.at( i ) ) && name.at( i ) != '-' && name.at( i ) != '\'' )

            return false ;
    }

    return true ;
}

bool Controller::isPhoneValid( string phone )
{
    if ( phone.length() != 12 ) return false ; // nnn-nnn-nnnn

    if ( phone[ 3 ] != '-' ) return false ; // nnn-nnn-nnnn

    if ( phone[ 7 ] != '-' ) return false ; // nnn-nnn-nnnn

    for ( int i = 0 ; i < phone.length(); i++ )
    {
        if ( i != 3 && i != 7 )
        {
            if ( phone[ i ] < '0' || phone[ i ] > '9' )
            {
                return false ;
            }
        }
    }

    return true ;
}

bool Controller::isEmailValid( string email )
{
    int atsign_idx = StringUtilities::indexOf( email, '@' ) ;

    int period_idx = StringUtilities::indexOf( email, '.' ) ;

    if ( atsign_idx < 1 ) return false ; // @ must be in 2nd position or greater.

    if ( period_idx < atsign_idx ) return false ; // period must present and beyond @.

    return true ;
}

bool Controller::isTitleValid( string title ) //if title is one of these strings then return true
{
    if (title == "Mr." || title == "Mrs." || title == "Miss." || title == "Dr." || title == "None")
    {
        return true;
    }

    return false;
}

bool Controller::isAddressValid( string address ) //if address length is longer than 0 and 
{
    if ( address.length() < 1 ) return false;

    return true;
}

class View 
{
    const string EXIT = "exit" ;
	
	const string CONTACT_FILE = "contacts.txt" ;

private:
    Controller controller ;

    Model model;

    char displayMenu(); // private helper method

public:
    View( ) ;

    void setController( Controller );

    void setModel(Model);

    void processMenu();

    string promptForInput( string ) ;

    void displayContactData( ContactData );

    void displayMsg( string );

    void addNewContact();

    typedef bool ( *ptrToValidationFunction )( string) ; // guess what?

    string getInputValue( string , string , ptrToValidationFunction ); 

    void saveToFile( string );

    void loadFromFile( string );

    void deleteContact();

    void findContact();

    void displayList( vector < ContactData > );

    void getContactList(vector < ContactData > );

    //displays contact list
    void displayContactList();

    //helper functions for getting user input
    string getLName();

    string getFName();

    string getPhone();

    string getEmail();

    string getTitle();

    string getAddress();
};

// implementation of View methods

View::View( ) 	
{
    // nothing to do
}

void View::setController( Controller controller )
{
    this->controller = controller ; 
}

void View::setModel(Model model)
{
    this->model = model;
}

void View::processMenu()
{
    char EXIT_CODE = 'X' ;

    char ADD_CODE = 'A' ;

    char FIND_CODE = 'F' ;
    
    char SAVE_CODE = 'S' ;
    
    char READ_CODE = 'R' ;

    char DELETE_CODE = 'D' ;

    char LIST_CODE = 'L' ;

    Model model;

    Controller controller;

    setController( controller ) ; // view only needs to know about controller

    controller.setModel( model ) ;      // about both view and model

    char choice = '?' ;

    while ( choice != EXIT_CODE )
    {
        choice = displayMenu();

        choice = StringUtilities::toUpperCase(choice);

        if ( choice == ADD_CODE ) addNewContact();

        else if ( choice == LIST_CODE ) displayContactList(); //new option to display all contacts

        else if ( choice == FIND_CODE ) findContact();

        else if ( choice == DELETE_CODE ) deleteContact();
            
        else if ( choice == SAVE_CODE ) saveToFile( CONTACT_FILE ) ;
            
        else if ( choice == READ_CODE ) loadFromFile( CONTACT_FILE );

        else if ( choice == EXIT_CODE ) exit(0);

        else
        {
            cout << "\n" << choice << " is not a valid option.\n"  ;
        }
    }
}

char View::displayMenu()
{        
    char choice ; // using string because Scanner has nextLine but no nextChar.

    cout << "\nEnter \'L\' or \'l\' to display all contacts    : " ;

    cout <<"\nEnter \'A\' or \'a\' to add a new contact         : " ;

    cout <<"\nEnter \'F\' or \'f\' to find an existing contact  : " ;

    cout <<"\nEnter \'D\' or \'d\' to delete an existing contact: " ;
    
    cout <<"\nEnter \'S\' or \'s\' to to save all data to a file: " ;
    
    cout <<"\nEnter \'R\' or \'r\' to to read data from a file  : " ;

    cout <<"\nEnter \'X\' or \'x\' to exit the application      : " ;



    cin >> choice ;

    cin.ignore();

    return choice ; 
}   

void View::displayContactData( ContactData contact )
{
    cout << contact.toString() ;
}

void View::displayMsg( string msg )
{
    cout << "\n" + msg ;
}

void View::addNewContact()
{
    ContactData dataEnteredByUser; // This ContactData object will hold the data entered by a user.

    //Calling helper get functions for user input
    string lastName = getLName(); 
    string firstName = getFName();
    string phone = getPhone();
    string email = getEmail();
    string title = getTitle();
    string address = getAddress();

    //converting stringsto chars and setting attributes
    char lastNameChars[ContactData::LAST_NAME_SIZE]; 
    StringUtilities::stringToCharsCopy(lastNameChars, lastName, ContactData::LAST_NAME_SIZE); // had to do this because lastname.c_str() returns a const char*, not char*.
    
    dataEnteredByUser.setLastName( lastNameChars);

    char firstNameChars[ContactData::FIRST_NAME_SIZE];
    StringUtilities::stringToCharsCopy(firstNameChars, firstName, ContactData::FIRST_NAME_SIZE); // had to do this because firstName.c_str() returns a const char*, not char*.
    
    dataEnteredByUser.setFirstName(firstNameChars);

    char phoneChars[ContactData::PHONE_SIZE];
    StringUtilities::stringToCharsCopy(phoneChars, phone, ContactData::PHONE_SIZE); // had to do this because phone.c_str() returns a const char*, not char*.
    
    dataEnteredByUser.setPhone(phoneChars);

    char emailChars[ContactData::EMAIL_SIZE];
    StringUtilities::stringToCharsCopy(emailChars, email, ContactData::EMAIL_SIZE); // had to do this because email.c_str() returns a const char*, not char*.
    
    dataEnteredByUser.setEmail(emailChars);

    char titleChars[ContactData::TITLE_SIZE];
    StringUtilities::stringToCharsCopy(titleChars, title, ContactData::TITLE_SIZE);

    dataEnteredByUser.setTitle(titleChars);

    char addressChars[ContactData::ADDRESS_SIZE];
    StringUtilities::stringToCharsCopy(addressChars, address, ContactData::ADDRESS_SIZE);

    dataEnteredByUser.setAddress(addressChars);    

    //adding contact
    model.addNewContact( dataEnteredByUser ); // go directly to model method.
}

string View::getLName() //gets last name and validates name from user
{
    string lastName = "";

    string userPrompt = "", errorMsg = ""; 

    userPrompt = "Enter contact\'s LAST name : ";

    errorMsg = " is not a valid value for last name which can include only letters, apostrophe, hyphen and space.";

    ptrToValidationFunction ptr2vf = Controller::isNameValid;

    lastName = getInputValue(userPrompt, errorMsg, ptr2vf);

    return lastName;
}

string View::getFName() //gets first name and validates name from user
{
    string firstName = "";

    string userPrompt = "", errorMsg = ""; 

    userPrompt = "Enter contact\'s FIRST name  : ";

    errorMsg = " is not a valid value for first name which can include only letters, apostrophe and space.";

    ptrToValidationFunction ptr2vf = Controller::isNameValid; // point to the function that validates names.

    firstName = getInputValue(userPrompt, errorMsg, ptr2vf); // using same validation function.

    return firstName;
}

string View::getPhone() //gets phone number and validates number from user
{
    string phone = "";

    string userPrompt = "", errorMsg = ""; 

    userPrompt = "Enter phone number as ###-###-#### for contact: ";

    errorMsg = " is not a valid value, must be ###-###-####.";

    ptrToValidationFunction ptr2vf = Controller::isPhoneValid; // use phone validation method.

    phone = getInputValue(userPrompt, errorMsg, ptr2vf);

    return phone;
}

string View::getEmail() //gets email and validates email from user
{
    string email = "";

    string userPrompt = "", errorMsg = ""; 

    userPrompt = "Enter email address for contact: ";

    errorMsg = " is not a valid value for email. Must have an \'@\' in at least the 2nd position and a \'.\' beyond it.";

    ptrToValidationFunction ptr2vf = Controller::isEmailValid; // use email validation method. 

    email = getInputValue(userPrompt, errorMsg, ptr2vf);

    return email;
}

string View::getTitle() //gets title and validates title from user
{
    string title = "";

    string userPrompt = "", errorMsg = ""; 

    userPrompt = "Enter title for contact: ";

    errorMsg = " is not a valid value for a title. Please enter \'Mr.\', \'Mrs.\', \'Miss.\' ,\'Dr.\', or \'None\'";

    ptrToValidationFunction ptr2vf = Controller::isTitleValid;

    title = getInputValue(userPrompt, errorMsg, ptr2vf);

    return title;
}

string View::getAddress() //gets address and validates address from user
{
    string address = "";

    string userPrompt = "", errorMsg = ""; 

    userPrompt = "Enter address for contact: ";

    errorMsg = " is not a valid value for a address. Please enter street number, street, city, state, zip code";

    ptrToValidationFunction ptr2vf = Controller::isAddressValid;

    address = getInputValue(userPrompt, errorMsg, ptr2vf);

    return address;
}

string View::getInputValue( string userPrompt, string errorMsg, ptrToValidationFunction validator )
{
    bool validData ;

    validData = false ;

    string inputValue = promptForInput( userPrompt ) ;

    validData = validator( inputValue ) ; // controller has responsibility for validating data.

    while ( ! validData )
    {
        displayMsg( "\n" + inputValue + errorMsg ); 
        inputValue = promptForInput( userPrompt ) ;
        validData = validator(inputValue ) ; // method passed as parameter
    }

    return inputValue ;
}

string View::promptForInput(string prompt)
{
    /* DEBUGGING CODE
    static int count = 0;

    count++;

    cout << "\n\nTop of promptForInput: We\'ve called promptForInput " << count << " times.\n";
    */

    string inputValue = "";

    cout << "\n" + prompt;

    getline(cin, inputValue, '\n');

    /* lower level substitute for getline.
    while ( cin.get(ch) && ch != '\n')
    {
        inputValue += ch;
    }
    */

    /* DEBUGGING CODE
    cout << "\n\nBottom of promptForInput: We\'ve called promptForInput " << count << " times.\n";
    */

    return inputValue;
}


void View::saveToFile( string CONTACT_FILE )
{		
    if ( model.saveToFile( CONTACT_FILE ) ) // go directly to model method.
    { 
        displayMsg( "\nSuccessfully wrote data to " +  CONTACT_FILE + ".\n" ); 
    }
    
    else
    { 
        displayMsg( "\nFailed to write data to " +  CONTACT_FILE + ".\n" ); 
    }
}

void View::loadFromFile( string CONTACT_FILE )
{
    if ( model.loadFromFile( CONTACT_FILE ) ) // go directly to model method.
    { 
        displayMsg( "\nSuccessfully read data from " +  CONTACT_FILE + ".\n" ); 
    }
    
    else
    { 
        displayMsg( "\nFailed to read data from " +  CONTACT_FILE + ".\n" ); 
    }
}

void View::deleteContact()
{
    vector < ContactData > retrievedContacts ;

    ContactData contactToDelete ;

    string emailKey = "" ;

    string lastNameToFind = "", firstNameToFind = "" ;

    int indexOfContactToDelete = 0 ;

    lastNameToFind  = promptForInput( "Enter at least the partial LAST name of the contact to delete : " ) ;
    
    firstNameToFind = promptForInput( "Enter at least the partial FIRST name of the contact to delete: " ) ;

    retrievedContacts = model.findContact( lastNameToFind, firstNameToFind ) ; // go directly to model method.

    cout << "\n\n";

    displayList( retrievedContacts );

    if ( retrievedContacts.size() == 0 )
    {
        displayMsg( "\nNo entry found for " + lastNameToFind + ", " + firstNameToFind + ".\n" );

        return ;
    }

    string intermediate = promptForInput( "Enter the index of the contact to delete: " ) ;

    indexOfContactToDelete = atoi( intermediate.c_str() ) ; // convert to int after 1st converting to char array

    contactToDelete = retrievedContacts[ indexOfContactToDelete ] ;

    emailKey = contactToDelete.getEmail();

    displayMsg( "\nDeleting " + contactToDelete.getLastName() + ", " + contactToDelete.getFirstName() + " with email " + contactToDelete.getEmail() + ".\n" );

    model.deleteContact( emailKey ); // go directly to model method.
}

void View::findContact()
{
    string lastNameToFind, firstNameToFind ;

    lastNameToFind  = promptForInput("Enter at least the partial LAST name of contact to find : " ) ;
    
    firstNameToFind = promptForInput("Enter at least the partial FIRST name of contact to find: " ) ;

    displayList( model.findContact( lastNameToFind, firstNameToFind  ) );
}

void View::displayList( vector < ContactData > foundContacts )
{
    if ( foundContacts.size() == 0 )
    {
        cout << "\nNo contacts found\n\n" ;
    }
    else
    {
        int i = 0 ;

        for ( ContactData cdObject : foundContacts )
        {
            cout << i << ". " << cdObject.toString() ;

            i ++ ;
        }
    }
}

void View::getContactList( vector < ContactData > contactList )
{
    int i = 0;

    for ( ContactData contactObj : contactList )
    {
        cout << i << ". " << contactObj.toString() ;

        i ++ ;
    } 
}

void View::displayContactList() //calls model function displayList()
{
    getContactList(model.displayList());
}

int main( )
{
    View view;

    view.processMenu();
}