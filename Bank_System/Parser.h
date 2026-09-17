#pragma once

#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Parser {
public:
    static vector<string> split(string line);
    static Client parseToClient(string line);
    static Employee parseToEmployee(string line);
    static Admin parseToAdmin(string line);
};

inline vector<string> Parser::split(string line) {
    stringstream ss(line);
    string t;
    vector<string> r;
    while (getline(ss, t, ',')) r.push_back(t);
    return r;
}

inline Client Parser::parseToClient(string line) {
    auto v = split(line);
    return Client(v[0], stoi(v[1]), v[2], stod(v[3]));
}

inline Employee Parser::parseToEmployee(string line) {
    auto v = split(line);
    return Employee(v[0], stoi(v[1]), v[2], stod(v[3]));
}

inline Admin Parser::parseToAdmin(string line) {
    auto v = split(line);
    return Admin(v[0], stoi(v[1]), v[2], stod(v[3]));
}
