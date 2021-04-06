//
// Created by genez on 06.04.2021.
//

#ifndef ML_LIB_MATRIX_H
#define ML_LIB_MATRIX_H

#endif //ML_LIB_MATRIX_H
#include <iostream>
#include <cassert>
class Matrix{
public:

    Matrix(int _rows, int _columns);

    Matrix transposed() const;

    static Matrix multiply(const Matrix& first_matrix,const Matrix& second_matrix);

    void multiplyInPlace(const Matrix& multiplied_by);

    void write(std::ostream &os) const;

    void transpose();

    void inverse(); //not sure if needed

    int determinant(); //not sure if needed

    int rank(); //not sure if needed

    void operator = (const Matrix &_matrix);

    ~Matrix();
private:
    int rows, columns;
    double **matrix;

};
