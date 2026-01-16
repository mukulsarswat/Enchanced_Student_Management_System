#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
public:
    string name, rollNo, branch, course, email;

    Student() {}
    Student(string n, string r, string b, string c, string e);

    void print() const;
};

#endif
