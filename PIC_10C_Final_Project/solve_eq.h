#ifndef solve_eq_h
#define solve_eq_h

#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>

// Solve polynomial equations with degree 2
void solve_quadratic_eq(const std::vector<double>& coeff) {
    std::cout << std::fixed;
    std::cout << std::setprecision(3);
    double delta = pow(coeff[1],2) - 4 * coeff[0] * coeff[2];
    double x1 = (-1 * coeff[1] + sqrt(delta)) / (2 * coeff[2]);
    double x2 = (-1 * coeff[1] - sqrt(delta)) / (2 * coeff[2]);
    std::cout << "The roots of this equation are " << x1 << " and " << x2 << "\n\n";
}




#endif
