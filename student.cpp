#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(string n, string r, string b, string c, string e) {
    name = n;
    rollNo = r;
    branch = b;
    course = c;
    email = e;
}

void Student::print() const {
    cout << "\nName   : " << name
         << "\nRoll   : " << rollNo
         << "\nBranch : " << branch
         << "\nCourse : " << course
         << "\nEmail  : " << email
         << "\n------------------------\n";
}
