#include "Login.h"
#include <iostream>
#include <fstream>
using namespace std;

bool Login::adminLogin() {
    string user, pass, u, p;
    cout << "Username: "; cin >> user;
    cout << "Password: "; cin >> pass;

    ifstream fin("Admin.txt");
    fin >> u >> p;

    return (user == u && pass == p);
}
