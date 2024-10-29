#include <iostream>

#include "P/Polynomial.hpp"
#include "cli/Cli.hpp"
#include "cli/InputHandler.hpp"

int main() {
    // ЪЪЪ

    Cli cli;
    cli.run();

    InputHandler inputHandler;
    Polynomial p = inputHandler.scanPolynomial();

    std::cout << p.toString() << std::endl;

    return 0;
}