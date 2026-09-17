#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include "Validation.h"
#include <string>
using namespace std;


class Employee : public Person {
private:
    double salary;

public:
    Employee();
    Employee(string name, int id, string password, double salary);

    void setSalary(double salary);
    double getSalary() const;

    void display();
};

#endif
