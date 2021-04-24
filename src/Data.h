//
// Created by genez on 21.04.2021.
//

#ifndef ML_LIB_DATA_H
#define ML_LIB_DATA_H


#include "Matrix.h"
#include <iostream>
#include <sstream>
class Data{
public:
    Data(std::istream &file);
    void show(std::ostream &os=std::cout);
    ~Data();

    Matrix *matrix_representation;
private:
    void readHeaders(std::istream& csv_file);
    void readData(std::istream& csv_file);
    std::vector<std::string> headers;
};


#endif //ML_LIB_DATA_H
