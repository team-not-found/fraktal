#include <iostream>

#include "dummy/dummy.hpp"
#include "fern/fern.hpp"

int main(int argc, char *argv[]) {
    Fern *fern = new Fern();
    std::cout << "Hello from fraktal-cli" << std::endl;
    hello();

    delete fern;
    return 0;
};