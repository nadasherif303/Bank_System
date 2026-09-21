#include <iostream>
#include <string>
#include <exception>
#include <fstream>

#include "Validation.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"

using namespace std;

#pragma once

class FileHelper{
public:


	// save last ID to txt file
	static void saveLast(string fileName, int id) {

		// open the file to write (if not existed, create one)
		ofstream file(fileName);

		// check if txt file is opened 
		if (file.is_open()){

			// write id to last ID txt file
			file << id;

			// close txt file
			file.close();
		}

	}


	// get last ID from file
	static int getLast(string fileName) {

		// open the txt file to read from it, ifstream ---> input file stream
		ifstream file(fileName);

		int id{};

		// check if txt file is opened 
		if (file.is_open()) {

			// read id from file
			file >> id;

			// close file
			file.close();
		}

		else {
			cout << "Unable to open this file\n";
		}

		return id;

	}


	// save client data to Clients.txt file
	static void saveClient(Client c) {

		// from get last method, get last id then add 1 to it ----> and this will be new id for new added client
		int lastId = getLast("ClientLastId.txt") + 1;

		// open txt file to write in it, ios::app --> for keeping old data in the file without deleting it and append new data to it
		// ofstream ---> output file stream
		ofstream file("Clients.txt", ios::app);

		// check if txt file is opened 
		if (file.is_open()){

			// write clients data in the file : name, id, password, balance
			file << c.getName() << ","
				 << lastId << ","
			   	 << c.getPassword() << ","
				 << c.getbalance() << endl;

			// close file
			file.close();
		}

		else {
			cout << "Unable to open clients file\n";
		}

		// save new generated client ID to last ID txt file
		saveLast("ClientLastId.txt", lastId);
	}


	// save employee data to Employees.txt file
	static void saveEmployee(string fileName, string lastIdFile, Employee e) {

		// from get last method, get last id then add 1 to it ----> and this will be new id for new added employee
		int lastId = getLast(lastIdFile) + 1;

		// open txt file to write in it, ios::app --> for keeping old data in the file without deleting it and append new data to it
		ofstream file(fileName, ios::app);

		if (file.is_open()){

			// write clients data in the file : name, id, password, balance
			file << e.getName() << ","
			     << lastId << ","
				 << e.getPassword() << ","
				 << e.getSalary() << endl;

			// close file
			file.close();
		}

		else {
			cout << "Unable to open employees file\n";
		}

		// save new generated employee ID to last ID txt file
		saveLast(lastIdFile, lastId);
	}


	// print all clients data from txt file
	static void getClients() {

		// open client txt file
		ifstream file("Clients.txt");

		// variable to store text read from txt file
		string line;

		if (file.is_open()) {

			// getline(file, line) ---> reads the line from txt file and store it in line variable to use it in the loop
			while (getline(file, line)) {

				// if line is not empty
				if (!line.empty()) {

					// parserToClient converts text from txt file into a client obj with its data, then these data will be stored in client obj we created
					Client c = Parser::parseToClient(line);

					// print all clients data
					c.display();
					cout << '\n';
				}

			}

			file.close();
		}

		else {
			cout << "Unable to open clients file\n";
		}
	}


	// print all employees data from txt file
	static void getEmployees() {

		// open employee txt file
		ifstream file("Employees.txt");

		// variable to store text read from txt file
		string line;

		if (file.is_open()) {

			// getline(file, line) ---> reads the line from txt file and store it in line variable to use it in the loop
			while (getline(file, line)) {

				// if line is not empty
				if (!line.empty()) {

					// parserToEmployee converts text from txt file into an employee obj with its data, then these data will be stored in employee obj we created
					Employee e = Parser::parseToEmployee(line);

					// print all employees data
					e.display();
					cout << '\n';
				}

			}

			file.close();
		}

		else {
			cout << "Unable to open employees file\n";
		}

	}


	// print all admins data from txt file
	static void getAdmins() {

		// open admin txt file
		ifstream file("Admins.txt");

		// variable to store text read from txt file
		string line;

		if (file.is_open()) {

			// getline(file, line) ---> reads the line from txt file and store it in line variable to use it in the loop
			while (getline(file, line)) {

				// if line is not empty
				if (!line.empty()) {

					// parserToAdmin converts text from txt file into an admin obj with its data, then these data will be stored in admin obj we created
					Admin a = Parser::parseToAdmin(line);

					// print all admins data
					a.display();
				}

			}

			file.close();
		}

		else {
			cout << "Unable to open admins file\n";
		}
	}


	// clear all file's data
	static void clearFile(string fileName, string lastIdFile) {

		// open file to write(delete what in it), ios::trunc ---> truncate, this flag deletes all file's data
		ofstream file(fileName, ios::trunc);

		file.close();

		// make last ID in txt file = 0
		saveLast(lastIdFile, 0);
	}

};