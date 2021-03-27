#pragma once

#include <unistd.h>
#include <iostream>
class Fern
{
public:
	float **densityMap;
	int nX;
	int nY;
	void generatesFractal(float plotDensity,float minX,float minY,float maxX,float maxY,long int steppNumber);
	void saveFractal(const char *filename);
};