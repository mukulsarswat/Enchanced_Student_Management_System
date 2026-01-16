#include "StudentManager.h"
#include <iostream>
#include <fstream>
using namespace std;

bool StudentManager::rollExists(const string& roll) {
    for (const auto& s : students)
        if (s.rollNo == roll) return true;
    return false;
}

void StudentManager::loadFromFile() {
    students.clear();
    ifstream fin("Student.txt");
    string line;

    while (getline(fin, line)) {
        Student s;
        size_t pos;

        pos = line.find('|'); s.name = line.substr(0, pos); line.erase(0, pos+1);
        pos = line.find('|'); s.rollNo = line.substr(0, pos); line.erase(0, pos+1);
        pos = line.find('|'); s.branch = line.substr(0, pos); line.erase(0, pos+1);
        pos = line.find('|'); s.course = line.substr(0, pos); line.erase(0, pos+1);
        s.email = line;

        students.push_back(s);
    }
}

void StudentManager::saveToFile() {
    ofstream fout("Student.txt");
    for (auto& s : students)
        fout << s.name << "|" << s.rollNo << "|" << s.branch << "|"
             << s.course << "|" << s.email << "\n";
}

void StudentManager::addStudent() {
    Student s;
    cin.ignore();

    cout << "Name: "; getline(cin, s.name);
    cout << "Roll: "; getline(cin, s.rollNo);

    if (rollExists(s.rollNo)) {
        cout << "Roll already exists!\n";
        return;
    }

    cout << "Branch: "; getline(cin, s.branch);
    cout << "Course: "; getline(cin, s.course);
    cout << "Email: "; getline(cin, s.email);

    students.push_back(s);
    saveToFile();
}

void StudentManager::displayStudents() {
    for (const auto& s : students)
        s.print();
}

void StudentManager::searchStudent() {
    string roll;
    cin.ignore();
    cout << "Enter Roll: ";
    getline(cin, roll);

    for (const auto& s : students)
        if (s.rollNo == roll) {
            s.print();
            return;
        }
    cout << "Student not found\n";
}

void StudentManager::editStudent() {
    string roll;
    cin.ignore();
    cout << "Enter Roll: ";
    getline(cin, roll);

    for (auto& s : students) {
        if (s.rollNo == roll) {
            cout << "New Name: "; getline(cin, s.name);
            cout << "New Email: "; getline(cin, s.email);
            saveToFile();
            return;
        }
    }
    cout << "Student not found\n";
}

void StudentManager::deleteStudent() {
    string roll;
    cin.ignore();
    cout << "Enter Roll: ";
    getline(cin, roll);

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->rollNo == roll) {
            students.erase(it);
            saveToFile();
            return;
        }
    }
    cout << "Student not found\n";
}
