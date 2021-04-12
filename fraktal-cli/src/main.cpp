#include <iostream>

#include "dummy/dummy.hpp"
#include "fern/fern.hpp"

#include "utility/argument_marshaller.hpp"
#include "utility/fractal_type.hpp"

#define REQUIRED_ARGUMENT true

int main(int argc, char *argv[]) {
    ArgumentMarshaller marshaller(argc, argv);
    FractalType type =
        marshaller.enumArgument<FractalType>(1, REQUIRED_ARGUMENT);
    Fern *fern = new Fern();
    std::cout << "Hello from fraktal-cli" << std::endl;
    hello();

    delete fern;
    return 0;
};