#include "fractal.hpp"

#include <fstream>
#include <cstdlib>
#include <ctime>

void Fern::generatesFractal(float plotDensity,float minX,float minY,float maxX,float maxY,long int steppNumber){
	std::srand((unsigned int)time(NULL));//seed r gen
	int rand;
	float xy[2]={0.,0.};
	float x_temp;
	nX=(int)(maxX-minX)*plotDensity;
	nY=(maxY-minY)*plotDensity;
	densityMap = new float* [nX];
	for (int i = 0; i < nX; ++i){
		densityMap[i] =new float[nY];
	}

	for (int i = 0; i < nX; ++i){
		for (int j = 0; j < nY; ++j){
			densityMap[i][j]=0;
		}
	}
	float f1[2][2] = {
		{0.,0.},
		{0.,0.16}
	};
	float f2[2][2] = {
		{0.85,0.04},
		{-0.04,0.85}
	};
	float f3[2][2] = {
		{0.2,-0.26},
		{0.23,0.22}
	};
	float f4[2][2] = {
		{-0.15,0.28},
		{0.26,0.24}
	};
	float v1[2];
	float v2[2]={0.,1.6};
	float v3[2]={0.,1.6};
	float v4[2]={0.,0.44};

	for (long int i = 0; i < steppNumber; ++i){
		rand=std::rand() % 100+1;
		if(rand==1){
			x_temp=xy[0]*f1[0][0]+xy[1]*f1[0][1]+v1[0];
			xy[1]=xy[0]*f1[1][0]+xy[1]*f1[1][1]+v1[1];
			xy[0]=x_temp;
		}
		if((rand>=2)&&(rand<=86)){
			x_temp=xy[0]*f2[0][0]+xy[1]*f2[0][1]+v2[0];
			xy[1]=xy[0]*f2[1][0]+xy[1]*f2[1][1]+v2[1];
			xy[0]=x_temp;
		}
		if ((rand>= 87)&&(rand<= 93)){
			x_temp=xy[0]*f3[0][0]+xy[1]*f3[0][1]+v3[0];
			xy[1]=xy[0]*f3[1][0]+xy[1]*f3[1][1]+v3[1];
			xy[0]=x_temp;
		}
		if (rand>= 94){
			x_temp=xy[0]*f4[0][0]+xy[1]*f4[0][1]+v4[0];
			xy[1]=xy[0]*f4[1][0]+xy[1]*f4[1][1]+v4[1];
			xy[0]=x_temp;
		}
		if((xy[0]<maxX)&&(xy[0]>minX)&&(xy[1]<maxY)&&(xy[1]>minY)){
			densityMap[(int)((xy[0]-minX)*plotDensity)][(int)((xy[1]-minY)*plotDensity)]+=1;

		}
	}
}

void Fern::saveFractal(const char *filename){
	std::ofstream myfile;
	myfile.open(filename);

	for (int i = 0; i < nX; ++i){
		for (int j = 0; j < nY; ++j){
			myfile << densityMap[i][j];
			myfile << " ";
		}
		myfile << "\n";
	}
	myfile.close();
}