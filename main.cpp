//
// Created by Marco Silva on 17/02/2023
//

#include "src/application.h"
#include <iostream>
#include "src/debug.h"

int main(int, char**) {
    Application app("Bank");
    app.Run();
    app.~Application();

    Debug::Delay(1.0);

    return 0;
}
