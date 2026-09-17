#include "Admin.h"
#include <iostream>

using namespace std;


// Default Constructor
Admin::Admin() : Employee() {}


// Parameterized Constructor
Admin::Admin(string name, int id, string password, double salary)
    : Employee(name, id, password, salary) {}


// Display Admin information
void Admin::display(){

    cout << "=== Admin Information ===" << endl;

    Person::display();
    cout << "Salary: " << getSalary() << endl;
}