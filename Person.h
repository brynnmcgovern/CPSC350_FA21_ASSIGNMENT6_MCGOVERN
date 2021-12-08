/** Brynn McGovern
    2370579
    bmcgovern@chapman.edu
    CPSC 350 section 1
    Assignment 6
    Header for Person class
    */

#include <iostream>
#ifndef PERSON_H
#define PERSON_H

using namespace std;

class Person
{
    public:
        int id;
        string name;
        string level;

        Person();
        ~Person();

        int getID();
        void setID(int v);

        string getName();
        string getGrade();
};

#endif
