#include <iostream>
#include <string>
#include <exception>
#include "Validation.h"
#include "Person.h"
using namespace std;


int main()
{
    Person p;
    p.setName("Ahmed");
    p.setId(908);
    p.setPassword("Ahmed005");

    p.display();
    
}