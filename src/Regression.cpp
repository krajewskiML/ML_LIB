//
// Created by genez on 16.04.2021.
//

#include "Regression.h"

Matrix Regression::hypothesis(const Data &data) {
    assert(predictor!= nullptr);

    return Matrix();
}

Matrix Regression::addOnes(Matrix &data) {
    Matrix ones(data.rows, 1, 1, 1), ans = Matrix::HorizontalStack(data, ones);
    return ans;
}

void Regression::show(std::ostream &out) const {
    out<<"Model has "<<(predictor->rows)*(predictor->columns)<<" parameters"<<'\n';
}
