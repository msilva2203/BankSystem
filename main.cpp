//
// Created by Marco Silva on 17/02/2023
//

#include "src/application.h"
#include "src/debug.h"

int main(int, char**) {
    Application app("Bank", "../files/");
    app.Run();
    app.~Application();

    Debug::Delay();

    return 0;
}
