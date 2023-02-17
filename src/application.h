//
// Created by Marco Silva on 17/02/2023
//

#include <string>
#include "manager.h"

class Application
{
    public:
    Application(const std::string& name = "Default App");
    ~Application();

    void Run();

    const std::string& GetAppName() const { return _appName; }
    void SetAppName(const std::string& name) { _appName = name; }
    bool IsRunning() const { return _isRunning; }
    void SetIsRunning(bool A = true) { _isRunning = A; }

    private:
    std::string _appName;
    Manager manager;
    bool _isRunning;

};