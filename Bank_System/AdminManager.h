#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Admin.h"
#include "Employee.h"
#include "Client.h"
#include "FileHelper.h"
#include "EmployeeManager.h"

using namespace std;


class AdminManager{


    static void printAdminMenu() {

        cout << "\n========== Admin Menu ==========\n";
        cout << "1. Display My Info\n";
        cout << "2. Add New Employee\n";
        cout << "3. Search For Employee\n";
        cout << "4. Edit Employee Info\n";
        cout << "5. List All Employees\n";
        cout << "6. Add New Client\n";
        cout << "7. List All Clients\n";
        cout << "8. Search For Client\n";
        cout << "9. Edit Client Info\n";
        cout << "10. Logout\n";
        cout << "================================\n";
        cout << "Enter your choice: ";
    }


    static Admin* login(int id, string password) {
        vector<Admin> admins = FileHelper::getAdmins();

        for (size_t i = 0; i < admins.size(); i++) {
            if (admins[i].getId() == id && admins[i].getPassword() == password) {
                return new Admin(admins[i]);
            }
        }
        return nullptr;
    }


    bool AdminOptions(Admin* admin) {

        printAdminMenu();
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            system("cls");
            admin->display();
            break;
        }


        case 2: {
            system("cls");
            string name, password;
            double salary;
            cout << "--- Add New Employee ---\n";
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Password: ";
            cin >> password;
            cout << "Enter Salary: ";
            cin >> salary;

            int id = FileHelper::getLast("EmployeeLastId.txt") + 1;
            Employee newEmp(name, id, password, salary);

            admin->addEmployee(newEmp);
            FileHelper::saveEmployee("Employees.txt", "EmployeeLastId.txt", newEmp);
            cout << "\nEmployee added successfully with ID: " << id << endl;
            break;
        }


        case 3: {
            system("cls");
            int empId;
            cout << "Enter Employee ID to search: ";
            cin >> empId;

            Employee* emp = admin->searchEmployee(empId);
            if (emp != nullptr) {
                cout << "\nEmployee Found:\n";
                emp->display();
            }
            else {
                cout << "\nEmployee with ID " << empId << " not found!\n";
            }
            break;
        }


        case 4: {
            system("cls");
            int empId;
            cout << "Enter Employee ID to edit: ";
            cin >> empId;

            Employee* emp = admin->searchEmployee(empId);
            if (emp != nullptr) {
                string name, password;
                double salary;
                cout << "Enter New Name: ";
                cin >> name;
                cout << "Enter New Password: ";
                cin >> password;
                cout << "Enter New Salary: ";
                cin >> salary;

                admin->editEmployee(empId, name, password, salary);
                cout << "\nEmployee information updated successfully!\n";
            }
            else {
                cout << "\nEmployee with ID " << empId << " not found!\n";
            }
            break;
        }


        case 5: {
            system("cls");
            cout << "\n--- List Of All Employees ---\n";
            admin->listEmployee();
            break;
        }


        case 6: {
            system("cls");
            EmployeeManager::newClient(admin);
            break;
        }


        case 7: {
            system("cls");
            EmployeeManager::listAllClients(admin);
            break;
        }


        case 8: {
            system("cls");
            EmployeeManager::searchForClient(admin);
            break;
        }


        case 9: {
            system("cls");
            EmployeeManager::editClientInfo(admin);
            break;
        }


        case 10: {
            cout << "\nLogging out...\n";
            return false;
        }


        default: {
            cout << "\nInvalid choice. Please try again.\n";
            break;

        }
        }


        system("pause");
        return true;

        }

    };