//
// Created by genez on 16.04.2021.
//

#ifndef ML_LIB_SUPERVISEDMODEL_H
#define ML_LIB_SUPERVISEDMODEL_H

#include "Model.h"
#include "Data.h"
class SupervisedModel : public Model {
    ///Interface class for all algorithms that require labels to learn
public:
    //fits models to data with given labels
    virtual void fit(const Data &data, const Data &label, double learning_rate, int epochs) = 0;

    //creates prediction based on actual state of the model
    virtual Matrix predict(const Data &data) const = 0;

    //test efficiency of the model
    virtual void test(const Data &data, const Data &label) const = 0;
};


#endif //ML_LIB_SUPERVISEDMODEL_H
