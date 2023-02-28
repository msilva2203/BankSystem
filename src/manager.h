//
// Created by Marco Silva on 17/02/2023
//

#include <vector>
#include <fstream>
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
    const std::vector<Account> GetFilteredUsers(const EOrder order = EOrder::ID);
    int const GetSize() const { return _users.size(); }
    SearchResult FindAccountById(int id);
    bool IsIdValid(int id);
    bool IsEmpty() const { return _users.empty(); }
    static void PrintAccountData(Account account);
    static void PrintAccountDataToFile(Account account, std::ofstream& file);

    private:
    std::vector<Account> _users;

    int GetAccountSystemIndex(int id);
    static std::vector<Account> GetOrderedUsers(std::vector<Account> users, const EOrder order);

};