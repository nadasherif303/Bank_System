#include <iostream>
#include <string>
#include <exception>
using namespace std;



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



int main()
{
    Person p;
    p.setName("Ahmed");
    p.setId(908);
    p.setPassword("Ahmed005");

    p.display();
    
}