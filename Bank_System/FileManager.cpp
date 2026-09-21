#include "FileManager.h"

// ==================== Clients Operations ====================
void FileManager::addClient(Client client) {
    FileHelper::saveClient(client);
}

vector<Client> FileManager::getAllClients() {
    return FileHelper::getClients();
}

void FileManager::removeAllClients() {
    FileHelper::clearFile("Clients.txt", "ClientLastId.txt");
}

// ==================== Employees Operations ====================
void FileManager::addEmployee(Employee employee) {
    FileHelper::saveEmployee("Employees.txt","EmployeeLastId.txt",employee);
}

vector<Employee> FileManager::getAllEmployees() {
    return FileHelper::getEmployees();
}

void FileManager::removeAllEmployees() {
    FileHelper::clearFile("Employees.txt", "EmployeeLastId.txt");
}

// ==================== Admin Operations ====================
void FileManager::addAdmin(Admin admin) {
    FileHelper::saveEmployee("Admins.txt","AdminLastId.txt",admin);
}

vector<Admin> FileManager::getAllAdmins() {
    return FileHelper::getAdmins();
}

void FileManager::removeAllAdmins() {
    FileHelper::clearFile("Admins.txt", "AdminLastId.txt");
}