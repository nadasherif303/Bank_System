#include "Parser.h"


 vector<string> Parser::split(string line) {
    stringstream ss(line);
    string t;
    vector<string> r;
    while (getline(ss, t, ',')) r.push_back(t);
    return r;
}

Client Parser::parseToClient(string line) {
    auto v = split(line);
    return Client(v[0], stoi(v[1]), v[2], stod(v[3]));
}

Employee Parser::parseToEmployee(string line) {
    auto v = split(line);
    return Employee(v[0], stoi(v[1]), v[2], stod(v[3]));
}

Admin Parser::parseToAdmin(string line) {
    auto v = split(line);
    return Admin(v[0], stoi(v[1]), v[2], stod(v[3]));
}
