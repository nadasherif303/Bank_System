#include "Admin.h"
#include <iostream>

using namespace std;


// Default Constructor
Admin::Admin() : Employee() {}


// Parameterized Constructor
Admin::Admin(int id, string name, string password, double salary)
    : Employee(id, name, password, salary){ }


// Display Admin information
void Admin::display(){
    cout << "=== Admin Information ===" << endl;

    Employee::display();
}