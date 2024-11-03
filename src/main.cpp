#ifdef ENABLE_GUI
#include "gui/Gui.hpp"
#else
#include "cli/Cli.hpp"
#endif

int main() {
#ifdef ENABLE_GUI
    Gui gui;
    gui.run();
#else
    Cli cli;
    cli.run();
#endif

    return 0;
}