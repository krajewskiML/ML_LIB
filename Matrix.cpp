//
// Created by genez on 06.04.2021.
//


#include "Matrix.h"

Matrix::Matrix(int _rows, int _columns) {

    assert(_rows != 0 and _columns != 0);

    rows = _rows;
    columns = _columns;
    matrix = new double *[rows];
    int i, j;
    for (i = 0; i < rows; ++i) {
        matrix[i] = new double[columns];
        for (j = 0; j < columns; ++j) {
            matrix[i][j] = i * 3 + j * 5; //random value for tests
        }
    }
}

Matrix Matrix::transposed() const {

    Matrix *returned;
    returned = new Matrix(columns, rows);

    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            returned->matrix[j][i] = matrix[i][j];
        }
    }
    return *returned;
}

Matrix Matrix::multiply(const Matrix &first_matrix, const Matrix &second_matrix) {

    assert(first_matrix.columns == second_matrix.rows);
    Matrix *result;
    result = new Matrix(first_matrix.rows, second_matrix.columns);
    int i, j, k;
    for (i = 0; i < result->rows; ++i) {
        for (j = 0; j < result->columns; ++j) {
            result->matrix[i][j] = 0;
            for (k = 0; k < first_matrix.columns; ++k) {
                result->matrix[i][j] += first_matrix.matrix[i][k] * second_matrix.matrix[k][j];
            }
        }
    }
    return *result;
}

void Matrix::write(std::ostream &os) const {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            os << matrix[i][j] << ' ';
        }
        os << '\n';
    }
}

void Matrix::transpose() {
    *this = transposed();
}

int Matrix::determinant() {
    return 0;
}

int Matrix::rank() {
    return 0;
}

void Matrix::inverse() {

}

void Matrix::operator=(const Matrix &_matrix) {
    rows = _matrix.rows;
    columns = _matrix.columns;
    matrix = new double *[rows];
    int i, j;
    for (i = 0; i < rows; ++i) {
        matrix[i] = new double[columns];
        for (j = 0; j < columns; ++j) {
            matrix[i][j] = _matrix.matrix[i][j]; //random value for tests
        }
    }
}


Matrix::~Matrix() {
    int i;
    for (i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}



