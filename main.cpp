#include <iostream>

#include "src/Data.h"
#include <fstream>
#include "src/Regression.h"
#include "src/LinearRegression.h"
#include "src/PolynomialRegression.h"
#include "src/mathFunctions.h"

void regressionTest(){
    LinearRegression a;
    std::ifstream data_file("data.csv");
    std::ifstream labels_file("linear_regression_labels.csv");
    Data data(data_file);
    Data labels(labels_file);
    a.fit(data, labels, 0.000003, 1000);
    a.test(data, labels);
}
void logisticRegressionTest(){

}

int main() {
    return 0;
}
