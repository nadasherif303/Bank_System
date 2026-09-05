#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include "Validation.h"

class Employee : public Person {
private:
    double salary;

public:
    Employee();
    Employee(int id, std::string name, std::string password, double salary);

    void setSalary(double salary);
    double getSalary() const;

    void display() const override;
};

#endif
