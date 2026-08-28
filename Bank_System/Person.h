#include <iostream>
#include <string>
#include <exception>
#include "Validation.h"
using namespace std;


#pragma once
class Person {
protected:

	string name;
	int id;
	string password;

public:


	// setters

	void setName(string name) {

		if (Validation::nameValide(name)) {
			this->name = name;
		}
	}

	void setId(int id) {
		this->id = id;
	}

	void setPassword(string password) {

		if (Validation::passwordValide(password)) {
			this->password = password;
		}
	}


	// getters

	string getName() const {
		return name;
	}

	int getId() const {
		return id;
	}

	string getPassword() {
		return password;
	}


	// methods

	void display() {
		cout << "Name = " << getName() << endl;
		cout << "ID = " << getId() << endl;
		cout << "Password = " << getPassword() << endl;

		cout << "===========================\n";
	}
};