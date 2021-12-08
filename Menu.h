/** Brynn McGovern
    2370579
    bmcgovern@chapman.edu
    CPSC 350 section 1
    Assignment 6
    Header for menu class
    */

#ifndef MENU_H
#define MENU_H

#include <iostream>

using namespace std;

class Menu
{
    private:
        int response;
    public:
        Menu();
        ~Menu();

        void displayMenu();
};

#endif
