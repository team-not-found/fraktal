#include "../src/fern/fern.hpp"
#include "../src/utility/matrix2d.hpp"

using namespace std;
int main() {
    Matrix2d<double> matrix(5, 5);
    matrix.print();
    std::cout << matrix(2, 3);
    matrix.writeToFile("matrix2dtest.bin");

    Fern newFern;
    newFern.generateFractal(150, 50);
    for (int i = 0; i < newFern.nX; i++) {
        for (int j = 0; j < newFern.nY; j++) {
            if (newFern.densityMap(i, j) == 0) {
                std::cout << " ";
            } else {
                std::cout << "*";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}