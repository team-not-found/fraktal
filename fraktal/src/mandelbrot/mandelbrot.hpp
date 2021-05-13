#pragma once

#include "../utility/matrix2d.hpp"
#include <iostream>
#include <unistd.h>

class Mandelbrot {
  public:
    Matrix2d<double> *densityMap;
    int nX;
    int nY;

    ~Mandelbrot();
    void saveFractal(const char *filename);
    void generateFractal(int width, int height, double x0 = -2, double y0 = -1,
                         double x1 = 1, double y1 = 1, int stepNumber = 10000);

    int element(double cx, double cy, int i);
};