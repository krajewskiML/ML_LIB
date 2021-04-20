//
// Created by genez on 16.04.2021.
//

#ifndef ML_LIB_SUPERVISEDMODEL_H
#define ML_LIB_SUPERVISEDMODEL_H

#include "Model.h"

class SupervisedModel : public Model {
public:
    virtual void fit(const Matrix &data, const Matrix &label, double learning_rate) = 0;

    virtual Matrix predict(const Matrix &data) const = 0;

    virtual void test(const Matrix &data, const Matrix &label) const = 0;
};


#endif //ML_LIB_SUPERVISEDMODEL_H
