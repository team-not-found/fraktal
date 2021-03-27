#include "../src/fractal.hpp"

using namespace std;
int main() {
	Fern newFern;
	newFern.generatesFractal(300,-4,0,4,10,200000000);
	newFern.saveFractal("plot.bin");
	cout << "Hello World!";
	return 0;
}