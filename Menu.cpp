/** Brynn McGovern
    2370579
    bmcgovern@chapman.edu
    CPSC 350 section 1
    Assignment 6
    Implementation of Menu class
    */

#include "Menu.h"

using namespace std;

Menu::Menu(){

}
Menu::~Menu(){

}

/**
displays the options to the user
*/
void Menu::displayMenu(){
    cout << "Student and Faculty Database: ";
    cout << "\n1.  Print all students and their information" << endl;
    cout << "2.  Print all faculty and their information" << endl;
    cout << "3.  Find and display student information" << endl;
    cout << "4.  Find and display faculty information" << endl;
    cout << "5.  Get faculty advisor of student" << endl;
    cout << "6.  Get advisees of a faculty member" << endl;
    cout << "7.  Add a new student" << endl;
    cout << "8.  Delete a student" << endl;
    cout << "9.  Add a new faculty member" << endl;
    cout << "10. Delete a faculty member" << endl;
    cout << "11. Change a student’s advisor" << endl;
    cout << "12. Remove an advisee from a faculty member" << endl;
    cout << "13. Rollback" << endl;
    cout << "14. Exit" << endl;
}
