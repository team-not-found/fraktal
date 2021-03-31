#include "../src/utility/matrix2d.hpp"
#include "../src/fern/fern.hpp"

using namespace std;
int main() {
	Matrix2d<double> matrix(5, 5);
	matrix.print();
	std::cout << matrix(2,3);
	matrix.writeToFile("matrix2dtest.bin");

	Fern newFern;
	newFern.generateFractal(3,-4,0,4,10,200000);
	newFern.saveFractal("plot.bin");

	return 0;
}