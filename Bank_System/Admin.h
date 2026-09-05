#pragma once
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Admin {
private:
    int id;
    string name;
    string password;
    double salary;

    //Admin
    bool isValidName(string n);
    bool isValidPassword(string p);

public:
    Admin();
    Admin(int id, string name, string password, double salary);

    //(Setters)
    void setId(int id);
    void setName(string name);
    void setPassword(string password);
    void setSalary(double salary);  //(Getters)
    int getId();
    string getName();
    string getPassword();
    double getSalary();


    void display();
};