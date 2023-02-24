//
// Created by Marco Silva on 17/02/2023
//

#include "application.h"
#include "debug.h"

Application::Application(const std::string& name)
{
    _appName = name;

    Debug::PrintString("Application Initialized: " + GetAppName());
    Debug::EndLine();
    Debug::Delay();
}

Application::~Application()
{
    Debug::PrintString("Application Closed: " + GetAppName());
    Debug::EndLine();
    Debug::Delay();
}

void Application::Run()
{
    SetIsRunning();

    while (IsRunning())
    {
        ShowMainMenu();
    }
}

const std::string& Application::GetUserInput()
{
    Debug::PrintString("Your input: ", EFormat::STAY_LINE);
    std::cin >> _input;

    return _input;
}

inline void Application::ShowMainMenu()
{
    Debug::PrintString("MAIN MENU");
    Debug::PrintString("0 - Close Application");
    Debug::PrintString("1 - Add Account");
    Debug::PrintString("2 - Remove Account");
    Debug::PrintString("3 - Print Users");
    Debug::PrintString("4 - Check Account");
    Debug::PrintString("5 - Add funds to account");
    Debug::PrintString("9 - Information");

    int input = -1;

    input = std::stoi(GetUserInput());
    while (input < 0 || input > 9)
    {
        Debug::PrintString("Your input does not correspond to any of the available options. Try again...");
        input = std::stoi(GetUserInput());
    }

    Debug::EndLine();
    Debug::Delay();

    switch (input)
    {
        case 0:
        SetIsRunning(false);
        break;

        case 1:
        ShowAddMenu();
        break;

        case 2:
        ShowRemoveMenu();
        break;

        case 3:
        ShowPrintMenu();
        break;

        case 4:
        ShowCheckMenu();
        break;

        case 5:
        ShowFundMenu();
        break;

        case 9: 
        ShowInfoMenu();
        break;

        default:
        Debug::PrintString("Your input is not accepted");
        Debug::EndLine();
        Debug::Delay();
        break;
    }
}

inline void Application::ShowAddMenu()
{
    Debug::PrintString("ADDING ACCOUNT(S)");

    int input = 1;
    int iteration = 1;
    int id = 0;
    bool valid = false;

    while(input == 1)
    {
        Debug::EndLine();
        Debug::PrintString("ADDING ", EFormat::STAY_LINE);
        Debug::PrintString(iteration);

        Debug::Tab();
        Debug::PrintString("Name");
        Debug::Tab();
        std::string name = GetUserInput();

        while(!valid)
        {
            Debug::Tab();
            Debug::PrintString("Identification");
            Debug::Tab();
            id = std::stoi(GetUserInput());

            valid = manager.IsIdValid(id);
            if (!valid) Debug::PrintString("This Identification number is not valid. Try again...");
        }

        Debug::Tab();
        Debug::PrintString("Initial Balance");
        Debug::Tab();
        int balance = std::stoi(GetUserInput());

        Account account{name, id, balance};
        manager.AddUser(account);

        Debug::PrintString("Add another account?");
        Debug::PrintString("0 - No");
        Debug::PrintString("1 - Yes");
        input = std::stoi(GetUserInput());

        valid = false;
        iteration++;
    }

    Debug::EndLine();
    Debug::Delay();

}

inline void Application::ShowRemoveMenu()
{
    Debug::PrintString("REMOVING ACCOUNT(S)");

    int input = 1;
    int iteration = 1;

    while (input == 1)
    {
        input = -1;

        Debug::EndLine();
        Debug::PrintString("REMOVING ", EFormat::STAY_LINE);
        Debug::PrintString(iteration);
        Debug::EndLine();

        while (input == -1)
        {
            Debug::PrintString("Account Identification");
            int id = std::stoi(GetUserInput());

            if (manager.FindAccountById(id).IsFound()) input = 1;

            if (input == -1) Debug::PrintString("This Account Identification does not correspond to any account. Try again...");
            else
            {
                manager.RemoveUser(id);
                Debug::EndLine();
                Debug::PrintString("The account with ID ", EFormat::STAY_LINE);
                Debug::PrintString(id, EFormat::STAY_LINE);
                Debug::PrintString(" has been removed from the system...");
                Debug::EndLine();
            }
        }

        Debug::PrintString("Remove another account?");
        Debug::PrintString("0 - No");
        Debug::PrintString("1 - Yes");
        input = std::stoi(GetUserInput());

        iteration++;
    }

    Debug::EndLine();
    Debug::Delay();

}

inline void Application::ShowPrintMenu()
{
    if (manager.IsEmpty())
    {
        Debug::PrintString("The system is empty. Add accounts...");
        Debug::EndLine();
        Debug::Delay();

        return;
    }

    Debug::PrintString("PRINTING");

    int size = manager.GetSize();
    int iteration = 1;
    std::vector<Account> users = manager.GetUsers();

    for (Account a : users)
    {
        Debug::EndLine();
        Debug::PrintString("ACCOUNT ", EFormat::STAY_LINE);
        Debug::PrintString(iteration, EFormat::STAY_LINE);
        Debug::PrintString("/", EFormat::STAY_LINE);
        Debug::PrintString(size);
        Manager::PrintAccountData(a);
    }

    Debug::EndLine();
    Debug::Delay();

}

inline void Application::ShowCheckMenu()
{
    if (manager.IsEmpty())
    {
        Debug::PrintString("The system is empty. Add accounts...");
        Debug::EndLine();
        Debug::Delay();

        return;
    }

    Debug::PrintString("CHECK ACCOUNT");
    Debug::EndLine();

    Debug::PrintString("Insert account identification");
    int id = std::stoi(GetUserInput());
    Debug::EndLine();

    SearchResult result = manager.FindAccountById(id);
    if (result.IsFound())
    {
        // found
        Debug::PrintString("ACCOUNT FOUND");
        Manager::PrintAccountData(result.GetAccount());
    }
    else
    {
        // not found
        Debug::PrintString("This identification does not correspond to any account...");
    }

    Debug::EndLine();
    Debug::Delay();

}

inline void Application::ShowFundMenu()
{
    if (manager.IsEmpty())
    {
        Debug::PrintString("The system is empty. Add accounts...");
        Debug::EndLine();
        Debug::Delay();

        return;
    }

    Debug::PrintString("ADDING FUNDS");
    Debug::EndLine();

    Debug::PrintString("Insert account identification");
    int id = std::stoi(GetUserInput());
    Debug::EndLine();

    SearchResult result = manager.FindAccountById(id);
    if (result.IsFound())
    {
        // found
        Debug::PrintString("ACCOUNT FOUND");
        Manager::PrintAccountData(result.GetAccount());

        Debug::EndLine();
        Debug::PrintString("Insert amount to add");
        int add = std::stoi(GetUserInput());
        Debug::EndLine();

        manager.AddFundsToAccount(id, add);
        Debug::PrintString("Added ", EFormat::STAY_LINE);
        Debug::PrintString(add, EFormat::STAY_LINE);
        Debug::PrintString(" to account with ID ", EFormat::STAY_LINE);
        Debug::PrintString(id);
    }
    else
    {
        // not found
        Debug::PrintString("This identification does not correspond to any account...");
    }

    Debug::EndLine();
    Debug::Delay();
}

inline void Application::ShowInfoMenu()
{
    Debug::PrintString("INFORMATION");
    Debug::EndLine();

    Debug::PrintString("Developed by Marco Manuel Almeida e Silva");
    Debug::PrintString("This program was developed in Visual Studio Code using C++17");

    Debug::EndLine();
    Debug::Delay();
}