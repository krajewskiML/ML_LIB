#include <iostream>

#include "src/Data.h"
#include <fstream>
#include "src/Regression.h"
int main() {
    Regression model(2);
    std::fstream data("data.csv");
    std::fstream labels("linear_regression_labels.csv");
    Data dane(data);
    Data oznaczenia(labels);
    model.fit(dane, oznaczenia, 0.00000003, 10000000);

}
