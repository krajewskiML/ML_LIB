//
// Created by genez on 16.04.2021.
//

#ifndef ML_LIB_REGRESSION_H
#define ML_LIB_REGRESSION_H

#include "SupervisedModel.h"
#include "bits/stdc++.h"

class Regression : public SupervisedModel {

    /// Regression class is a model that

public:
    Regression(int _polynomial_degree);

    void show(std::ostream &out = std::cout) const;

    void fit(const Data &data, const Data &label, double learning_rate, int epochs);

    Matrix predict(const Data &data) const;

    void save(std::ostream &os) const;

    void read(std::istream &is);

    void test(const Data &data, const Data &label) const;

    ~Regression();


protected:
    Matrix prepareData(const Data &data) const;

    Matrix applyHypothesis(const Matrix &data) const;

    void gradientDescent(const Matrix &data, const Matrix &label, double learning_rate);

    double cost(const Matrix &guess, const Matrix &labels) const;

    void createHypothesis(const Matrix &final_data);

    int numberOfParameters() const;

    Matrix *hypothesis_matrix;

    int polynomial_degree;


};


#endif //ML_LIB_REGRESSION_H
