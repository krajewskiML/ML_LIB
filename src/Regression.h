//
// Created by genez on 16.04.2021.
//

#ifndef ML_LIB_REGRESSION_H
#define ML_LIB_REGRESSION_H

#include "SupervisedModel.h"

class Regression : public SupervisedModel {

    void show(std::ostream &out=std::cout)const;
    Matrix hypothesis(const Data &data);
private:
    Matrix *predictor;
    double (*error)(double label, double prediction), (*error_derivative)(double label, double prediction);

};


#endif //ML_LIB_REGRESSION_H
