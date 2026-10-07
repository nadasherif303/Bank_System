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
	static void printClientMenu() {
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
	static void searhForClient(Employee* employee) {
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

};
