//
// Created by genez on 21.04.2021.
//

#ifndef ML_LIB_DATA_H
#define ML_LIB_DATA_H


#include "Matrix.h"
#include <iostream>
#include <sstream>

class Data{
    friend class Matrix;
public:
    Data(std::istream &file);

    ~Data();

    void show(std::ostream &os = std::cout);

    Matrix labelsToMatrix() const;

    int records, variables;
    Matrix *matrix_representation = nullptr;
private:
    void readHeaders(std::istream &csv_file);

    void readData(std::istream &csv_file);


    std::vector<std::string> headers;
};


#endif //ML_LIB_DATA_H
