/** Brynn McGovern
    2370579
    bmcgovern@chapman.edu
    CPSC 350 section 1
    Assignment 6
    Implementation of Simulation class
    */

#include <string>
#include <fstream>
#include "Simulation.h"

using namespace std;

Simulation::Simulation(){};
Simulation::~Simulation(){};

void Simulation::readFromFile(){
    ifstream masterStudentFile;
    ifstream masterFacultyFile;


    int i = 0;
    string n = "";
    string l = "";
    double g = 0;
    string m = "";
    int a = -1;

    string line;
    int numStudents = 0;
    int lineCount = 1;

	masterStudentFile.open("studentTable.txt");

    if (masterStudentFile.is_open()){
        try{

       		getline(masterStudentFile, line);

            if (line != ""){
                numStudents = stoi(line);
            }
        }

        catch (exception e){
            cout << " Incorrect file format " << endl;
        }


        for (int j = 0; j < (7 * numStudents); ++j){
            getline(masterStudentFile, line);

            switch (lineCount){
                case 1:{
                    if (line != "--"){
                        cout << " Incorrect file format" << endl;
                    }

                    break;
                }

                case 2:{
                    try{
                   		i = stoi(line);
                    }

                    catch (exception e){
                        cout << " Incorrect file format " << endl;
                    }

                    break;
                }

                case 3:{
                    n = line;

                    break;
                }

                case 4:{
                    l = line;

                    break;
                }

                case 5:{
                    try{
                   		g = stod(line);
                    }

                    catch (exception e){
                        cout << " Incorrect file format " << endl;
                    }

                    break;
                }

                case 6:{
                    m = line;

                    break;
                }


                case 7:{
                    try{
                   		a = stoi(line);

                        Student *student = new Student(i, n, l, g, m, a);

                        TreeNode<Student> *studentNode = new TreeNode<Student>(student, i);

                        masterStudent.insert(studentNode);
                    }

                    catch (exception e){
                        cout << " Incorrect file format " << endl;
                    }
                    break;
                }

                default:break;
            }

            ++lineCount;

            if (lineCount > 7){
                lineCount = 1;
            }
        }
    }

    else{
        cout << "File not found. Simulation will start with no students in the database. " << endl;
    }

    masterStudentFile.close();



    int numFaculty = 0;

    int fi = 0;
    string fn = "";
    string fl = "";
    string fd = "";
    int advID = 0;

    lineCount = 1;
    int createdCount = 0;

    int na = 0;

    masterFacultyFile.open("facultyTable.txt");

    if (masterFacultyFile.is_open()){
        try{

       		getline(masterFacultyFile, line);

            if (line != ""){
                numFaculty = stoi(line);
            }
        }

        catch (exception e){
            cout << "Incorrect file format" << endl;
        }


        while (getline(masterFacultyFile, line)){
            switch (lineCount){
                case 1:{
                    if (line != "--"){
                        cout << "Incorrect file format" << endl;
                    }

                    break;
                }

                case 2:{
                    try{
                   		fi = stoi(line);
                    }

                    catch (exception e){
                        cout << "Incorrect file format" << endl;
                    }

                    break;
                }

                case 3:{
                    fn = line;

                    break;
                }

                case 4:{
                    fl = line;

                    break;
                }

                case 5:{
                    fd = line;

                    break;
                }


                case 6:{
                    try{
                   		na = stoi(line);
                    }

                    catch (exception e){
                        cout << "Incorrect file format" << endl;
                    }

                    Faculty *faculty = new Faculty(fi, fn, fl, fd);

                    createdCount++;

                    for (int k = 0; k < na; ++k){
                        getline(masterFacultyFile, line);

                        try{
                       		advID = stoi(line);
                        }

                        catch (exception e){
                            cout << "Incorrect file format" << endl;
                        }

                        faculty->addAdvisee(advID);
                    }


                    TreeNode<Faculty> *facultyNode = new TreeNode<Faculty>(faculty, fi);

                    masterFaculty.insert(facultyNode);

                    break;
                }

                default:break;
            }

            ++lineCount;

            if (createdCount == numFaculty){
                break;
            }

            if (lineCount > 6){
                lineCount = 1;
            }
        }
    }

    else{
        cout << "File not found. Simulation will start with no faculty members in the database." << endl;
    }

    masterFacultyFile.close();
}

void Simulation::writeToFile(){

    ofstream masterStudentFile;
    ofstream masterFacultyFile;

    masterStudentFile.open("studentTable.txt");


    if (masterStudentFile.is_open()){
        masterStudentFile << masterStudent.getSize() << endl;

        TreeNode<Student> *studentRoot = masterStudent.getRoot();

        outputMasterStudent(studentRoot, "studentTable.txt");
    }

    masterStudentFile.close();



    masterFacultyFile.open("facultyTable.txt");


    if (masterFacultyFile.is_open()){
        masterFacultyFile << masterFaculty.getSize() << endl;

        TreeNode<Faculty> *facultyRoot = masterFaculty.getRoot();

        outputMasterFaculty(facultyRoot, "facultyTable.txt");
    }

    masterFacultyFile.close();

    cout << " The database has been written to the files. " << endl;
}

/**
Recursive print function for student tree
*/
void Simulation::printMasterStudent(TreeNode<Student> *s){
    if (s != NULL){
        if (s->left != NULL){
            printMasterStudent(s->left);
        }

        s->data->printStudent();

        if (s->right != NULL){
            printMasterStudent(s->right);
        }
    }

    else{
        cout << "Student tree is empty" << endl;
    }
}

/**
Recursive print function for faculty tree
*/
void Simulation::printMasterFaculty(TreeNode<Faculty> *f){
    if (f != NULL){
        if (f->left != NULL){
            printMasterFaculty(f->left);
        }

        f->data->printFaculty();

        if (f->right != NULL){
            printMasterFaculty(f->right);
        }
    }

    else{
        cout << "Faculty tree is empty" << endl;
    }
}

/**
function to print student tree to file
*/
void Simulation::outputMasterStudent(TreeNode<Student> *stud, string s){
    ofstream f;
    f.open(s);

    if (stud != NULL){
        f << "--\n";


        f << stud->data->getID() << "\n" << stud->data->getName() << "\n" << stud->data->getGrade() << "\n" << stud->data->getGPA() << "\n" << stud->data->getMajor() << "\n" << stud->data->getAdvisorID() << endl;

        if (stud->left != NULL){
            outputMasterStudent(stud->left, s);
        }

        if (stud->right != NULL){
            outputMasterStudent(stud->right, s);
        }
    }

    f.close();
}

/**
function to print faculty tree to file
*/
void Simulation::outputMasterFaculty(TreeNode<Faculty> *fac, string s){
    ofstream f;
    f.open(s);

    if (fac != NULL){
        f << "--\n";

        f << fac->data->getID() << "\n" << fac->data->getName() << "\n" << fac->data->getGrade() << "\n" << fac->data->getDepartment() << endl;

        f << fac->data->getNumAdvisees() << "\n";

        if (fac->data->getNumAdvisees() > 0){
            for (int i = 0; i < fac->data->maxArray; ++i){

                if (fac->data->adviseeIDArray[i] != -1){
                    f << fac->data->adviseeIDArray[i] << endl;
                }
            }
        }

        if (fac->left != NULL){
            outputMasterFaculty(fac->left, s);
        }

        if (fac->right != NULL){
            outputMasterFaculty(fac->right, s);
        }
    }

    else{
        cout << "Faculty tree is empty" << endl;
    }

    f.close();
}

/**
creates student node and adds it to student tree
*/
void Simulation::addStudent(){
    cout << "Adding a new student: " << endl;

    int i;
    string n;
    string l;
    double g;
    string m;
    int a;

    int answerInt = 0;
    double answerDbl = 0;
    string answer = "";

    while (true){
        cout << " ID of student: ";

        answerInt = 0;
        answer = "";
        cin >> answer;

        try{
            i = stoi(answer);

            if (i > 0){
                if (!masterStudent.isInTree(i)){
                    break;
                }

                else{
                    cout << " Student already exists. Try another." << endl;
                }
            }

            else{
                cout << " Invalid input. Try again." << endl;
            }
        }

        catch (exception e){
            cout << " Invalid input. Try again." << endl;
        }
    }

    string line;

    cout << " Name of student: ";
    cin.ignore();
    getline(cin, n);

    cout << " Grade: ";
    getline(cin, l);

    while (true){
        cout << " GPA: ";

        answerDbl = 0;
        answer = "";
        cin >> answer;

        try{
            g = stod(answer);

            if (g > 0 && g < 5){
                break;
            }

            else{
                cout << " Please enter a GPA between 0 and 4" << endl;
            }
        }

        catch (exception e){
            cout << " Invalid input. Try again." << endl;
        }
    }

    cout << " Major: ";
    cin.ignore();
    getline(cin, m);

    //prompt for advisor
    if (!masterFaculty.isEmpty()){
        cout << "Does this student have an advisor?\n1 - Yes\n2 - No" << endl;

        while (true){
            answerInt = 0;
            answer = "";
            cin >> answer;

            try{
                answerInt = stoi(answer);

                if (answerInt == 1 || answerInt == 2){
                    break;
                }
            }

            catch (exception e){
                cout << "Invalid input. Try again." << endl;
            }
        }

        // if student already has advisor, prompt for advisor ID
        if (answerInt == 1){
            cout << " Advisor ID: ";

            while (true){
                answerInt = 0;
                answer = "";
                cin >> answer;


                try{
                    a = stoi(answer);


                    if (masterFaculty.isInTree(a)){
                        Faculty *faculty = masterFaculty.search(a);

                        faculty->addAdvisee(i);

                        break;
                    }

                    else{
                        cout << " Faculty member not found.";
                    }
                }

                catch (exception e){
                    cout << " Please enter an integer.";
                }
            }
        }

        else{
            a = -1;
        }
    }

    else{
        a = -1;
    }

    Student *student = new Student(i, n, l, g, m, a);

    TreeNode<Student> *studentNode = new TreeNode<Student>(student, i);

    masterStudent.insert(studentNode);
}

/**
creates faculty node and adds it to faculty tree
*/
void Simulation::addFaculty(){
    cout << " Adding a faculty member: " << endl;

    int i;
    string n;
    string l;
    string d;

    int answerInt = 0;
    int numEntries = 0;
    string answer = "";

    while (true){
        cout << "ID of faculty member: ";

        answerInt = 0;
        answer = "";
        cin >> answer;

        try{
            i = stoi(answer);

            if (i > 0){
                break;
            }
        }

        catch (exception e){
            cout << "Invalid input. Try again." << endl;
        }
    }

    string line;

    cout << "Name of faculty member: ";
    cin.ignore();
    getline(cin, n);

    cout << "Level of faculty member: ";
    getline(cin, l);

    cout << "Department of faculty member: ";
    getline(cin, d);

    Faculty *faculty = new Faculty(i, n, l, d);

    // prompts for student advisee
    if (!masterStudent.isEmpty()){
        cout << "Does this facuty member have advisees?\n1 - Yes\n2 - No" << endl;

        while (true){
            answerInt = 0;
            answer = "";
            cin >> answer;

            try{
                answerInt = stoi(answer);

                if (answerInt == 1 || answerInt == 2){
                    break;
                }
            }

            catch (exception e){
                cout << "Invalid input. Try again: ";
            }
        }

        //prompts for number of student advisees
        if (answerInt == 1 && !masterStudent.isEmpty()){
            cout << "How many students does this faculty member advise?" << endl;

            while (true){
                cout << "Please enter an integer: ";

                answerInt = 0;
                answer = "";
                cin >> answer;


                try{
                    answerInt = stoi(answer);

                    if (answerInt > 0 && answerInt <= masterStudent.getSize()){
                        numEntries = answerInt;
                        break;
                    }

                    else{
                        cout << "Please enter an integer less than or equal to " << masterStudent.getSize() << "." << endl;
                    }
                }

                catch (exception e){
                    cout << "Invalid input. Please enter an integer.";
                }
            }

            for (int v = 0; v < numEntries; ++v){
                while (true){
                    cout << "Please enter a Student ID (" << numEntries - v << " remaining): ";

                    answerInt = 0;
                    answer = "";

                    cin >> answer;

                    try{
                        answerInt = stoi(answer);


                        if (masterStudent.isInTree(answerInt)){
                            faculty->addAdvisee(answerInt);


                            masterStudent.search(answerInt)->setAdvisorID(i);

                            break;
                        }

                        else{
                            cout << "Student not found.";
                        }
                    }

                    catch (exception e){
                        cout << "Please enter an integer.";
                    }
                }
            }
        }
    }

    TreeNode<Faculty> *facultyNode = new TreeNode<Faculty>(faculty, i);

    masterFaculty.insert(facultyNode);
}


/**
creates student object and student node, then inserts node to student tree
*/
void Simulation::addStudentFromFile(int i, string n, string l, double g, string m, int a){
    Student *student = new Student(i, n, l, g, m, a);

    TreeNode<Student> *studentNode = new TreeNode<Student>(student, i);

    masterStudent.insert(studentNode);
}


/**
creates faculty object and faculty node, then adds it to faculty tree
*/
void Simulation::addFacultyFromFile(int i, string n, string l, string d){
    Faculty *faculty = new Faculty(i, n, l, d);

    TreeNode<Faculty> *facultyNode = new TreeNode<Faculty>(faculty, i);

    masterFaculty.insert(facultyNode);


}

/**
displays student info
*/
void Simulation::displayStudentInfo(int i){
    if (masterStudent.isInTree(i)){
        masterStudent.search(i)->printStudent();
    }

    else{
        cout << "Student is not in system. Returning to Menu " << endl;
    }
}

/**
displays faculty info
*/
void Simulation::displayFacultyInfo(int i){
    if (masterFaculty.isInTree(i)){
        masterFaculty.search(i)->printFaculty();
    }

    else{
        cout << " Faculty member is not in system.Returning to Menu " << endl;
    }
}

TreeNode<Student>* Simulation::getMasterStudentRoot(){
    return masterStudent.getRoot();
}

TreeNode<Faculty>* Simulation::getMasterFacultyRoot(){
    return masterFaculty.getRoot();
}


int Simulation::checkInput(int l, int u, string m){
    string answer;
    int answerInt;

    while (true){
        cout << "\n" << m;

        answerInt = 0;
        answer = "";
        cin >> answer;

        try{
            answerInt = stoi(answer);

            if (answerInt < u && answerInt > l){

                return answerInt;
            }

            else{
                cout << "Please try again." << endl;
            }
        }

        catch (exception e){
            cout << "Invalid input. Please enter an integer.";
        }
    }
}

void Simulation::run(){
    bool running = true;

    while (running){
        int response;

        response = checkInput(-1, 15, "Please choose an option from the menu: ");

        switch (response){

            case 1:{
                if (masterStudent.isEmpty()){
                    cout << " No students in database. " << endl;

                    break;
                }

                cout << endl;
                printMasterStudent(masterStudent.getRoot());

                break;
            }

            case 2:{
                if (masterFaculty.isEmpty()){
                    cout << "No faculty members in database " << endl;

                    break;
                }

                cout << endl;
                printMasterFaculty(masterFaculty.getRoot());

                break;
            }

            case 3:{
                if (masterStudent.isEmpty()){
                    cout << "No students in database" << endl;

                    break;
                }

                int t;

                while (true){
                    t = checkInput(0, 10000, "Please enter a Student ID: ");

                    if (masterStudent.isInTree(t)){
                        displayStudentInfo(t);

                        break;
                    }

                    else{
                        cout << "Student is not in database. Please enter a valid Student ID." << endl;
                    }
                }

                break;
            }

            case 4:{
                if (masterFaculty.isEmpty()){
                    cout << "No faculty members in database " << endl;

                    break;
                }

                int t;

                while (true){
                    t = checkInput(0, 10000, "Please enter a Faculty ID: ");

                    if (masterFaculty.isInTree(t)){
                        displayFacultyInfo(t);

                        break;
                    }
                }

                break;
            }


            case 5:{
                if (masterStudent.isEmpty()){
                    cout << "No students in database " << endl;

                    break;
                }

                int t;

                cout << "Current students in database:" << endl;
                printMasterStudent(masterStudent.getRoot());

                while (true){
                    t = checkInput(0, 10000, "Please enter a Student ID: ");

                    if (masterStudent.isInTree(t)){
                        displayFacultyInfo(masterStudent.search(t)->getAdvisorID());

                        break;
                    }

                    else{
                        cout << "Student is not in database. Please enter a valid Student ID." << endl;
                    }
                }

                break;
            }

            case 6:{
                if (masterFaculty.isEmpty()){
                    cout << "No faculty members in database " << endl;

                    break;
                }

                int t;

                cout << "Current faculty members in database:" << endl;
                printMasterFaculty(masterFaculty.getRoot());

                while (true){
                    t = checkInput(0, 10000, "Please enter a Faculty ID: ");

                    if (masterFaculty.isInTree(t)){
                        Faculty *fac = masterFaculty.search(t);

                        for (int i = 0; i < fac->getArraySize(); ++i){
                            if (fac->adviseeIDArray[i] != -1){
                                displayStudentInfo(fac->adviseeIDArray[i]);
                            }
                        }

                        break;
                    }

                    else{
                        cout << "Faculty member is not in database. Please enter a valid ID." << endl;
                    }
                }

                break;
            }

            case 7:{
                addStudent();

                cout << "Student has been added. Returning to Menu...(Press '0' to display options)" << endl;

                break;
            }

            case 8:{
                int t;

                if (masterStudent.isEmpty()){
                    cout << "No students in database" << endl;

                    break;
                }

                cout << "Current students in database:";
                printMasterStudent(masterStudent.getRoot());

                while (true){
                    t = checkInput(0, 10000, "Please enter a Student ID: ");

                    if (masterStudent.isInTree(t)){
                        if (masterStudent.search(t)->getAdvisorID() != -1){
                            masterFaculty.search(masterStudent.search(t)->getAdvisorID())->removeAdvisee(t);
                        }

                        masterStudent.deleteNode(t);

                        cout << "Student has been deleted. Returning to Menu...(Press '0' to display options)" << endl;

                        break;
                    }

                    else{
                        cout << "\nStudent is not in database. Please enter a valid Student ID." << endl;
                    }
                }

                break;
            }

            case 9:{
                addFaculty();

                cout << "Faculty member has been added. Returning to Menu...(Press '0' to display options)" << endl;

                break;
            }

            case 10:{
                int t;

                if (masterFaculty.isEmpty()){
                    cout << "No faculty members in database" << endl;

                    break;
                }

                cout << "Current faculty members in database:";
                printMasterFaculty(masterFaculty.getRoot());

                while (true){
                    t = checkInput(0, 10000, "Please enter a Faculty ID: ");

                    if (masterFaculty.isInTree(t)){
                        if (masterFaculty.search(t)->numStudents > 0){
                            for (int i = 0; i < masterFaculty.search(t)->maxArray; ++i){
                                if (masterFaculty.search(t)->adviseeIDArray[i] != -1){
                                    masterStudent.search(masterFaculty.search(t)->adviseeIDArray[i])->setAdvisorID(-1);
                                }
                            }
                        }
                        masterFaculty.deleteNode(t);

                        cout << "Faculty member has been deleted. Returning to Menu...(Press '0' to display options)" << endl;

                        break;
                    }

                    else{
                        cout << "Faculty member is not in database. Please enter a valid Faculty ID." << endl;
                    }
                }

                break;
            }

            // CHANGE A STUDENT’S ADVISOR
            case 11:{
                if (masterFaculty.isEmpty()){
                    cout << "No faculty members in database " << endl;

                    break;
                }

                if (masterStudent.isEmpty()){
                    cout << "No students in database" << endl;

                    break;
                }

                int f;
                int s;

                cout << "Current students in database:";
                printMasterStudent(masterStudent.getRoot());

                while (true){
                    s = checkInput(0, 10000, "Please enter a Student ID: ");

                    if (masterStudent.isInTree(s)){
                        while (true){
                            f = checkInput(0, 10000, "Please enter a Faculty ID: ");

                            if (masterFaculty.isInTree(f)){
                                break;
                            }

                            else{
                                cout << "Faculty member is not in database. Please enter a valid ID." << endl;
                            }
                        }

                        break;
                    }

                    else{
                        cout << "Student is not in database. Please enter a valid Student ID." << endl;
                    }
                }

                masterStudent.search(s)->setAdvisorID(f);

                masterFaculty.search(f)->addAdvisee(s);

                cout << "Advisor has been changed. Returning to Menu...(Press '0' to display options)" << endl;

                break;
            }

            // REMOVE ADVISEE FROM FACULTY MEMBER
            case 12:{
                if (masterFaculty.isEmpty()){
                    cout << "No faculty members in database" << endl;

                    break;
                }

                if (masterStudent.isEmpty()){
                    cout << "No students in database" << endl;

                    break;
                }

                int f;
                int s;

                cout << "Current faculty members in database:";
                printMasterFaculty(masterFaculty.getRoot());

                while (true){
                    f = checkInput(0, 10000, "Please enter a Faculty ID: ");

                    if (masterFaculty.isInTree(f)){
                        cout << "This Faculty Member currently avises: ";
                        masterFaculty.search(f)->printAdvisees();

                        while (true){
                            s = checkInput(0, 10000, "Please enter a Student ID: ");

                            if (masterStudent.isInTree(s)){
                                break;
                            }

                            else{
                                cout << "Student is not in database. Please enter a valid Student ID." << endl;
                            }
                        }

                        break;
                    }

                    else{
                        cout << "Faculty member is not in database. Please enter a valid ID." << endl;
                    }
                }

                if (masterFaculty.search(f)->removeAdvisee(s)){
                    masterStudent.search(s)->setAdvisorID(-1);

                    cout << "Advisor has been removed. Returning to Menu...(Press '0' to display options)" << endl;
                }

                else{
                    cout << "Advisor wasn't able to be removed. Returning to Menu...(Press '0' to display options)" << endl;
                }

                break;
            }

            // rollback
            case 13:{
                break;
            }

            // exit
            case 14:{
                running = false;

                cout << "Exiting Application. Goodbye." << endl;

                break;
            }

            default:{
                Menu m;

                m.displayMenu();

                break;
            }
        }
    }
}

// attempt to create a rollback feature; doesn't work properly
// void Simulation::saveTree(TreeNode<Student> *n)
// {
//     if (n != NULL)
//     {
//         masterStudent1.insert(n);
//
//         if (n->left != NULL)
//         {
//             saveTree(n->left);
//         }
//
//         if (n->right != NULL)
//         {
//             saveTree(n->right);
//         }
//     }
// }
