//
// Created by Marco Silva on 17/02/2023
//

#include "manager.h"
#include "debug.h"

Manager::Manager()
{
    //Debug::PrintString("Manager constructed!");
}

Manager::~Manager()
{
    //Debug::PrintString("Manager destroyed!");
}

void Manager::AddUser(Account account)
{
    _users.push_back(account);
}

void Manager::RemoveUser(int id)
{
    int index = GetAccountSystemIndex(id);
    if (index == -1) return;

    _users.erase(_users.begin() + index);
}

void Manager::AddFundsToAccount(int id, int funds)
{
    int index = GetAccountSystemIndex(id);
    if (index == -1) return;

    _users[index].OffsetBalance(funds);
}

int Manager::GetAccountSystemIndex(int id)
{
    if (!FindAccountById(id).IsFound()) return -1;

    for (int i = 0; i < _users.size(); i++)
    {
        if (_users[i].GetId() == id) return i;
    }

    return -1;
}

SearchResult Manager::FindAccountById(int id)
{
    if (IsEmpty()) return {false};
    for (Account a : _users)
    {
        if (a.GetId() == id) return {a, true};
    }

    return {false};
}

bool Manager::IsIdValid(int id)
{
    if (id <= 0) return false;

    return !FindAccountById(id).IsFound();
}

void Manager::PrintAccountData(Account account)
{
    Debug::PrintString("-----------------------------------");
    Debug::PrintString("\tNAME: ", EFormat::STAY_LINE);
    Debug::PrintString(account.GetName());
    Debug::PrintString("\tIDENTIFICATION: ", EFormat::STAY_LINE);
    Debug::PrintString(account.GetId());
    Debug::PrintString("\tBALANCE: ", EFormat::STAY_LINE);
    Debug::PrintString(account.GetBalance());
    Debug::PrintString("-----------------------------------");
}