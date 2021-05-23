//
// Created by genez on 16.04.2021.
//

#ifndef ML_LIB_REGRESSION_H
#define ML_LIB_REGRESSION_H

#include "SupervisedModel.h"
#include "bits/stdc++.h"

class Regression : public SupervisedModel {


public:
    Regression(int _polynomial_degree);

    void show(std::ostream &out = std::cout) const;

    void fit(const Data &data, const Data &label, double learning_rate, int epochs);

    Matrix predict(const Data &data) const;

    void save(std::ostream &os) const;

    void read(std::istream &is);

    void test(const Data &data, const Data &label)const ;

    ~Regression();

private:
    double cost(const Matrix &guess, const Matrix &labels) const;

    int polynomial_degree;
    Matrix *hypothesis_matrix;

    Matrix predict(const Matrix &data) const;

    void createHypothesis(const Matrix &final_data);

    int numberOfParameters() const;

    Matrix prepareData(Data &data) const;

    void gradientDescent(const Matrix &data, const Matrix &label, double learning_rate);

    Matrix predict(const Matrix &data);
};


#endif //ML_LIB_REGRESSION_H
