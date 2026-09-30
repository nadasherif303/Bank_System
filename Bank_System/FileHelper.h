#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Parser.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"


using namespace std;


class Admin;
class Employee;
class Client;


class FileHelper{
public:


	// save last ID to txt file
	static void saveLast(string fileName, int id) {

		// open the file to write (if not existed, create one)
		ofstream file(fileName);

		// write id to last ID txt file
		file << id;
		
		// close txt file
		file.close();
			
	}


	// get last ID from file
	static int getLast(string fileName) {

		int id{};


		// open the txt file to read from it, ifstream ---> input file stream
		ifstream file(fileName);

		// read id from file
		file >> id;

		// close file
		file.close();
		
		return id;

	}


	// save client data to Clients.txt file
	static void saveClient(Client c) {

		// from get last method, get last id then add 1 to it ----> and this will be new id for new added client
		int lastId = getLast("ClientLastId.txt") + 1;

		
		// creating string variable to hold client data
		string data = c.getName() + ',' 
			        + to_string(c.getId()) + ',' 
			        + to_string(lastId) + ',' 
			        + to_string(c.getbalance());


		// open txt file to write in it
		// ios::app --> for keeping old data in the file without deleting it and append new data to it
		// ofstream ---> output file stream
		ofstream file("Clients.txt", ios::app);


		// save client data into file
		file << data + "\n";


		// save new generated client ID to last ID txt file
		saveLast("ClientLastId.txt", lastId);


		file.close();

	}


	// save employee data to Employees.txt file
	static void saveEmployee(string fileName, string lastIdFile, Employee e) {

		// from get last method, get last id then add 1 to it ----> and this will be new id for new added employee
		int lastId = getLast(lastIdFile) + 1;


		// creating string variable to hold client data
		string data = e.getName() + ','
			+ to_string(e.getId()) + ','
			+ to_string(lastId) + ','
			+ to_string(e.getSalary());


		// open txt file to write in it, ios::app --> for keeping old data in the file without deleting it and append new data to it
		ofstream file(fileName, ios::app);


		// save employee data into file
		file << data + "\n";


		// save new generated employee ID to last ID txt file
		saveLast(lastIdFile, lastId);


		file.close();
	}


	// get all clients data from txt file into a vector
	static vector<Client> getClients() {
		
		// create an empty vector to store data in it
		vector<Client> clients;

		// open client txt file
		ifstream file("Clients.txt");


		// variable to store text read from txt file
		string line;

		
		// getline(file, line) ---> reads the line from txt file and store it in line variable to use it in the loop
		while (getline(file, line)) {

			// parserToClient converts text from txt file into a client obj with its data, then these data will be stored in client obj we created
			Client c = Parser::parseToClient(line);

			// push back every client data to new clients vector
			clients.push_back(c);
	
		}

		file.close();

		return clients;
		
	}


	// get all employees data from txt file into a vector
	static vector<Employee> getEmployees() {
		
		// create an empty vector to store data in it
		vector<Employee> employees;

		// open employee txt file
		ifstream file("Employees.txt");


		// variable to store text read from txt file
		string line;


		// getline(file, line) ---> reads the line from txt file and store it in line variable to use it in the loop
		while (getline(file, line)) {

			// parserToEmployee converts text from txt file into an employee obj with its data, then these data will be stored in employee obj we created
			Employee e = Parser::parseToEmployee(line);


			// push back every client data to new clients vector
			employees.push_back(e);

		}

		file.close();

		return employees;
		
	}


	// print all admins data from txt file
	static vector<Admin> getAdmins() {
		
		// create an empty vector to store data in it
		vector<Admin> admins;


		// open admin txt file
		ifstream file("Admins.txt");


		// variable to store text read from txt file
		string line;


		// getline(file, line) ---> reads the line from txt file and store it in line variable to use it in the loop
		while (getline(file, line)) {


			// parserToAdmin converts text from txt file into an admin obj with its data, then these data will be stored in admin obj we created
			Admin a = Parser::parseToAdmin(line);


			// push back every client data to new clients vector
			admins.push_back(a);

		}

		file.close();

		return admins;
		
		
	}


	// clear all file's data
	static void clearFile(string fileName, string lastIdFile) {

		// open file to write(delete what in it), ios::trunc ---> truncate, this flag deletes all file's data
		ofstream file(fileName, ios::trunc);
		ofstream file2(lastIdFile, ios::trunc);


		// make last ID in txt file = 0
		file2 << "0";


		file.close();
		file2.close();
	}

};