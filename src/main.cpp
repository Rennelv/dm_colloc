#include <iostream>

#include "N/LongNatural.hpp"
#include "gui/Gui.hpp"

int main() {
    Gui gui;
    gui.run();

    LongNatural a("12345");
    LongNatural b("67");
    LongNatural c = a % b;
    std::cout << a.toString() << " % " << b.toString() << " = " << c.toString() << std::endl;

    return 0;
}