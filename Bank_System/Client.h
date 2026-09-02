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
	
	//setters
	void setbalance(double balance);
	double getbalance();
	//Operations
	void deposit(double amount);
	void withdraw(double amount);
	void transferTo(double amount,Client& recipient);
	void checkBalance();
	void display() override;

	
};



