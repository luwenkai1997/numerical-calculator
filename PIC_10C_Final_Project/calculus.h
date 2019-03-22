#ifndef calculus_h
#define calculus_h
#include "interpolation.h"

// Estimate derivative at t through Lagrange Polynomials
double differentiate(const double& t, const std::vector<double>& x, const std::vector<double>& y);




double differentiate(const double& t, const std::vector<double>& x, const std::vector<double>& y) {
    double h = 0.5;
    double lhs = langange(t-h, x, y);
    double rhs = langange(t+h, x, y);
    double derivative = (rhs-lhs) / (2*h);
    return derivative;
}



#endif 
