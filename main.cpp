#include <iostream>

#include "Matrix.h"
#include "mathFunctions.h"
int main() {
    std::cout<<DerivativeOfActivationFunction::sigmoid(1)<<" "
    <<DerivativeOfActivationFunction::relu(2)<<" "
    <<DerivativeOfActivationFunction::arctan(std::sqrt(3)/3);

    return 0;
}
