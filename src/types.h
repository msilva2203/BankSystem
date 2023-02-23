//
// Created by Marco Silva on 17/02/2023
//

#include <string>

struct Account
{
    std::string _name;
    int _id;
    int _balance;

    Account(const std::string& name, int id, int balance) : _name(name), _id(id), _balance(balance) {}

    const std::string& GetName() const { return _name; }
    int GetId() const { return _id; }
    int GetBalance() const { return _balance; }
};
