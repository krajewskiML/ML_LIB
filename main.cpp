#include <iostream>

#include "src/Data.h"
#include <fstream>
#include "src/Regression.h"
#include "src/LinearRegression.h"
#include "src/PolynomialRegression.h"
#include <time.h>

int main() {
    LinearRegression model;
    std::fstream data("data.csv");
    std::fstream labels("linear_regression_labels.csv");
    Data dane(data);
    Data oznaczenia(labels);

    model.fit(dane, oznaczenia, 0.0000003, 10000);
    model.test(dane, oznaczenia);
    return 0;
}
