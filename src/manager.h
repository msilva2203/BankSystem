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

    private:
    std::vector<Account> _users;

};