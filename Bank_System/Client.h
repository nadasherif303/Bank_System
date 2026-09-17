#pragma once
#include<iostream>
#include"Person.h"
using namespace std;
class Client :public Person {
private:
	double balance;
public:
	//constructors
	Client();
	Client(string name, int id, string password, double balance);
	
	//setters
	void setbalance(double balance);
	double getbalance()const;

	//Operations
	void deposit(double amount);
	void withdraw(double amount);
	void transferTo(double amount,Client& recipient);
	void checkBalance()const ;
	void display() override;

	
};



