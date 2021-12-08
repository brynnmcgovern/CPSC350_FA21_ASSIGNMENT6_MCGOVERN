/** Brynn McGovern
    2370579
    bmcgovern@chapman.edu
    CPSC 350 section 1
    Assignment 6
    Implementation of Person class
    */

#include "Person.h"

using namespace std;

Person::Person(){};
Person::~Person(){};

//returns ID
int Person::getID(){
    return id;
}

//sets the ID
void Person::setID(int v){
    id = v;
}

//gets the name
string Person::getName(){
    return name;
}

//gets the grade level
string Person::getGrade(){
    return level;
}
