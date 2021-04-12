#include <iostream>

#include "Matrix.h"
#include "mathFunctions.h"
int main() {
      double (*foo)(double);
      foo = ActivationFunction::sigmoid;
//    Matrix checker(1, 10, -2, 2);
//    checker.write();
//    Matrix result = Matrix::ApplyFunction(checker, foo);
//    checker.write();
//    result.write();

    Matrix first(1, 10, -5, 5);
    Matrix second = Matrix::ApplyFunction(first, foo);
    first.write();
    second.write();
    return 0;
}
