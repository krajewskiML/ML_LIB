//
// Created by genez on 16.04.2021.
//

#include "Regression.h"

Matrix Regression::predict(const Data &data) const {
    assert(hypothesis_matrix != nullptr);
    Matrix prepared_data = prepareData(data);
    return prepared_data * (*hypothesis_matrix);
}

void Regression::show(std::ostream &out) const {
    out << "Model has " << numberOfParameters() << " parameters" << '\n';
}

Regression::Regression(int _polynomial_degree) : polynomial_degree(_polynomial_degree) {
}

void Regression::fit(const Data &data, const Data &label, double learning_rate, int epochs) {
    Matrix prepared_data = prepareData(data), labels = *label.matrix_representation;
    if (hypothesis_matrix->rows != prepared_data.columns or hypothesis_matrix->columns != 1) {
        createHypothesis(prepared_data);
    }
    //will stick to gradient descent for now
    for (int epoch = 0; epoch < epochs; epoch++) {
        gradientDescent(prepared_data, labels, learning_rate);
    }
}

void Regression::gradientDescent(const Matrix &data, const Matrix &label, double learning_rate) {
    Matrix guess = applyHypothesis(data);
    Matrix error = guess - label;
    (*hypothesis_matrix) -= (data.transposed()) * error * learning_rate * (1.0 / data.rows);
}

double Regression::cost(const Matrix &guess, const Matrix &labels) const {
    return ((guess - labels) ^ 2).sum();
}

int Regression::numberOfParameters() const {
    assert(hypothesis_matrix != nullptr);
    return hypothesis_matrix->rows * hypothesis_matrix->columns;
}

Matrix Regression::prepareData(const Data &data) const {
    if (polynomial_degree == 0) {
        return Matrix(data.records, 1, 1, 1);
    }
    if (polynomial_degree == 1) {
        return Matrix::HorizontalStack(*data.matrix_representation, Matrix(data.records, 1, 1, 1));
    }
    Matrix answer(data.records, data.variables * polynomial_degree + 1);

    for (int i = 1; i <= polynomial_degree; i++) {
        answer.PasteIntoInPlace((*data.matrix_representation) ^ i, 0, (i - 1) * (data.variables));
    }
    answer.PasteIntoInPlace(Matrix(data.records, 1), 0,
                            polynomial_degree * data.variables);
    return answer;
}

void Regression::createHypothesis(const Matrix &final_data) {
    hypothesis_matrix = new Matrix(final_data.columns, 1, -1, 1);
}

Matrix Regression::applyHypothesis(const Matrix &data) const {
    return data * (*hypothesis_matrix);
}

void Regression::save(std::ostream &os) const {
    hypothesis_matrix->save(os);
}

void Regression::read(std::istream &is) {
    hypothesis_matrix = new Matrix(is);
}

void Regression::test(const Data &data, const Data &label) const {
    Matrix guess = predict(data);
    std::cout << std::fixed << cost(guess, (*label.matrix_representation)) << '\n';
}


Regression::~Regression() = default;



