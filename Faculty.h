/** Brynn McGovern
    2370579
    bmcgovern@chapman.edu
    CPSC 350 section 1
    Assignment 6
    Header file for faculty class; inherits person class
    */

#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include <array>
#include "DoublyLinkedList.h"
#include "Person.h"

using namespace std;

class Faculty : public Person{
    public:
        string department;
        unsigned int numStudents;
        unsigned int maxArray;
        int *adviseeIDArray;

        Faculty();
        Faculty(int i, string n, string l, string d);
        ~Faculty();

        void printFaculty();

        void printAdvisees();

        void addAdvisee(int aid);
        bool removeAdvisee(int adviseeID);

        int getArraySize();

        string getDepartment();
        int getNumAdvisees();
};

#endif
