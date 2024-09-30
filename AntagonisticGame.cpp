// antagonistic_game.cpp
#include "AntagonisticGame.h"
#include <limits>
#include <algorithm>

AntagonisticGame::AntagonisticGame(const Matrix& m)
    : matrix(m), computedPrices(false) {}

void AntagonisticGame::computePrices() {
    if (computedPrices) return;

    int rows = matrix.getRows();
    int cols = matrix.getCols();

    rowMins.resize(rows, std::numeric_limits<double>::infinity());
    colMaxs.resize(cols, -std::numeric_limits<double>::infinity());

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            double element = matrix.get(i, j);
            if (element < rowMins[i]) {
                rowMins[i] = element;
            }
            if (element > colMaxs[j]) {
                colMaxs[j] = element;
            }
        }
    }

    lowerPrice = *std::max_element(rowMins.begin(), rowMins.end());

    upperPrice = *std::min_element(colMaxs.begin(), colMaxs.end());

    computedPrices = true;
}

std::vector<std::pair<int, int>> AntagonisticGame::findEquilibriumPoints() const {
    std::vector<std::pair<int, int>> equilibriumPoints;

    if (lowerPrice == upperPrice) {
        int rows = matrix.getRows();
        int cols = matrix.getCols();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix.get(i, j) == rowMins[i] && matrix.get(i, j) == colMaxs[j]) {
                    equilibriumPoints.emplace_back(i, j);
                }
            }
        }
    }

    return equilibriumPoints;
}
