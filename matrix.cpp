#include "Matrix.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

Matrix::Matrix(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    std::string line;
    std::vector<std::vector<double>> tempData;
    int expectedCols = -1;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<double> row;
        double value;
        std::string word;

        while (ss >> word) {
            try {
                value = std::stod(word);
            }
            catch (const std::invalid_argument& e) {
                throw std::runtime_error("Non-numeric value found in the matrix");
            }

            row.push_back(value);
        }

        if (expectedCols == -1) {
            expectedCols = row.size();
        }
        else if (row.size() != expectedCols) {
            throw std::runtime_error("Inconsistent number of columns in the matrix");
        }

        tempData.push_back(row);
    }

    rows = tempData.size();
    cols = expectedCols;

    if (rows == 0 || cols == 0) {
        throw std::runtime_error("Matrix is empty or invalid");
    }

    data = tempData;
    file.close();
}

void Matrix::print() const
{
    for (const auto& row : data) {
        for (const auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

double Matrix::get(int row, int col) const {
    return data[row][col];
}

void Matrix::set(int row, int col, double value) {
    data[row][col] = value;
}

double Matrix::getRows() const {
    return rows;
}

double Matrix::getCols() const {
    return cols;
}