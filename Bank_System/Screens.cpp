#include <iostream>
#include "Screens.h"


#include "ClientManager.h"
#include "EmployeeManager.h"
#include "AdminManager.h"


using namespace std;


void Screens::bankName() {

    cout << "=========================================\n";
    cout << "               BANK SYSTEM               \n";
    cout << "=========================================\n\n";
}


void Screens::welcome() {

    // clear previous console screen, cls ---> clean screen
    system("cls");

    bankName();

    cout << "Welcome To Our Bank Application\n\n";

    // pausing screen
    system("pause");
}


void Screens::loginOptions() {

    cout << "1. Log In as a Client\n" 
         << "2. Log In as an Employee\n" 
         << "3. Log In as an Admin\n" 
         << "4. Exit\n";
}


int Screens::logInAs() {

    int choice{};

    loginOptions();

    cout << "\nPlease Select An Option (1 - 4) : ";

    cin >> choice;

    return choice;
}


void Screens::invalid(int c) {

    cout << "\nInvalid Option : " << c << " ! Please Try Again\n\n";
   
    system("pause");
}


void Screens::logOut() {

    bankName();
    cout << "\nLogged Out Successfully, Thank you for using our Bank Application.\n\n";
   
}


void Screens::logInScreen(int c) {

    // clear previous console screen, cls ---> clean screen
    system("cls");

    bankName();

    int id{};
    string password;

    cout << "Please Enter ID : ";
    cin >> id;

    cout << "Please Enter Password : ";
    cin >> password;

    
    switch (c) {
    case 1: {
        cout << "--- Client Login ---\n";

        Client* client = ClientManager::login(id, password);
        if (client != nullptr) {
          
            while (ClientManager::clientOptions(client));
            delete client; 
        }

        else {
            cout << "\nInvalid ID or Password!\n";
            system("pause");
        }

        break;
    }

    case 2: {
        cout << "--- Employee Login ---\n";

        Employee* employee = EmployeeManager::login(id, password);
        if (employee != nullptr) {
            while (EmployeeManager::employeeOptions(employee));
            delete employee;
        }

        else {
            cout << "\nInvalid ID or Password!\n";
            system("pause");
        }

        break;
    }

    case 3:{
        cout << "--- Admin Login ---\n";
        Admin* admin = AdminManager::login(id, password);
        if (admin != nullptr) {
            while (AdminManager::AdminOptions(admin));
            delete admin;
        }
        else {
            cout << "\nInvalid ID or Password!\n";
            system("pause");
        }
        break;
    }

    default: {
        invalid(c);
        break;
    }
    }

}


void Screens::runApp() {

    welcome();

    while (true) {

        system("cls");

        bankName();

        int choice = logInAs();

        if (choice >= 1 && choice <= 3) {

            logInScreen(choice);
   
        }

        else if (choice == 4) {

            system("cls");

            logOut();

            break;

        }

        else {
            invalid(choice);
        }
    }

}