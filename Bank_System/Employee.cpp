#include <iostream>
#include <fstream>
#include "Employee.h"
#include "FileHelper.h"
#include "FileManager.h"
#include "Client.h"
#include "Parser.h"


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


void Employee::addClient(Client& client) {
    FileHelper::saveClient(client);
}


Client* Employee::searchClient(int id) {

    FileManager fm;

    vector<Client>::iterator ClientIt;

    for (ClientIt = fm.getAllClients().begin(); ClientIt != fm.getAllClients().end();ClientIt++) {

        if (ClientIt->getId() == id) {

            return &(*ClientIt);
        }
    }

    // if not found
    return nullptr;
   
}


void Employee::listClients() {

    vector<Client>::iterator ClientsIt;

    FileManager fm;

    for (ClientsIt = fm.getAllClients().begin(); ClientsIt != fm.getAllClients().end(); ClientsIt++) {
        ClientsIt->display();
    }
}


void Employee::editClient(int id, string name, string password, double balance) {


    Client* clientPtr = searchClient(id);

    if (clientPtr != nullptr) {
        clientPtr->setName(name);
        clientPtr->setPassword(password);
        clientPtr->setbalance(balance);

        cout << "Client " << clientPtr->getName() << " Updated Successfully\n";
    }

    else {
        cout << "Client not found!";
    }

}


void Employee::display(){

    cout << "=== Employee Information ===" << endl;
   
    Person::display();
    cout << "Salary: " << salary << "\n";
}
