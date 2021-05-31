//
// Created by genez on 21.04.2021.
//

#ifndef ML_LIB_DATA_H
#define ML_LIB_DATA_H


#include "Matrix.h"
#include <iostream>
#include <sstream>

class Data{
    ///Data class is a simple csv reader and is able to store only numerical values

public:
    friend class Matrix;
    //creates data class from csv file
    Data(std::istream &file);

    ~Data();
    //writes data to ostream
    void show(std::ostream &os = std::cout);

    //creates matrix of 0 and places 1 in column of label index from vector
    Matrix labelsToMatrix() const;

    int records, variables;
    Matrix *matrix_representation = nullptr;
private:
    void readHeaders(std::istream &csv_file);

    void readData(std::istream &csv_file);

    std::vector<std::string> headers;
};


#endif //ML_LIB_DATA_H
