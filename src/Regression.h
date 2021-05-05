//
// Created by genez on 16.04.2021.
//

#ifndef ML_LIB_REGRESSION_H
#define ML_LIB_REGRESSION_H

#include "SupervisedModel.h"
#include "bits/stdc++.h"
class Regression  {


public:
    Regression(int _polynomial_degree);
    void show(std::ostream &out=std::cout)const;
    void fit(const Data &data, const Data &label, double learning_rate, int epochs);
    Matrix hypothesis(const Data &data);
    ~Regression();

private:
    int polynomial_degree;
    Matrix *hypothesis_matrix;
    void createHypothesis(const Matrix &final_data);
    int numberOfParameters()const;
    Matrix prepareData(Data &data) const;
    double (*error_measurment)(double label, double prediction), (*error_derivative)(double label, double prediction);
    void gradientDescent(const Matrix &data, const Matrix &label, double learning_rate);

};


#endif //ML_LIB_REGRESSION_H
