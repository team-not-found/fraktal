#pragma once

#include<vector>
#include<string>
#include<iostream>

#include "binary_writer.hpp"

// Great for storing a matrix (N x M) of elements of type <T>.
template <class T> class Matrix2d {
    std::vector<std::vector<T>> matrix;
    int n, m;
public:
    Matrix2d<T>() {}

    // Initializes the size to n x m. 
    Matrix2d<T>(int n, int m): matrix(n, std::vector<T>(m, 0)) {
        this->n = n;
        this->m = m;
    }

    int getN() {
        return n;
    }

    int getM() {
        return m;
    }

    // Acessing elements can be done via the () operator. Ex: myMatrix(4,5).
    T& operator()(int i, int j) {
        if(i < 0 || i > n || j < 0 || j > m) {
            std::cout << "Out of bounds!" << std::endl;
            return matrix[0][0];
        }

        return matrix[i][j];
    }

    // Will write the contents of the matrix row by row to the screen.
    void print() {
        std:: cout << std::endl;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                std::cout << matrix[i][j] << " ";
            }

            std:: cout << std::endl;
        }
    }

    // Will write the contents of the matrix to a binary file.
    void writeToFile(const std::string filename) {
        BinaryWriter<T>* writer = new BinaryWriter<T>(filename);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                writer->write(matrix[i][j]);
            }
        }

        delete writer;
    }
};