#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include "Student.h"
#include <vector>

class StudentManager {
private:
    vector<Student> students;

    bool rollExists(const string& roll);

public:
    void loadFromFile();
    void saveToFile();

    void addStudent();
    void displayStudents();
    void searchStudent();
    void editStudent();
    void deleteStudent();
};

#endif
