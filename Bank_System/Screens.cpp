#include <iostream>
#include "Screens.h"


//#include "ClientManager.h"
//#include "EmployeeManager.h"
//#include "AdminManager.h"


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

    switch (c) {
        case 1:
            cout << "--- Client Login ---\n";
            //ClientManager::login();
            break;

        case 2:
            cout << "--- Employee Login ---\n";
            //EmployeeManager::login();
            break;

        case 3:
            cout << "--- Admin Login ---\n";
            //AdminManager::login();
            break;

        default:
            invalid(c);
            break;
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
            break; // remember to check if we need it or not
   
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