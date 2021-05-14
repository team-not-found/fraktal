#include <cstdlib>
#include <iostream>
#include <string>

#include "dummy/dummy.hpp"
#include "fern/fern.hpp"
#include "mandelbrot/mandelbrot.hpp"

#include "utility/argument_marshaller.hpp"
#include "utility/fractal_type.hpp"

#define REQUIRED_ARGUMENT true

void help() {
    std::cout << "First argument must be fractal name, possible values:";

    for (int i = 0; i < FractalType::NumberOfTypes; i++) {
        std::cout << ' ' << enumToString<FractalType>((FractalType)i);
    }
    std::cout << " !" << std::endl;

    std::cout
        << "The second and third arguments are always the width the height."
        << std::endl;

    std::cout << "After these in the case of mandelbrot you need to provide "
                 "two points in "
                 "the plane that define a rectangle in the format x0 y0 x1 y1, "
                 "e.g -2.0 -1.0 1.0 1.0"
              << std::endl;

    std::cout << std::endl;

    std::cout << "Optionally you can supply a number that will limit the "
                 "number of iterations in case of fern and the max number of "
                 "iterations per pixel in case of mandelbrot."
              << std::endl;

    std::cout << std::endl;

    std::cout << "Finally you can give a filename where you expect the output."
              << std::endl;
}

int main(int argc, char *argv[]) {
    ArgumentMarshaller marshaller(argc, argv);

    std::string firstArg = marshaller.stringArgument(1);
    if (firstArg == "help") {
        help();
        return 0;
    }

    FractalType type =
        marshaller.enumArgument<FractalType>(1, REQUIRED_ARGUMENT);

    if (type == FractalType::FernFractal) {
        int width = marshaller.integerArgument(2, REQUIRED_ARGUMENT);
        int height = marshaller.integerArgument(3, REQUIRED_ARGUMENT);
        int nIterations = marshaller.integerArgument(4);

        std::string filename = marshaller.stringArgument(5);

        Fern *fern = new Fern();
        if (nIterations <= 0) {
            fern->generateFractal(width, height);
        } else {
            fern->generateFractal(width, height, nIterations);
        }

        if (filename == "") {
            std::string defaultFilename =
                "fern" + to_string(width) + "_" + to_string(height) + ".bin";
            fern->saveFractal(defaultFilename.c_str());
        } else {
            fern->saveFractal(filename.c_str());
        }

        delete fern;
        return 0;
    }

    if (type == FractalType::MandelbrotFractal) {
        int width = marshaller.integerArgument(2, REQUIRED_ARGUMENT);
        int height = marshaller.integerArgument(3, REQUIRED_ARGUMENT);
        double x0 = marshaller.doubleArgument(4, REQUIRED_ARGUMENT);
        double y0 = marshaller.doubleArgument(5, REQUIRED_ARGUMENT);
        double x1 = marshaller.doubleArgument(6, REQUIRED_ARGUMENT);
        double y1 = marshaller.doubleArgument(7, REQUIRED_ARGUMENT);
        int nIterations = marshaller.integerArgument(8);
        std::string filename = marshaller.stringArgument(9);

        Mandelbrot *mandelbrot = new Mandelbrot();
        if (nIterations <= 0) {
            mandelbrot->generateFractal(width, height);
        } else {
            mandelbrot->generateFractal(width, height, nIterations);
        }

        if (filename == "") {
            std::string defaultFilename = "mandelbrot" + to_string(width) +
                                          "_" + to_string(height) + ".bin";
            mandelbrot->saveFractal(defaultFilename.c_str());
        } else {
            mandelbrot->saveFractal(filename.c_str());
        }

        delete mandelbrot;
        return 0;
    }

    return 0;
};