#include "Employee.h"
#include "Person.h"
#include <iostream>

using namespace std;

Employee::Employee() : Person(), salary(5000.0) {}

Employee::Employee( string name, int id, string password, double salary)
    : Person(name, id, password) {
    setSalary(salary);
}

void Employee::setSalary(double salary) {
    if (Validation::salaryValide(salary)) {
        this->salary = salary;
    } else {
        cout << "Invalid Salary! Minimum salary allowed is 5000.\n";
    }
}

double Employee::getSalary() const {
    return salary;
}

void Employee::display(){

    cout << "=== Employee Information ===" << endl;
   
    Person::display();
    cout << "Salary: " << salary << "\n";
}
