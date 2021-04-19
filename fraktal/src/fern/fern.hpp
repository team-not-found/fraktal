#pragma once

#include "../utility/matrix2d.hpp"

#include <iostream>
#include <unistd.h>

class Fern {
  public:
    Matrix2d<double> densityMap;
    int nX;
    int nY;
    void generateFractal(int width, int height, long int stepNumber = 1000000);
    void saveFractal(const char *filename);
};