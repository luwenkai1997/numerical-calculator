#ifndef calculus_h
#define calculus_h
#include "interpolation.h"

// Estimate derivative at t through Lagrange Polynomials
template <typename T>
T differentiate(const T& t, const std::vector<T>& x, const std::vector<T>& y);

// Estimate the intehral of y(x) through Composite Numerical Integration
template <typename T>
T composite(const std::vector<T>& x, const std::vector<T>& y, int n);



template <typename T>
T differentiate(const T& t, const std::vector<T>& x, const std::vector<T>& y) {
    T h = 0.5;
    T lhs = langange(t-h, x, y);
    T rhs = langange(t+h, x, y);
    T derivative = (rhs-lhs) / (2*h);
    return derivative;
}


template <typename T>
T composite(const std::vector<T>& x, const std::vector<T>& y, int n) {
    T a = x[0];
    T b = x[n-1];
    T h = (b-a)/n;
    T integral = 0;
    
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
