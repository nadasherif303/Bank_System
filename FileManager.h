#pragma once
#include<iostream>
#include<vector>
#include"DataSourceInterface.h"
#include"FileHelper.h"
using namespace std;
class FileManager :public DataSourceInterface {
public:
	void addClient(Client client)override;
	vector<Client> getAllClient()override;
	void removeAllClient()override;

	void addEmployee(Employee employe)override;
	vector<Employee> getAllEmployee()override;
	void removeAllEmployee()override;

	void addAdmin(Admin admin)override;
	vector<Admin> getAllAdmin()override;
	void removeAllAdmin()override;

};