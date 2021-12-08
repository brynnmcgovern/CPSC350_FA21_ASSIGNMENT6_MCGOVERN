/** Brynn McGovern
    2370579
    bmcgovern@chapman.edu
    CPSC 350 section 1
    Assignment 6
    Main class
    */

#include "Simulation.h"

using namespace std;

int main (int argc, char** argv)
{
    Simulation S1;
    Menu menu;

    S1.readFromFile();

    menu.displayMenu();

    S1.run();

    S1.writeToFile();

    return 0;
}
