#include "Client.h"
//constructors
Client::Client() :Person(), balance(1500) {};
//setters
void Client:: setbalance(double balance){
	if (Validation::balanceValide(balance)) {
		this->balance = balance;
	}
	else {
		cout << "Invalid balance! Minimum balance is 1500\n";
	}
	};
double Client::getbalance() {
	return balance;
}
//Operations
void Client::deposit(double amount) {
	if (amount>0) {
		balance += amount;
		cout << "Successfully deposited :" << amount << "$" << "\nNew Balance: " << balance << "$\n";
	}
	else {
		cout << "Invalid deposit amount!\n";
	}
};
void Client::withdraw(double amount) {
	if (amount > 0 && (balance-amount)>=1500) {
		balance -= amount;
		cout << "Successfully withdraw :" << amount << "$" << "\nNew Balance: " << balance << "$\n";
	
	}
	else {
		cout << " withdraw failed!\n";
	}
};
void Client:: transferTo(double amount, Client& recipient) {
	if (amount >0 && (balance - amount) >= 1500) {
		balance -= amount;
		recipient.deposit(amount);
		cout << "Successfully transfer :" << amount << "$ To " << recipient.getName() << endl;
	}
	else {
		cout << "Transfer failed to " << recipient.getName() << endl;
	}
};
void Client::checkBalance() {
	cout << "Current Balance : " << balance << endl;
}
void Client::display() {
		Person::display();
		cout << "balance" << getbalance() << endl;
	}