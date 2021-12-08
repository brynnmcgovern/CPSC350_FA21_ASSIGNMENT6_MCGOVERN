/** Brynn McGovern
    2370579
    bmcgovern@chapman.edu
    CPSC 350 section 1
    Assignment 6
    Implementation of Student class
    */

#include "Student.h"

using namespace std;

//constructor
Student::Student(){

}

//overloaded constructor
Student::Student(int i, string n, string l, double g, string m, int a){
    id = i;
    name = n;
    level = l;
    gpa = g;
    major = m;
    advisorID = a;
}

//destructor
Student::~Student(){

}

//sets the ID of the advisor to the student
void Student::setAdvisorID(int aid){
    advisorID = aid;
}

//returns the ID of the advisor to the student
int Student::getAdvisorID(){
    return advisorID;
}

//prints the student information
void Student::printStudent(){
    cout << "Student ID: " << id << " | Name: " << name << " | Grade: " << level << " | GPA: " << gpa << " | Major: " << major << " | Advisor ID: ";

    if (advisorID == -1){
        cout << "No Advisor" << endl;
    }

    else{
        cout << advisorID << endl;
    }
}

//returns student GPA
double Student::getGPA(){
    return gpa;
}

//returns student's major 
string Student::getMajor(){
    return major;
}
