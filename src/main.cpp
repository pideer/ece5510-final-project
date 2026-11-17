#include "runner.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    std::vector<std::string> args(argv + 1, argv + argc);

    std::string type = (2 <= argc) ? argv[1] : "hashCpu";
    // add args here

    return run(args, type);
}
