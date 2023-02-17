//
// Created by Marco Silva on 17/02/2023
//

#include "application.h"
#include "debug.h"

Application::Application(const std::string& name)
{
    _appName = name;

    Debug::PrintString("Application Initialized: " + GetAppName());
}

Application::~Application()
{
    Debug::PrintString("Application Closed: " + GetAppName());
}

void Application::Run()
{
    SetIsRunning();

    while (IsRunning())
    {
        Debug::Delay(5.0);
        SetIsRunning(false);
    }
}