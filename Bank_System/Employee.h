#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include "Validation.h"
#include <string>

using namespace std;

class Client;

class Employee : public Person {
private:
    double salary;

public:
    Employee();
    Employee(string name, int id, string password, double salary);

    void setSalary(double salary);

    double getSalary() const;

    void addClient(Client& client);

    Client* searchClient(int id);

    void listClient();

    void editClient(int id, string name, string password, double salary);

    void display();
};

#endif
