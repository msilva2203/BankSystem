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

    inline void AddUser(Account account);
    inline void RemoveUser(int index);

    const std::vector<Account>& GetUsers() const { return _users; }
    int const GetSize() const { return _users.size(); }
    int FindAccountById(int id);
    bool IsIdValid(int id);

    private:
    std::vector<Account> _users;

};