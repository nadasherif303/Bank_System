#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <fstream>

#include "Validation.h"
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

#include "Parser.h"
#include "FileHelper.h"
#include "FileManager.h"

#include "Screens.h"


using namespace std;


vector<Employee> allEmployees;


int main()
{

    cout << "\n================ Phase_03 ================\n\n";


    cout << "======== 1) Screens Class ========\n\n";

    Screens::runApp();
   
}