#pragma once
#include <iostream>
#include <vector>


#include "DataSourceInterface.h"
#include "FileHelper.h"

using namespace std;

class FileManager : public DataSourceInterface {
public:
    
    void addClient(Client client) override;
    vector<Client> getAllClients() override;
    void removeAllClients() override;

    
    void addEmployee(Employee employee) override;
    vector<Employee> getAllEmployees() override;
    void removeAllEmployees() override;

    
    void addAdmin(Admin admin) override;
    vector<Admin> getAllAdmins() override;
    void removeAllAdmins() override;
};
