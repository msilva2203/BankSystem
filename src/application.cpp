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
    //Debug::Delay(0.5f);
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

    int input = -1;

    input = std::stoi(GetUserInput());
    while (input < 0 || input > 3)
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

        default:
        Debug::PrintString("Your input is not accepted");
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
        Debug::PrintString("ADDING " + iteration);

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

        //Account account{name, id, balance};
        //manager.AddUser(account);

        Debug::PrintString("Add another account?");
        Debug::PrintString("0 - No");
        Debug::PrintString("1 - Yes");
        input = std::stoi(GetUserInput());

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
        int account = -1;

        Debug::EndLine();
        Debug::PrintString("REMOVING " + iteration);
        Debug::EndLine();

        while (account == -1)
        {
            Debug::PrintString("Account Identification");
            int id = std::stoi(GetUserInput());

            account = manager.FindAccountById(id);
            if (account == -1) Debug::PrintString("This Account Identification does not correspond to any account. Try again...");
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
    Debug::PrintString("PRINTING");
    Debug::EndLine();

    std::vector<Account> users = manager.GetUsers();

    for (Account a : users)
    {
        Debug::PrintString("Name: " + a.GetName());
    }

    Debug::EndLine();
    Debug::Delay();

}