#include <iostream>
#include "Login.h"
#include "StudentManager.h"
using namespace std;

int main() {
    Login login;
    StudentManager sm;
    sm.loadFromFile();

    int choice;
    cout << "1. Admin Login\n2. Exit\nChoice: ";
    cin >> choice;

    if (choice == 1) {
        if (!login.adminLogin()) {
            cout << "Invalid login!\n";
            return 0;
        }

        int ch;
        while (true) {
            cout << "\n1.Add 2.Display 3.Search 4.Edit 5.Delete 6.Exit\n";
            cin >> ch;

            switch (ch) {
            case 1: sm.addStudent(); break;
            case 2: sm.displayStudents(); break;
            case 3: sm.searchStudent(); break;
            case 4: sm.editStudent(); break;
            case 5: sm.deleteStudent(); break;
            case 6: return 0;
            }
        }
    }
    return 0;
}
