#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ClientManager {
public:
    static void printClientMenu() {
        cout << "\n--- Client Menu ---\n";
        cout << "1. Display Profile\n";
        cout << "2. Check Balance\n";
        cout << "3. Update Password\n";
        cout << "4. Withdraw\n";
        cout << "5. Deposit\n";
        cout << "6. Transfer Money\n";
        cout << "7. Logout\n";
    }

    static void updatePassword(Person* person) {
        string newPassword;
        cout << "Enter new password: ";
        cin >> newPassword;
        person->setPassword(newPassword);
        cout << "Password updated successfully!\n";
    }

    static Client* login(int id, string password) {
        return nullptr;
    }

    static bool clientOptions(Client* client) {
        int choice;
        cout << "Choose an option: ";
        cin >> choice;
        
        if (choice == 7) {
            return false;
        }
        
        return true;
    }
};
