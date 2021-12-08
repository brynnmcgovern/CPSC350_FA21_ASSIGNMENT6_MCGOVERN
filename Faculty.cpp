/** Brynn McGovern
    2370579
    bmcgovern@chapman.edu
    CPSC 350 section 1
    Assignment 6
    Implementation of faculty class
    */

#include "Faculty.h"

using namespace std;

Faculty::Faculty(){

}

Faculty::Faculty(int i, string n, string l, string d){
    id = i;
    name = n;
    level = l;
    department = d;
    adviseeIDArray = new int[4];
    numStudents = 0;
    maxArray = 4;

    for (int i = 0; i < 4; ++i){
        adviseeIDArray[i] = -1;
    }
}

Faculty::~Faculty(){
    delete [] adviseeIDArray;
}

//prints the information for a faculty member
void Faculty::printFaculty(){
    cout << "Faculty ID: " << id << " | Name: " << name << " | Level: " << level << " | Dept: " << department << "\nAdvisee IDs: ";
    printAdvisees();
    cout << endl;
}

//prints the student advisees for a faculty member
void Faculty::printAdvisees(){
    if (numStudents == 0){
        cout << "No Advisees";
    }


    else{
        for (int i = 0; i < maxArray; ++i){
            if (adviseeIDArray[i] != -1){
                cout << adviseeIDArray[i];

                if (i < numStudents - 1){
                    cout << ", ";
                }
            }
        }
    }

    cout << endl;
}

//adds student advisee to faculty member
void Faculty::addAdvisee(int aid){

    if (numStudents == maxArray){
		int *temp1 = new int[numStudents];

		for (int i = 0; i < numStudents; ++i){
			temp1[i] = adviseeIDArray[i];
		}

		adviseeIDArray = new int[numStudents * 2];

        maxArray = numStudents * 2;

		for (int i = 0; i < numStudents; ++i){
			adviseeIDArray[i] = temp1[i];
		}

        for (int i = numStudents; i < numStudents * 2; ++i){
            adviseeIDArray[i] = -1;
        }

        adviseeIDArray[++numStudents] = aid;
	}

    else{
        int f = 0;

        for (int i = 0; i < maxArray; ++i){
            if (adviseeIDArray[i] == aid){
                f = maxArray;
            }
        }

        while (f < maxArray){
            if (adviseeIDArray[f] == -1){
                adviseeIDArray[f] = aid;

                ++numStudents;

                break;
            }

            ++f;
        }
    }
}

//removes student advisee from the faculty member
bool Faculty::removeAdvisee(int adviseeID){
    bool deleted = false;

    for (int i = 0; i < maxArray; ++i){
        if (adviseeIDArray[i] == adviseeID){
            adviseeIDArray[i] = -1;

            --numStudents;

            deleted = true;
        }
    }

    if (!deleted){
        cout << "Advisee not found." << endl;
    }

    return deleted;
}

//returns maximum array size
int Faculty::getArraySize(){
    return maxArray;
}

//returns the department of the faculty member
string Faculty::getDepartment(){
    return department;
}

//returns the number of student advisees
int Faculty::getNumAdvisees(){
    return numStudents;
}
