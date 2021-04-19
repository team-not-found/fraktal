#include "fern.hpp"

#include <cstdlib>
#include <ctime>
#include <fstream>

void Fern::generateFractal(int width, int height, long int stepNumber) {
    std::srand((unsigned int)time(NULL)); // seed r gen
    const float minX = -3.0;
    const float maxX = 3.0;
    const float minY = 0.0;
    const float maxY = 10.0;

    nX = height;
    nY = width;

    int rand;
    float xy[2] = {0., 0.};
    float x_temp;
    float plotDensityX = nX / (maxX - minX);
    float plotDensityY = nY / (maxY - minY);
    densityMap = Matrix2d<double>(nX, nY);

    float f1[2][2] = {{0., 0.}, {0., 0.16}};
    float f2[2][2] = {{0.85, 0.04}, {-0.04, 0.85}};
    float f3[2][2] = {{0.2, -0.26}, {0.23, 0.22}};
    float f4[2][2] = {{-0.15, 0.28}, {0.26, 0.24}};
    float v1[2];
    float v2[2] = {0., 1.6};
    float v3[2] = {0., 1.6};
    float v4[2] = {0., 0.44};

    for (long int i = 0; i < stepNumber; ++i) {
        rand = std::rand() % 100 + 1;
        if (rand == 1) {
            x_temp = xy[0] * f1[0][0] + xy[1] * f1[0][1] + v1[0];
            xy[1] = xy[0] * f1[1][0] + xy[1] * f1[1][1] + v1[1];
            xy[0] = x_temp;
        }
        if ((rand >= 2) && (rand <= 86)) {
            x_temp = xy[0] * f2[0][0] + xy[1] * f2[0][1] + v2[0];
            xy[1] = xy[0] * f2[1][0] + xy[1] * f2[1][1] + v2[1];
            xy[0] = x_temp;
        }
        if ((rand >= 87) && (rand <= 93)) {
            x_temp = xy[0] * f3[0][0] + xy[1] * f3[0][1] + v3[0];
            xy[1] = xy[0] * f3[1][0] + xy[1] * f3[1][1] + v3[1];
            xy[0] = x_temp;
        }
        if (rand >= 94) {
            x_temp = xy[0] * f4[0][0] + xy[1] * f4[0][1] + v4[0];
            xy[1] = xy[0] * f4[1][0] + xy[1] * f4[1][1] + v4[1];
            xy[0] = x_temp;
        }
        if ((xy[0] < maxX) && (xy[0] > minX) && (xy[1] < maxY) &&
            (xy[1] > minY)) {
            densityMap((int)((xy[0] - minX) * plotDensityX),
                       (int)((xy[1] - minY) * plotDensityY)) += 1;
        }
    }
}

void Fern::saveFractal(const char *filename) {
    densityMap.writeToFile(filename);
}