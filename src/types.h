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
    int GetId() { return _id; }
    int GetBalance() { return _balance; }
    void OffsetBalance(int offset) { _balance += offset; }
};

struct SearchResult
{
    Account _account;
    bool _found;

    SearchResult(bool found) : _account({"none", 0, 0}), _found(found) {}
    SearchResult(Account account, bool found = true) : _account(account), _found(found) {}

    bool IsFound() { return _found; }
    const Account& GetAccount() const { return _account; }
};

enum class EOrder
{
    ID = 0,
    BALANCE = 1,
    NAME = 2
};