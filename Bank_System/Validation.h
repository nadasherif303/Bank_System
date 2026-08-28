#include <iostream>
#include <string>
#include <exception>
using namespace std;


#pragma once
class Validation {
public:

	static bool nameValide(const string& name) {

		if (name.length() < 3 || name.length() > 20)
			return false;


		for (char c : name) {
			if (isalpha((c)) == 0) {
				return false;
			}
		}

		return true;
	}


	static bool passwordValide(const string& password) {

		return password.length() >= 8 && password.length() <= 20;

	}


	static bool balanceValide(double balance) {

		return balance >= 1500;

	}

	static bool salaryValide(double salary) {

		return salary >= 5000;

	}

};