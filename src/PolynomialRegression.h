//
// Created by genez on 16.04.2021.
//

#ifndef ML_LIB_POLYNOMIALREGRESSION_H
#define ML_LIB_POLYNOMIALREGRESSION_H

#include "Regression.h"

class PolynomialRegression : public Regression {
public:
    PolynomialRegression(int _degree=2);
private:
    int degree;
};


#endif //ML_LIB_POLYNOMIALREGRESSION_H
