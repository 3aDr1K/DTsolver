#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>

class Matrix {
private:
	std::vector<std::vector<double>> data;
	int rows;
	int cols;
public:
	Matrix() : rows(0), cols(0) {};
	Matrix(const std::string& filename);
	double get(int row, int col) const;
	void set(int row, int col, double value);
	void print() const;
	double getRows() const;
	double getCols() const;
};

#endif