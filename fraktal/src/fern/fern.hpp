#pragma once

#include "../utility/matrix2d.hpp"

#include <iostream>
#include <unistd.h>

class Fern {
  public:
    Matrix2d<double> densityMap;
    int nX;
    int nY;
    void generateFractal(float plotDensity, float minX, float minY, float maxX,
                         float maxY, long int stepNumber);
    void saveFractal(const char *filename);
};