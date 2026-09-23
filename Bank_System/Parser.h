#pragma once

#include <vector>
#include <string>
#include <sstream>

#include "Admin.h"
#include "Client.h"
#include "Employee.h"

using namespace std;

class Admin;
class Employee;
class Client;

class Parser {
public:
    static vector<string> split(string line);
    static Client parseToClient(string line);
    static Employee parseToEmployee(string line);
    static Admin parseToAdmin(string line);
};