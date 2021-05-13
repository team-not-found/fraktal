#include "mandelbrot.hpp"

#include <cstdlib>
#include <ctime>
#include <fstream>

void Mandelbrot::generateFractal(int width, int height, double x0, double y0,
                                 double x1, double y1, int stepNumber) {
    nX = width;
    nY = height;

    densityMap = new Matrix2d<double>(nY, nX);
    for (int i = 0; i < nY; i++) {
        for (int j = 0; j < nX; j++) {
            densityMap->operator()(i, j) = Mandelbrot::element(
                j * 1. / width * (x1 - x0) + x0,
                i * 1. / height * (y1 - y0) + y0, stepNumber);
        }
    }
}

int Mandelbrot::element(double cx, double cy, int cnt) {
    int i = 0;
    double x = 0;
    double y = 0;
    double xtemp;
    while ((i < cnt) && (x * x + y * y < 4)) {
        xtemp = x * x - y * y + cx;
        y = 2 * x * y + cy;
        x = xtemp;
        i += 1;
    }
    return i;
}

void Mandelbrot::saveFractal(const char *filename) {
    densityMap->writeToFile(filename);
}

Mandelbrot::~Mandelbrot() {
    std::cout << "Called Mandelbrot destructor!\n";
    delete densityMap;
}