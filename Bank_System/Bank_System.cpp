#include <iostream>
#include <string>
#include <exception>
#include "Validation.h"
#include "Person.h"
#include "Client.h"
using namespace std;


int main()
{
    Person p("Ahmed", 908,"Ahmed005");
    
    p.display();

    Client c;
    c.setbalance(3500.0);
    c.display();
}