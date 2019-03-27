#ifndef interpolation_h
#define interpolation_h

#include <iomanip>
#include <iostream>
#include <cmath>
#include <vector>

// interpolation via Lagrange Polynomials
template <typename T>
T langange(const T& t, const std::vector<T>& x, const std::vector<T>& y);



template <typename T>
T langange(const T& t, const std::vector<T>& x, const std::vector<T>& y) {
    T output = 0;
    std::vector<T> L(x.size());
    
    for (int i = 0; i < x.size(); ++i) {
        T numerator = 1;
        T denominator = 1;
        
        for (int j = 0; j < x.size(); ++j) {
            if (i != j) {
                numerator *= (t-x[j]);
                denominator *= (x[i]-x[j]);
            }
        }
        L[i] = numerator / denominator;
    }
    
    for (int i = 0; i < x.size(); ++i) {
        output += L[i]*y[i];
    }
    
    return output;
}

#endif
