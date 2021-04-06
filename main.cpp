#include <iostream>

#include "Matrix.h"

int main() {

    Matrix jeden(4, 2);
    Matrix dwa(2, 4);
    Matrix wynik = Matrix::multiply(jeden, dwa);
    wynik.write(std::cout);
    wynik = wynik.transposed();
    wynik.write(std::cout);
    wynik.transpose();
    wynik.write(std::cout);
    return 0;
}
