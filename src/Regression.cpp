//
// Created by genez on 16.04.2021.
//

#include "Regression.h"

Matrix Regression::hypothesis(const Data &data) {
    assert(hypothesis_matrix != nullptr);
    return (*data.matrix_representation) * (*hypothesis_matrix);
}


void Regression::show(std::ostream &out) const {
    out << "Model has " << this->numberOfParameters() << " parameters" << '\n';
}

Regression::Regression(int _polynomial_degree) : polynomial_degree(_polynomial_degree) {
}

void Regression::fit(const Data &data, const Data &label, double learning_rate, int epochs) {
    Matrix prepared_data = prepareData(const_cast<Data &>(data)), labels = *label.matrix_representation;
    createHypothesis(prepared_data);
    //will stick to gradient descent for now
    for(int epoch=1; epoch<=epochs; epoch++){
        gradientDescent(prepared_data, labels, learning_rate);
        hypothesis_matrix->write();
        std::cout<<"elo\n";
    }

}

void Regression::gradientDescent(const Matrix &data, const Matrix &label, double learning_rate) {
    Matrix guess = data*(*hypothesis_matrix);
    guess.write();
    (*hypothesis_matrix)-=(data.transposed())*(guess-label)*learning_rate*(1.0/data.rows);
}

int Regression::numberOfParameters() const {
    assert(hypothesis_matrix != nullptr);
    return hypothesis_matrix->rows * hypothesis_matrix->columns;
}

Matrix Regression::prepareData(Data &data) const {
    if (polynomial_degree == 0) {
        return Matrix(data.matrix_representation->rows, 1, 1, 1);
    }
    if (polynomial_degree == 1) {
        return Matrix::HorizontalStack(*data.matrix_representation, Matrix(data.matrix_representation->rows, 1, 1, 1));
    }
    Matrix answer(data.matrix_representation->rows, data.matrix_representation->columns * polynomial_degree + 1);

    for (int i = 1; i <= polynomial_degree; i++) {
        answer.PasteIntoInPlace((*data.matrix_representation) ^ i, 0, (i - 1) * (data.matrix_representation->columns));
    }
    answer.PasteIntoInPlace(Matrix(data.matrix_representation->rows, 1), 0,
                            polynomial_degree * data.matrix_representation->columns);
    return answer;
}

void Regression::createHypothesis(const Matrix &final_data) {
    hypothesis_matrix = new Matrix(final_data.columns, 1, -1, 1);
}



Regression::~Regression() = default;



