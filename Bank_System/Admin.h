#include <iostream>
#include <string>
#include <cctype>
#include "Employee.h"

using namespace std;

#pragma once


class Admin : public Employee{
public:
    // Default Constructor
    Admin();

    // Parameterized Constructor
    Admin(int id, string name, string password, double salary);

    // Display Admin information
    void display() override;
};