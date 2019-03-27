#ifndef calculus_h
#define calculus_h
#include "interpolation.h"

// Estimate derivative at t through Lagrange Polynomials
double differentiate(const double& t, const std::vector<double>& x, const std::vector<double>& y);

double composite(const std::vector<double>& x, const std::vector<double>& y, int n);



double differentiate(const double& t, const std::vector<double>& x, const std::vector<double>& y) {
    double h = 0.5;
    double lhs = langange(t-h, x, y);
    double rhs = langange(t+h, x, y);
    double derivative = (rhs-lhs) / (2*h);
    return derivative;
}


double composite(const std::vector<double>& x, const std::vector<double>& y, int n) {
    double a = x[0];
    double b = x[n-1];
    double h = (b-a)/n;
    double integral = 0;
    
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            integral = integral + h/3 * y[i];
        }
        else if (i == n-1) {
            integral = integral + h/3 * y[i];
        }
        else if (i % 2 == 0) {
            integral = integral + 2*h/3 * y[i];
        }
        else {
            integral = integral + 4*h/3 * y[i];
        }
    }
    
    return integral;
}


#endif 
