//
// Created by Marco Silva on 17/02/2023
//

#include <vector>
#include "types.h"

class Manager
{
    public:
    Manager();
    ~Manager();

    void AddUser(Account account);
    void RemoveUser(int id);
    void AddFundsToAccount(int id, int funds);

    const std::vector<Account>& GetUsers() const { return _users; }
    int const GetSize() const { return _users.size(); }
    SearchResult FindAccountById(int id);
    bool IsIdValid(int id);
    bool IsEmpty() const { return _users.empty(); }
    static void PrintAccountData(Account account);

    private:
    std::vector<Account> _users;

    int GetAccountSystemIndex(int id);

};