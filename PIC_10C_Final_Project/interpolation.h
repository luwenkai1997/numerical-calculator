#ifndef interpolation_h
#define interpolation_h

#include <iomanip>
#include <iostream>
#include <cmath>
#include <vector>

// interpolation via Lagrange Polynomials
double langange(const int& t, const std::vector<double>& x, const std::vector<double>& y);



double langange(const int& t, const std::vector<double>& x, const std::vector<double>& y) {
    double output = 0;
    std::vector<double> L(x.size());
    
    for (int i = 0; i < x.size(); ++i) {
        double numerator = 1;
        double denominator = 1;
        
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
