#pragma once

#include<iostream>
#include<string>
#include<vector>

#include"Employee.h"
#include"Client.h"
#include"FileHelper.h"

using namespace std;

class EmployeeManager {
public:

	static void printEmployeeMenu() {
		cout << "\n---Employee Menu---\n";
		cout << "1. Add New Client\n";
		cout << "2. List All Clients\n";
		cout << "3. Search for Client\n";
		cout << "4. Edit Client Info\n";
		cout << "5. Display My Info\n";
		cout << "6. Logout\n";
		
	}


	static void newClient(Employee* employee) {
		string name, password;
		double balance;

		cout << "\n---Add New Client---\n";
		cout << "Enter Name : ";
		cin >> name;
		cout << "Enter Password : ";
		cin >> password;
		cout << "Enter Initial Balance : ";
		cin >> balance;

		int id = FileHelper::getLast("ClientLastId.txt") + 1;
		Client newClientobj(name,id,password,balance);

		employee->addClient(newClientobj);
		FileHelper::saveClient(newClientobj);
		cout << "Client added successfully with id: " << id << endl;
	}


	static void listAllClients(Employee* employee) {
		cout << "\n---List Of All Clients---\n";
		employee->listClients();
	}


	static void searchForClient(Employee* employee) {
		int id;
		cout << "\nEnter Client Id To Search: ";
		cin >> id;
		Client* client = employee->searchClient(id);
		if (client != nullptr) {
			client->display();
			delete client;
		}
		else
			cout << "Client not found\n";
	}


    static void editClientInfo(Employee* employee) {
        int id;
        cout << "Enter Client ID to edit: ";
        cin >> id;


        Client* client = employee->searchClient(id);
        if (client != nullptr) {
            string name, password;
            double balance;

            cout << "Enter new name: ";
            cin >> name;
            cout << "Enter new password: ";
            cin >> password;
            cout << "Enter new balance: ";
            cin >> balance;

            client->setName(name);
            client->setPassword(password);
            client->setbalance(balance);

            employee->editClient(id,name,password,balance);
            cout << "Client information updated successfully!\n";
        }

        else {
            cout << "Client with ID " << id << " not found!\n";
        }
    }


    static Employee* login(int id, string password) {
        vector<Employee> employees = FileHelper::getEmployees();

        for (size_t i = 0; i < employees.size(); i++) {
            if (employees[i].getId() == id && employees[i].getPassword() == password) {
                // Return a dynamically allocated pointer to the authenticated employee
                return new Employee(employees[i]);
            }
        }
        return nullptr;
    }


    static bool employeeOptions(Employee* employee) {
        printEmployeeMenu();

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            newClient(employee);
            return true;
        case 2:
            listAllClients(employee);
            return true;
        case 3:
            searchForClient(employee);
            return true;
        case 4:
            editClientInfo(employee);
            return true;
        case 5:
            employee->display();
            return true;
        case 6:
            cout << "Logging out...\n";
            return false;
        default:
            cout << "Invalid choice. Please try again.\n";
            return true;
        }
    }



};











