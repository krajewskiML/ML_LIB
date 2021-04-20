//
// Created by genez on 16.04.2021.
//

#ifndef ML_LIB_REGRESSION_H
#define ML_LIB_REGRESSION_H

#include "SupervisedModel.h"

class Regression : public SupervisedModel {
    void show(std::ostream &out=std::cout)const;
private:
    Matrix hypothesis(const Matrix &data);
    Matrix addOnes(Matrix& data);
    Matrix *predictor= nullptr;
    double (*error)(double label, double prediction), (*error_derivative)(double label, double prediction);

};


#endif //ML_LIB_REGRESSION_H
