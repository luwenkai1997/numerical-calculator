#ifndef solve_eq_h
#define solve_eq_h

#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>

// Solve polynomial equations with degree 2
template <typename T>
void solve_quadratic_eq(const std::vector<T>& coeff);

// Solve polynomial equation with degree > 2 via Bisection method
template <typename T>
T bisection(const std::vector<T>& coeff, const T& l, const T& u);

// Compute the value of polynomial
template <typename T>
T value(const T& x, const std::vector<T>& coeff);




template <typename T>
void solve_quadratic_eq(const std::vector<T>& coeff) {
    std::cout << std::fixed;
    std::cout << std::setprecision(3);
    double delta = pow(coeff[1],2) - 4 * coeff[0] * coeff[2];
    double x1 = (-1 * coeff[1] + sqrt(delta)) / (2 * coeff[2]);
    double x2 = (-1 * coeff[1] - sqrt(delta)) / (2 * coeff[2]);
    std::cout << "The roots of this equation are " << x1 << " and " << x2 << "\n\n";
}

template <typename T>
T bisection(const std::vector<T>& coeff, const T& l, const T& u) {
    std::vector<T> x(50);
    std::vector<T> a(50);
    std::vector<T> b(50);
    x[0] = 0.5 * (l + u);
    a[0] = l;
    b[0] = u;
    for (int i = 0; i < 49; ++i) {
        if (value(a[i], coeff) * value(x[i], coeff) < 0) {
            a[i+1] = a[i];
            b[i+1] = x[i];
            x[i+1] = 0.5 * (a[i+1] + b[i+1]);
        }
        else if (value(a[i], coeff) * value(x[i], coeff) > 0) {
            b[i+1] = b[i];
            a[i+1] = x[i];
            x[i+1] = 0.5 * (a[i+1] + b[i+1]);
        }
        else {
            return x[i];
        }
    }
    return x[49];
    
}

template <typename T>
T value(const T& x, const std::vector<T>& coeff) {
    T output = 0;
    for (int i = 0; i < coeff.size(); ++i) {
        output += coeff[i] * pow(x,i);
    }
    return output;
}


#endif
