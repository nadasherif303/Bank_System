#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"
#include "FileHelper.h"
#include "FileManager.h"

class Admin : public Employee {
public:
   
    Admin();
    Admin(int id, std::string name, std::string password, double salary);

   
    void addEmployee(Employee& employee);
    Employee* searchEmployee(int id);
    void editEmployee(int id, std::string name, std::string password, double salary);
    void listEmployee();
};
