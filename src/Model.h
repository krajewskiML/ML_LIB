//
// Created by genez on 12.04.2021.
//

#ifndef ML_LIB_MODEL_H
#define ML_LIB_MODEL_H

#include "Matrix.h"
#include <cassert>
#include <iostream>
class Model {
public:
    virtual void show(std::ostream &out=std::cout) const = 0;

    virtual void save(std::ostream &out) const = 0; //maybe h5 format

    virtual void read(std::istream &in) = 0; //maybe h5 format
};


#endif //ML_LIB_MODEL_H
