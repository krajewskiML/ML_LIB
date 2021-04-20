cmake_minimum_required(VERSION 3.17)
project(ML_LIB)

set(CMAKE_CXX_STANDARD 14)

#include_directories(ML_LIB Matrix.h Matrix.cpp)

add_executable(ML_LIB main.cpp src/Matrix.h src/Matrix.cpp src/mathFunctions.cpp src/mathFunctions.h src/Model.h src/SupervisedModel.cpp src/SupervisedModel.h src/Regression.cpp src/Regression.h src/LogisticRegression.cpp src/LogisticRegression.h src/PolynomialRegression.cpp src/PolynomialRegression.h src/LinearRegression.cpp src/LinearRegression.h)