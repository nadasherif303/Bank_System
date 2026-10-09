#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Client.h"
#include "FileHelper.h"

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
        vector<Client> clients = FileHelper::getClients();

        for (int i = 0; i < clients.size(); i++) {
            if (clients[i].getId() == id && clients[i].getPassword() == password) {
                return new Client(clients[i]);
            }
        }
        return nullptr;
    }

    static bool clientOptions(Client* client) {
        system("cls");

        printClientMenu();

        int choice;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            client->display();
            break;

        case 2:
            client->checkBalance();
            break;

        case 3:
            updatePassword(client);
            break;

        case 4: {
            double amount;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            client->withdraw(amount);
            break;
        }

        case 5: {  
            double amount;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            client->deposit(amount);
            break;
        }

        case 6: {
            
            double amount;
            int recipientId;

            cout << "Enter recipient ID: ";
            cin >> recipientId;
            cout << "Enter amount to transfer: ";
            cin >> amount;

            vector<Client> clients = FileHelper::getClients();
            bool found = false;
            for (size_t i = 0; i < clients.size(); i++) {
                if (clients[i].getId() == recipientId) {
                    client->transferTo(amount, clients[i]);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Recipient not found!\n";
            }
            break;
        }
        case 7:
            return false;

        default:
            cout << "Invalid option!\n";
            break;
        }

        system("pause");
        return true;
    }
    
};
