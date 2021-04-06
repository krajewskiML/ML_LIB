#include <iostream>

#include "Matrix.h"

int main() {

    Matrix jeden(4, 2);
    Matrix dwa(2, 4);
    jeden.write(std::cout);
    jeden.multiplyInPlace(dwa);
    jeden.write(std::cout);
    return 0;
}
