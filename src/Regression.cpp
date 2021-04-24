//
// Created by genez on 16.04.2021.
//

#include "Regression.h"

Matrix Regression::hypothesis(const Data &data) {
    assert(predictor!= nullptr);
    return (*data.matrix_representation)*(*predictor);
}

void Regression::show(std::ostream &out) const {
    out<<"Model has "<<(predictor->rows)*(predictor->columns)<<" parameters"<<'\n';
}
