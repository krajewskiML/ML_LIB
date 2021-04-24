#include <iostream>

#include "src/Data.h"
#include <fstream>

int main() {
    std::ifstream file("heart.csv");
    Data check(file);
    check.show();
    return 0;
}
