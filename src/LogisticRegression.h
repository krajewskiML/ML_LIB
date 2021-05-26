//
// Created by genez on 16.04.2021.
//

#ifndef ML_LIB_LOGISTICREGRESSION_H
#define ML_LIB_LOGISTICREGRESSION_H

#include "Regression.h"

class LogisticRegression : public Regression {
public:
    ~LogisticRegression();

    void fit(const Data &data, const Data &label, double learning_rate, int epochs);
protected:
    void gradientDescent(const Matrix &data, const Matrix &label, double learning_rate);

    Matrix applyActivationFunction(const Matrix &after_hypothesis);

    Matrix getChances(const Matrix &unprocessed_data);

    void createHypothesis(const Matrix &final_data, const Matrix &final_labels);

    double cost(const Matrix &guess, const Matrix &labels) const;
};


#endif //ML_LIB_LOGISTICREGRESSION_H
