//
// Created by genez on 07.04.2021.
//

#include "mathFunctions.h"

namespace ActivationFunction {
    double sigmoid(double val) {
        return 1 / (std::exp(-val) + 1);
    }

    double relu(double val) {
        if (val <= 0) {
            return 0;
        }
        return val; //may make it some constant * val in the future
    }

    double arctan(double val) {
        return atan(val);
    }
}

namespace DerivativeOfActivationFunction {
    double sigmoid(double val) {
        return ActivationFunction::sigmoid(val) * (1 - ActivationFunction::sigmoid(val));
    }

    double relu(double val) {
        if (val <= 0) {
            return 0;
        }
        return 1; //may make it some constant in the future
    }

    double arctan(double val) {
        return 1 / (1 + val * val);
    }
}

namespace Error {
    double square(double label, double guess) {
        return (guess - label) * (guess - label);
    }

    double absolute(double label, double guess) {
        return std::abs(guess - label);
    }
}

namespace DerivativeOfError {
    double square(double label, double guess) {
        return 2 * (label - guess);
    }

    double absolute(double label, double guess) {
        if (label > guess) {
            return 1;
        }
        return -1;
    }
}

namespace GeneralPurposeFunction {
    double map(double val, double from_min, double from_max, double to_min, double to_max) {
        assert(from_min <= from_max and from_max >= val and from_min <= val and to_min <= to_max);
        return ((val - from_min) / (from_max - from_min)) * (to_max - to_min) + to_min;
    }
}