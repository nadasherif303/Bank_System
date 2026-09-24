#include <iostream>
#include <vector>
#include <string>
#include "Admin.h"

using namespace std;


extern vector<Employee> allEmployees;


Admin::Admin() : Employee() {}

Admin::Admin(int id, string name, string password, double salary)
    : Employee(id, name, password, salary) {}


void Admin::addEmployee(Employee& employee) {
    allEmployees.push_back(employee);
    FileManager fm;
    fm.addEmployee(employee);
}


Employee* Admin::searchEmployee(int id) {
    for (size_t i = 0; i < allEmployees.size(); i++) {
        if (allEmployees[i].getId() == id) {
            return &allEmployees[i];
        }
    }
    return nullptr;
}


void Admin::listEmployee() {
    cout << "\n================ ALL EMPLOYEES ================\n";
    if (allEmployees.empty()) {
        cout << "No employees found.\n";
        return;
    }
    for (auto& employee : allEmployees) {
        employee.display();
        cout << "-----------------------------------------------\n";
    }
}


void Admin::editEmployee(int id, string name, string password, double salary) {
    Employee* emp = searchEmployee(id);
    if (emp != nullptr) {
        emp->setName(name);
        emp->setPassword(password);
        emp->setSalary(salary);

        
        FileManager fm;
        fm.removeAllEmployees();
        for (auto& e : allEmployees) {
            fm.addEmployee(e);
        }
        cout << "Employee with ID " << id << " updated successfully.\n";
    } else {
        cout << "Employee with ID " << id << " not found.\n";
    }
}
