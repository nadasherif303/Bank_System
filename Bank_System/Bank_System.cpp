#include <iostream>
#include <string>
#include <exception>
#include <fstream>

#include "Validation.h"
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"
#include "FileHelper.h"

using namespace std;

int main()
{

    cout << "================ Phase_01 ================\n\n";

    Person p("Ahmed", 908, "Ahmed005");

    Client c(p.getName(), p.getId(), p.getPassword(), 5000.0);

    c.display();


    cout << "\n================ Phase_02 ================\n\n";


    cout << "======== 1) Parser Class ========\n\n";


    Client client = Parser::parseToClient("Ahmed,123,ahmed@gmail.com,5000");

    Employee employee = Parser::parseToEmployee("Omar,456,omar@gmail.com,7000");

    Admin admin = Parser::parseToAdmin("Ali,789,ali@gmail.com,10000");


    client.display();
    cout << '\n';

    employee.display();
    cout << '\n';

    admin.display();
    cout << '\n';


    cout << "===== 2) FileHelper Class =====\n\n";


    FileHelper::clearFile("Clients.txt", "ClientLastId.txt");
    FileHelper::clearFile("Employees.txt", "EmployeeLastId.txt");
    FileHelper::clearFile("Admins.txt", "AdminLastId.txt");


    Client c1("Nagwa", 0, "Nagwa_3005", 5000);
    Client c2("Mona", 0, "Mona@5666", 3000);
    Client c3("Ahmed", 0, "Ahmed@4006", 10000);

    Employee e1("Samy", 0, "Samy_7008", 7000);
    Employee e2("Omar", 0, "Omar@4005", 8500);

    Admin a1("Khaled", 0, "khaled@5002", 15000);


    FileHelper::saveClient(c1);
    FileHelper::saveClient(c2);
    FileHelper::saveClient(c3);

    FileHelper::saveEmployee("Employees.txt", "EmployeeLastId.txt", e1);
    FileHelper::saveEmployee("Employees.txt", "EmployeeLastId.txt", e2);

    FileHelper::saveEmployee("Admins.txt", "AdminLastId.txt", a1);


    FileHelper::getClients();
    cout << endl;

    FileHelper::getEmployees();
    cout << endl;

    FileHelper::getAdmins();
    cout << endl;


    cout << "Client's last ID : " << FileHelper::getLast("ClientLastId.txt") << endl;

    cout << "Employee's last ID : " << FileHelper::getLast("EmployeeLastId.txt") << endl;

    cout << "Admin's last ID : " << FileHelper::getLast("AdminLastId.txt") << endl;


}