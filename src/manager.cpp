//
// Created by Marco Silva on 17/02/2023
//

#include "manager.h"
#include "debug.h"

Manager::Manager()
{
    //Debug::PrintString("Manager constructed!");

    _users.push_back({"Marco", 12, 100});
    _users.push_back({"Silva", 14, 1000});
}

Manager::~Manager()
{
    //Debug::PrintString("Manager destroyed!");
}

inline void Manager::AddUser(Account account)
{
    _users.push_back(account);
}

inline void Manager::RemoveUser(int index)
{
    
}

int Manager::FindAccountById(int id)
{
    if (!IsIdValid(id)) return -1;

{
    // Find Account if it exists
}

    return 1;
}

bool Manager::IsIdValid(int id)
{
    if (id <= 0) return false;
    return true;
}