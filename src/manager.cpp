//
// Created by Marco Silva on 17/02/2023
//

#include "manager.h"
#include "debug.h"

Manager::Manager()
{
    //Debug::PrintString("Manager constructed!");

    _users.push_back({"Marco", 1, 100});
    _users.push_back({"Diogo", 5, 90});
    _users.push_back({"Matilde", 3, 1233});
    _users.push_back({"Bruno", 11, 10023});
    _users.push_back({"Alexandre", 19, 10065});
    _users.push_back({"Daniela", 17, 14});
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
    Debug::PrintString("-----------------------------------", EFormat::END_LINE);
    Debug::PrintString("\tNAME: ", EFormat::STAY_LINE);
    Debug::PrintString(account.GetName(), EFormat::END_LINE);
    Debug::PrintString("\tIDENTIFICATION: ", EFormat::STAY_LINE);
    Debug::PrintString(account.GetId(), EFormat::END_LINE);
    Debug::PrintString("\tBALANCE: ", EFormat::STAY_LINE);
    Debug::PrintString(account.GetBalance(), EFormat::END_LINE);
    Debug::PrintString("-----------------------------------", EFormat::END_LINE);
}

void Manager::PrintAccountDataToFile(Account account, std::ofstream& file)
{
    file << "-----------------------------------" << std::endl;
    file << "\tNAME: ";
    file << account.GetName() << std::endl;
    file << "\tIDENTIFICATION: ";
    file << account.GetId() << std::endl;
    file << "\tBALANCE: ";
    file << account.GetBalance() << std::endl;
    file << "-----------------------------------" << std::endl;
}

const std::vector<Account> Manager::GetFilteredUsers(const EOrder order)
{
    if (GetUsers().size() < 2) return GetUsers();

    return Manager::GetOrderedUsers(GetUsers(), order);
}

std::vector<Account> Manager::GetOrderedUsers(std::vector<Account> users, const EOrder order)
{
    bool complete = false;

    switch (order)
    {
        case (EOrder::ID):
        {
            Debug::PrintString("Ordering by ID");
            while (!complete)
            {
                complete = true;
                for (int i = 1; i < users.size(); i++)
                {
                    if (users[i].GetId() < users[i - 1].GetId())
                    {
                    std::swap(users[i], users[i - 1]);
                    complete = false;
                    }
                }
            }
            return users;
        }

        case (EOrder::BALANCE):
            {
                Debug::PrintString("Ordering by balance");
                while (!complete)
                {
                    complete = true;
                    for (int i = 1; i < users.size(); i++)
                    {
                        if (users[i].GetBalance() < users[i - 1].GetBalance())
                        {
                            std::swap(users[i], users[i - 1]);
                            complete = false;
                        }
                    }
                }
                return users;
            }

        case (EOrder::NAME):
        {
            Debug::PrintString("Ordering by Name");
            while (!complete)
            {
                complete = true;
                for (int i = 1; i < users.size(); i++)
                {
                    if (users[i].GetName() < users[i - 1].GetName())
                    {
                        std::swap(users[i], users[i - 1]);
                        complete = false;
                    }
                }
            }
            return users;
        }
        

        default:
        return users;
    }
}