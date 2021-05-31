//
// Created by genez on 16.04.2021.
//

#include "LogisticRegression.h"


LogisticRegression::~LogisticRegression() = default;


void LogisticRegression::createHypothesis(const Matrix &final_data, const Matrix &final_labels) {
    hypothesis_matrix = new Matrix(final_data.columns, final_labels.columns, -1, 1);
}
void LogisticRegression::fit(const Data &data, const Data &label, double learning_rate, int epochs) {
    Matrix prepared_data = prepareData(data), labels = label.labelsToMatrix();
    if(hypothesis_matrix->rows != prepared_data.columns or hypothesis_matrix->columns != 1){
        createHypothesis(prepared_data, labels);
    }
    //will stick to gradient descent for now
    for (int epoch = 0; epoch < epochs; epoch++) {
        gradientDescent(prepared_data, labels, learning_rate);
    }
}

void LogisticRegression::gradientDescent(const Matrix &data, const Matrix &label, double learning_rate) {
    Matrix guess = applyHypothesis(data);
    Matrix error = guess - label;
    (*hypothesis_matrix) -= (data.transposed()) * error * learning_rate * (1.0 / data.rows);
}

double LogisticRegression::cost(const Matrix &guess, const Matrix &labels) const {
    return ((labels.transposed()*Matrix::ApplyFunction(guess, std::log))+((labels-1)*(-1)).transposed()*Matrix::ApplyFunction((guess-1)*(-1), std::log)).sum();
}

Matrix LogisticRegression::applyActivationFunction(const Matrix &after_hypothesis) {
    return Matrix::ApplyFunction(after_hypothesis, ActivationFunction::sigmoid);
}

Matrix LogisticRegression::getChances(const Matrix &unprocessed_data) {
    return applyActivationFunction(applyHypothesis(unprocessed_data));
}
