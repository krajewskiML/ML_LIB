//
// Created by genez on 07.04.2021.
//

#ifndef ML_LIB_MATHFUNCTIONS_H
#define ML_LIB_MATHFUNCTIONS_H

#endif //ML_LIB_MATHFUNCTIONS_H
#include <iostream>
#include "math.h"
namespace ActivationFunction{
    double sigmoid(double val);
    double relu(double val);
    double arctan(double val);
}

namespace DerivativeOfActivationFunction{ // probably will change the name
    double sigmoid(double val);
    double relu(double val);
    double arctan(double val);
}

namespace Error{
    double square(double label, double guess);
    double absolute(double label, double guess);
}

namespace DerivativeOfError{
    double square(double label, double guess);
    double absolute(double label, double guess);
}
