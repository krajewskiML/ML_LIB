//
// Created by genez on 21.04.2021.
//


#include "Data.h"


void Data::readHeaders(std::istream &csv_file) {
    std::string all_headers, single_header;
    std::getline(csv_file, all_headers);
    std::stringstream first_line(all_headers);
    while (std::getline(first_line, single_header, ',')) {
        headers.push_back(single_header);
    }
}

void Data::readData(std::istream &csv_file) {
    std::string num, line;
    std::vector<double> all_numbers;
    int line_counter = 0;
    while (std::getline(csv_file, line)) {
        std::stringstream linestream(line);
        while (std::getline(linestream, num, ',')) {
            all_numbers.push_back(std::stod(num));
        }
        line_counter++;
    }
    matrix_representation = new Matrix(all_numbers, line_counter, headers.size());
}

Data::Data(std::istream &file) {
    readHeaders(file);
    readData(file);
    records = matrix_representation->rows;
    variables = matrix_representation->columns;
}

Data::~Data() {
    delete matrix_representation;
}


void Data::show(std::ostream &os) {
    for (const auto &header : headers) {
        os << header << ' ';
    }
    os << '\n';
    matrix_representation->write(os);
}

Matrix Data::labelsToMatrix() const{
    int num_of_classes = matrix_representation->maxValue();
    Matrix labelsMatrix(records, num_of_classes+1);
    for(int i=0; i<records; i++){
        labelsMatrix(i,(bool)matrix_representation->matrix[i][0])=1;
    }
    return labelsMatrix;
}


