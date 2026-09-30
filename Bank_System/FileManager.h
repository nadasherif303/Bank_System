#pragma once
#include <iostream>
#include <vector>

#include "DataSourceInterface.h"
#include "FileHelper.h"

using namespace std;

class FileManager : public DataSourceInterface {
public:
    
    // ==================== Clients Operations ====================
    int getClientId() {
        return FileHelper::getLast("ClientLastId.txt");
    }

    void addClient(Client client) {
        FileHelper::saveClient(client);
    }

    vector<Client> getAllClients() {
        return FileHelper::getClients();
    }

    void removeAllClients() {
        FileHelper::clearFile("Clients.txt", "ClientLastId.txt");
    }


    // ==================== Employees Operations ====================
    int getEmployeeId() {
        return FileHelper::getLast("EmployeeLastId.txt");
    }

    void addEmployee(Employee employee) {
        FileHelper::saveEmployee("Employees.txt", "EmployeeLastId.txt", employee);
    }

    vector<Employee> getAllEmployees() {
        return FileHelper::getEmployees();
    }

    void removeAllEmployees() {
        FileHelper::clearFile("Employees.txt", "EmployeeLastId.txt");
    }


    // ==================== Admin Operations ====================
    int getAdminId() {
        return FileHelper::getLast("AdminLastId.txt");
    }

    void addAdmin(Admin admin) {
        FileHelper::saveEmployee("Admins.txt", "AdminLastId.txt", admin);
    }

    vector<Admin> getAllAdmins() {
        return FileHelper::getAdmins();
    }

    void removeAllAdmins() {
        FileHelper::clearFile("Admins.txt", "AdminLastId.txt");
    }

};
