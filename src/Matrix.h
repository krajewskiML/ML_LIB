//
// Created by genez on 06.04.2021.
//

#ifndef ML_LIB_MATRIX_H
#define ML_LIB_MATRIX_H

#endif //ML_LIB_MATRIX_H

#include <iostream>
#include <cassert>
#include <time.h>
#include <random>
#include "mathFunctions.h"

class Matrix {
public:

    Matrix(int _rows = 1, int _columns = 1, double _min_val = 0, double _max_value = 0);

    Matrix(const Matrix &being_copied);

    Matrix(std::vector<double> numbers, int rows, int columns);

    Matrix transposed() const;

    static Matrix VerticalStack(const Matrix &first_matrix, const Matrix &second_matrix);

    static Matrix HorizontalStack(const Matrix &first_matrix, const Matrix &second_matrix);

    static Matrix multiply(const Matrix &first_matrix, const Matrix &second_matrix);

    static Matrix add(const Matrix &first_matrix, const Matrix &second_matrix);

    static Matrix substract(const Matrix &first_matrix, const Matrix &second_matrix);

    static Matrix multiplyByScalar(const Matrix &first_matrix, const double scalar);

    static Matrix multiplyElementWise(const Matrix &first_matrix, const Matrix &second_matrix);

    static Matrix PasteInto(const Matrix &pasted_into, const Matrix &being_pasted, int row_where, int col_where);

    static Matrix ApplyFunction(const Matrix &being_modified, double (*function)(double));

    static Matrix GetSubMatrix(const Matrix &get_from, int start_row, int start_column, int end_row, int end_column);

    static Matrix elementsToPower(Matrix &modified, int power); //may delete that later

    void multiplyInPlace(const Matrix &multiplied_by);

    double sum();

    void PasteIntoInPlace(const Matrix &being_pasted, int row_where, int col_where);

    void write(std::ostream &os = std::cout) const;

    void transpose();

    void inverse(); //not sure if needed

    int determinant(); //not sure if needed

    int rank(); //not sure if needed

    void showDimensions(std::ostream &os = std::cout);

    void operator-=(const Matrix &substracted);

    void operator+=(const Matrix &added);

    void operator*=(double scalar);

    Matrix operator*(const Matrix &multiplied_by) const;

    Matrix operator+(const Matrix &added) const;

    Matrix operator-(const Matrix &substracted) const;

    Matrix operator*(double scalar) const;

    Matrix operator^(double scalar);


    /*TODO:
     * -MAYBE add_ones (bias to data)
     */


    ~Matrix();

//private:

    int rows, columns;
    double **matrix;

};
