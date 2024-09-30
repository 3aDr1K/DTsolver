#ifndef ANTAGONISTIC_H
#define ANTAGONISTIC_H

#include "matrix.h"
#include <vector>
#include <utility>

class AntagonisticGame {
private:
    const Matrix& matrix;
    std::vector<double> rowMins;
    std::vector<double> colMaxs;
    double lowerPrice;
    double upperPrice;
    bool computedPrices;

public:
    AntagonisticGame(const Matrix& m);
    void computePrices();
    double getLowerPrice() const { return lowerPrice; }
    double getUpperPrice() const { return upperPrice; }
    std::vector<std::pair<int, int>> findEquilibriumPoints() const;
};

#endif