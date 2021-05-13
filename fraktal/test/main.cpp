#include "../src/fern/fern.hpp"
#include "../src/mandelbrot/mandelbrot.hpp"
#include "../src/utility/matrix2d.hpp"

using namespace std;
int main() {
    Matrix2d<double> matrix(5, 5);
    matrix.print();
    std::cout << matrix(2, 3) << std::endl;
    matrix.writeToFile("matrix2dtest.bin");

    std::cout << "Fern: " << std::endl;

    Fern fern;
    fern.generateFractal(150, 50);
    for (int i = 0; i < fern.nX; i++) {
        for (int j = 0; j < fern.nY; j++) {
            if (fern.densityMap->operator()(i, j) == 0) {
                std::cout << " ";
            } else {
                std::cout << "*";
            }
        }
        std::cout << std::endl;
    }

    std::cout << "Mandelbrot: " << std::endl;

    Mandelbrot mandelbrot;
    mandelbrot.generateFractal(150, 50);
    for (int i = 0; i < mandelbrot.nY; i++) {
        for (int j = 0; j < mandelbrot.nX; j++) {
            if (mandelbrot.densityMap->operator()(i, j) >= 100) {
                std::cout << '*';
            } else {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }

    return 0;
}