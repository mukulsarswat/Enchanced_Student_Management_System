#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>

using namespace std;

/* ---------- Color Utilities ---------- */
void Red() { cout << "\033[1;31m"; }
void Green() { cout << "\033[0;32m"; }
void Yellow() { cout << "\033[1;33m"; }
void Purple() { cout << "\033[0;35m"; }
void Cyan() { cout << "\033[0;36m"; }
void Reset() { cout << "\033[0m"; }

/* ---------- Cross-platform clear ---------- */
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/* ---------- Student Class ---------- */
class Student {
private:
    string name, rollNo, branch, course, email;

public:
    Student() {}

    Student(string n, string r, string b, string c, string e)
        : name(n), rollNo(r), branch(b), course(c), email(e) {}

    string getRollNo() const { return rollNo; }
    string getName() const { return name; }

    void setData(string n, string b, string e) {
        name = n;
        branch = b;
        email = e;
    }

    string toCSV() const {
        return name + "," + rollNo + "," + branch + "," + course + "," + email;
    }

    static Student fromCSV(const string& line) {
        string n, r, b, c, e;
        size_t pos;
        string temp = line;

        pos = temp.find(','); n = temp.substr(0, pos); temp.erase(0, pos + 1);
        pos = temp.find(','); r = temp.substr(0, pos); temp.erase(0, pos + 1);
        pos = temp.find(','); b = temp.substr(0, pos); temp.erase(0, pos + 1);
        pos = temp.find(','); c = temp.substr(0, pos); temp.erase(0, pos + 1);
        e = temp;

        return Student(n, r, b, c, e);
    }

    void print() const {
        Purple();
        cout << "\nName   : " << name
             << "\nRoll   : " << rollNo
             << "\nBranch : " << branch
             << "\nCourse : " << course
             << "\nEmail  : " << email << endl;
        cout << "-----------------------------\n";
        Reset();
    }
};

/* ---------- Student Management System ---------- */
class StudentManagementSystem {
private:
    vector<Student> students;

    bool rollExists(const string& roll) const {
        for (const auto& s : students)
            if (s.getRollNo() == roll)
                return true;
        return false;
    }

    bool isValidEmail(const string& email) const {
        return email.find('@') != string::npos;
    }

    void loadFromFile() {
        ifstream fin("Student.csv");
        string line;
        students.clear();

        while (getline(fin, line)) {
            students.push_back(Student::fromCSV(line));
        }
        fin.close();
    }

    void saveToFile() const {
        ofstream fout("Student.csv");
        for (const auto& s : students)
            fout << s.toCSV() << "\n";
        fout.close();
    }

public:
    void addStudent() {
        string name, roll, branch, course, email;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Name   : "; getline(cin, name);
        cout << "Roll   : "; getline(cin, roll);

        if (rollExists(roll)) {
            Red(); cout << "Duplicate Roll Number!\n"; Reset();
            return;
        }

        cout << "Branch : "; getline(cin, branch);
        cout << "Course : "; getline(cin, course);
        cout << "Email  : "; getline(cin, email);

        if (!isValidEmail(email)) {
            Red(); cout << "Invalid Email!\n"; Reset();
            return;
        }

        students.emplace_back(name, roll, branch, course, email);
        saveToFile();
        Green(); cout << "Student Added Successfully\n"; Reset();
    }

    void displayAll() const {
        if (students.empty()) {
            Red(); cout << "No Records Found\n"; Reset();
            return;
        }
        for (const auto& s : students)
            s.print();
    }

    void searchByRoll() const {
        string roll;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter Roll: ";
        getline(cin, roll);

        for (const auto& s : students) {
            if (s.getRollNo() == roll) {
                s.print();
                return;
            }
        }
        Red(); cout << "Student Not Found\n"; Reset();
    }

    void searchByName() const {
        string name;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter Name: ";
        getline(cin, name);

        bool found = false;
        for (const auto& s : students) {
            if (s.getName().find(name) != string::npos) {
                s.print();
                found = true;
            }
        }
        if (!found) {
            Red(); cout << "No Matching Student\n"; Reset();
        }
    }

    void editStudent() {
        string roll;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter Roll: ";
        getline(cin, roll);

        for (auto& s : students) {
            if (s.getRollNo() == roll) {
                string n, b, e;
                cout << "New Name   : "; getline(cin, n);
                cout << "New Branch : "; getline(cin, b);
                cout << "New Email  : "; getline(cin, e);

                if (!isValidEmail(e)) {
                    Red(); cout << "Invalid Email\n"; Reset();
                    return;
                }

                s.setData(n, b, e);
                saveToFile();
                Green(); cout << "Record Updated\n"; Reset();
                return;
            }
        }
        Red(); cout << "Student Not Found\n"; Reset();
    }

    void deleteStudent() {
        string roll;
        char confirm;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Roll: ";
        getline(cin, roll);

        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getRollNo() == roll) {
                it->print();
                cout << "Confirm Delete (y/n): ";
                cin >> confirm;

                if (confirm == 'y' || confirm == 'Y') {
                    students.erase(it);
                    saveToFile();
                    Green(); cout << "Deleted Successfully\n"; Reset();
                }
                return;
            }
        }
        Red(); cout << "Student Not Found\n"; Reset();
    }

    void menu() {
        loadFromFile();
        int choice;

        while (true) {
            Yellow();
            cout << "\n1.Add  2.Display  3.Search Roll  4.Search Name\n";
            cout << "5.Edit 6.Delete  7.Exit\n";
            cout << "Choice: ";
            cin >> choice;
            Reset();

            clearScreen();

            switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchByRoll(); break;
            case 4: searchByName(); break;
            case 5: editStudent(); break;
            case 6: deleteStudent(); break;
            case 7: exit(0);
            default: Red(); cout << "Invalid Choice\n"; Reset();
            }
        }
    }
};

/* ---------- MAIN ---------- */
int main() {
    StudentManagementSystem sms;
    sms.menu();
    return 0;
}
