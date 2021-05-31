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

    /// Matrix class represents a matrix of real numbers
    /// it uses dynamic allocation to make matrices of any proper given sizes

    // creates matrix of given size with a range of random values between given boundaries
    Matrix(int _rows = 1, int _columns = 1, double _min_val = 0, double _max_value = 0);

    // copy constructor
    Matrix(const Matrix &being_copied);

    // creates matrix from numbers given in vector and make it given size
    Matrix(std::vector<double> numbers, int rows, int columns);

    //reads matrix from file opened by istream
    Matrix(std::istream &is);

    //returns copy of transposed matrix
    Matrix transposed() const;

    /*returns stack of given matrices on top of each other
    *   upper_matrix
     *  lower matrix
    */
    static Matrix VerticalStack(const Matrix &upper_matrix, const Matrix &lower_matrix);

    /* returns stack of given matrices horizontally
     *  first_matrix second_matrix
     */
    static Matrix HorizontalStack(const Matrix &first_matrix, const Matrix &second_matrix);

    // returns result of multiplying given matricees
    static Matrix multiply(const Matrix &first_matrix, const Matrix &second_matrix);

    //returns result of adding two matrices
    static Matrix add(const Matrix &first_matrix, const Matrix &second_matrix);

    //returns result of subtracting given matrices
    static Matrix subtract(const Matrix &first_matrix, const Matrix &second_matrix);

    // returns result of multiplying matrix by scalar
    static Matrix multiplyByScalar(const Matrix &first_matrix, const double scalar);

    // returns result of multiplying matrices element-wise
    static Matrix multiplyElementWise(const Matrix &first_matrix, const Matrix &second_matrix);

    // returns a matrix that has a part of different matrix pasted into itself on given coordinates
    static Matrix PasteInto(const Matrix &pasted_into, const Matrix &being_pasted, int row_where, int col_where);

    // given pointer to a function that maps from doubles to doubles it returns a matrix modified by a function
    static Matrix ApplyFunction(const Matrix &being_modified, double (*function)(double));

    // returns a sub-matrix from given matrix and what part should be taken
    static Matrix GetSubMatrix(const Matrix &get_from, int start_row, int start_column, int end_row, int end_column);

    // returns a matrix which has its values raised to given power
    static Matrix elementsToPower(Matrix &modified, double power); //may delete that later

    // multiplies matrix object in place by other matrix
    void multiplyInPlace(const Matrix &multiplied_by);

    // returns sum of all elements
    double sum();

    // returns max value from matrix
    double maxValue();

    // pastes different matrix into itself on given row and column
    void PasteIntoInPlace(const Matrix &being_pasted, int row_where, int col_where);

    // transposes a matrix in place
    void transpose();

    void inverse(); //not sure if needed

    int determinant(); //not sure if needed

    int rank(); //not sure if needed

    //writes dimensions
    void writeDimensions(std::ostream &os = std::cout);

    //overloaded assign operator
    Matrix operator=(const Matrix &other);

    //overloaded matrix multiplying operator
    Matrix operator*(const Matrix &multiplied_by) const;

    //overloaded addition operator
    Matrix operator+(const Matrix &added) const;

    //overloaded minus operator
    Matrix operator-(const Matrix &substracted) const;

    //overloaded minus operator for scalar subtraction
    Matrix operator-(const double &substracted) const;

    //overloaded multiplying by scalar
    Matrix operator*(double scalar) const;

    //overloaded powering sigh
    Matrix operator^(double scalar);

    //overloaded matrix short subtracting operator
    void operator-=(const Matrix &subtracted);

    //overloaded matrix short addition operator
    void operator+=(const Matrix &added);

    //overloaded matrix short multiplication operator
    void operator*=(double scalar);

    //overloaded element getter/setter
    double &operator()(int row, int col);

    //writes matrix to a ostream
    void write(std::ostream &os = std::cout) const;

    // writes matrix dimensions and matrix itself to a file
    void save(std::ostream &os) const;

    //destructor erases dynamically allocated memory
    ~Matrix();

    int rows, columns;
    double **matrix;

private:
    void free();

    void copy(const Matrix &other);

    void move(Matrix &other);


    /*TODO:
     * -MAYBE add_ones (bias to data)
     */
};
