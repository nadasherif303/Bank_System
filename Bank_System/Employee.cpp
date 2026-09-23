#include <iostream>
#include <fstream>
#include "Employee.h"
#include "FileHelper.h"
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
    ifstream file("Clients.txt");
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (!line.empty()) {
                Client c = Parser::parseToClient(line);
                if (c.getId() == id) {
                    file.close();
                    return new Client(c);
                }
            }
        }
        file.close();
    }
    else {
        return nullptr;
    }
    
}

void Employee::listClient() {
    FileHelper::getClients();
}

void Employee::editClient(int id, string name, string password, double balance) {

    vector<Client> clients;

    ifstream file("Clients.txt");

    string line;

    bool found = false;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (!line.empty()) {
                Client c = Parser::parseToClient(line);
                if (c.getId() == id) {
                    c.setName(name);
                    c.setPassword(password);
                    c.setbalance(balance);
                    found = true;
                }
                clients.push_back(c);
            }
        }
        file.close();
    }

    if (!found) {
        cout << "Client not found!";
        return;
    }

    
    ofstream outFile("Clients.txt", ios::trunc);

    if (outFile.is_open()) {
        for (const auto& c : clients) {
            outFile << c.getName() << ","
                    << c.getId() << ","
                    << c.getPassword() << ","
                    << c.getbalance() << endl;
        }

        outFile.close();
        cout << "Client updated successfully!\n";
    }
}

void Employee::display(){

    cout << "=== Employee Information ===" << endl;
   
    Person::display();
    cout << "Salary: " << salary << "\n";
}
