#include "Employee.h"
#include <iostream>

using namespace std;

Employee::Employee() : Person(), salary(5000.0) {}

Employee::Employee(int id, string name, string password, double salary) 
    : Person(id, name, password) {
    setSalary(salary);
}

void Employee::setSalary(double salary) {
    if (Validation::validateSalary(salary)) {
        this->salary = salary;
    } else {
        cout << "Invalid Salary! Minimum salary allowed is 5000.\n";
    }
}

double Employee::getSalary() const {
    return salary;
}

void Employee::display() const {
    Person::display();
    cout << "Salary: " << salary << "\n";
}
