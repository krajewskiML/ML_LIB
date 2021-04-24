//
// Created by genez on 06.04.2021.
//


#include "Matrix.h"

Matrix::Matrix(int _rows, int _columns, double _min_value, double _max_value) {

    assert(_rows > 0 and _columns > 0 and _max_value >= _min_value);

    rows = _rows;
    columns = _columns;
    matrix = new double *[rows];
    int i, j;
    if (_max_value == _min_value) {
        for (i = 0; i < rows; ++i) {
            matrix[i] = new double[columns];
            for (j = 0; j < columns; ++j) {
                matrix[i][j] = _min_value;
            }
        }
    } else {
        srand(time(nullptr));
        for (i = 0; i < rows; ++i) {
            matrix[i] = new double[columns];
            for (j = 0; j < columns; ++j) {
                matrix[i][j] = GeneralPurposeFunction::map(rand(), 0, RAND_MAX, _min_value, _max_value);
            }
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

void Matrix::multiplyInPlace(const Matrix &multiplied_by) {
    assert(columns == multiplied_by.rows);
    *this = multiply(*this, multiplied_by);
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

Matrix::~Matrix() {
    int i;
    for (i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

Matrix Matrix::VerticalStack(const Matrix &uppermatrix, const Matrix &lower_matrix) {

    assert(uppermatrix.columns == lower_matrix.columns);


    Matrix answer(uppermatrix.rows + lower_matrix.rows, uppermatrix.columns);

    answer.PasteIntoInPlace(uppermatrix, 0, 0);
    answer.PasteIntoInPlace(lower_matrix, uppermatrix.rows, 0);

    return answer;
}

Matrix Matrix::PasteInto(const Matrix &pasted_into, const Matrix &being_pasted, int row_where, int col_where) {
    assert(row_where + being_pasted.rows <= pasted_into.rows and
           col_where + being_pasted.columns <= pasted_into.columns);
    Matrix answer(pasted_into);
    int i, j;
    for (i = row_where; i < row_where + being_pasted.rows; i++) {
        for (j = col_where; j < col_where + being_pasted.columns; j++) {
            pasted_into.matrix[i][j] = being_pasted.matrix[i - row_where][j - col_where];
        }
    }
    return answer;
}

void Matrix::PasteIntoInPlace(const Matrix &being_pasted, int row_where, int col_where) {

    assert(row_where + being_pasted.rows <= rows and
           col_where + being_pasted.columns <= columns);

    int i, j;
    for (i = row_where; i < row_where + being_pasted.rows; i++) {
        for (j = col_where; j < col_where + being_pasted.columns; j++) {
            matrix[i][j] = being_pasted.matrix[i - row_where][j - col_where];
        }
    }
}

Matrix Matrix::HorizontalStack(const Matrix &left_matrix, const Matrix &right_matrix) {

    assert(left_matrix.rows == right_matrix.rows);

    Matrix answer(left_matrix.rows, left_matrix.columns + right_matrix.rows);

    answer.PasteIntoInPlace(left_matrix, 0, 0);
    answer.PasteIntoInPlace(left_matrix, 0, left_matrix.columns);

    return Matrix(0, 0);
}


Matrix Matrix::ApplyFunction(const Matrix &being_modified, double (*function)(double)) {

    Matrix answer(being_modified);
    int i, j;

    for (i = 0; i < answer.rows; i++) {
        for (j = 0; j < answer.columns; j++) {
            answer.matrix[i][j] = function(being_modified.matrix[i][j]);
        }
    }

    return answer;
}

Matrix::Matrix(const Matrix &being_copied) {
    rows = being_copied.rows;
    columns = being_copied.columns;
    matrix = new double *[rows];
    int i, j;
    for (i = 0; i < rows; ++i) {
        matrix[i] = new double[columns];
        for (j = 0; j < columns; ++j) {
            matrix[i][j] = being_copied.matrix[i][j];
        }
    }
}

Matrix Matrix::GetSubMatrix(const Matrix &get_from, int start_row, int start_column, int end_row, int end_column) {

    assert(start_row < end_row and start_column < end_column and start_row < get_from.rows and
           end_row <= get_from.rows and start_column < get_from.columns and end_column <= get_from.columns and
           start_column >= 0 and start_row >= 0);

    Matrix answer(end_row - start_row, end_column - start_column);
    int i, j;
    for (i = 0; i < end_row - start_row; i++) {
        for (j = 0; j < end_column - start_column; j++) {
            answer.matrix[i][j] = get_from.matrix[i + start_row][j + start_column];
        }
    }
    return answer;
}

void Matrix::FromVector(const std::vector<double> numbers, int _rows, int _columns) {
    assert(_rows>0 and _columns>0 and _rows*_columns==numbers.size());
    rows = _rows;
    columns = _columns;
    matrix = new double *[rows];
    int i, j;
    for (i = 0; i < rows; ++i) {
        matrix[i] = new double[columns];
        for (j = 0; j < columns; ++j) {
            matrix[i][j] = numbers[i*columns+j];
        }
    }
}






