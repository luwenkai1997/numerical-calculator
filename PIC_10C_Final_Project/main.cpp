#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include "solve_eq.h"
#include "interpolation.h"
#include "calculus.h"


int main() {
    int mode = 0;
    
    // Ask the user to choose the function
    std::cout << "Welcome to use Wenkai's calculator! \n";
    std::cout << "Here are the functions of this calculator: \n\n";
    std::cout << "1. Solving Polynomial Equations in R \n";
    std::cout << "2. Interpolation of (x,y) Data \n";
    std::cout << "3. Estimating Derivaticves \n";
    std::cout << "4. Integtation of Data \n\n";
    std::cout << "Please enter the function you want to use: ";
    std::cin >> mode;
    
    // check whether the input is valid
    while (mode != 1 && mode != 2 && mode && 3 && mode != 4) {
        std::cout << "Invalid input! Please enter 1, 2, 3, 4: ";
        std::cin >> mode;
    }
    
    
    
    // Function 1: Solving Polynomial Equations in R
    if (mode == 1) {
        int n = 0; // degree of the polynomial
        std::cout << "Please enter the degree of the polynomial function you want to solve (up to 4): ";
        std::cin >> n;
        
        // check whether the input is valid
        while (n != 1 && n != 2 && n != 3 && n != 4) {
            std::cout << "Invalid input! Please enter 1, 2, 3, 4: ";
            std::cin >> n;
        }
        
        // ask for coefficients of the polynomial
        std::cout << "The function is in the form: f(x) = a_0 + a_1 * x + a_2 * x^2 + a_3 * x^3 + a_4 * x^4 = 0 \n";
        std::vector<double> coeff(n+1);
        for (int i = 0; i < n+1; ++i) {
            std::cout << "Please enter the value of a_" << i << ": ";
            std::cin >> coeff[i];
        }
        
        // if this function has degree 1...
        if (n == 1) {
            std::cout << "The root of this function is " << -1 * coeff[0] / coeff[1] << "\n\n";
            return 0;
        }
        
        // if this function has degree 2...
        if (n == 2) {
            solve_quadratic_eq(coeff);
            return 0;
        }
        
        // if this function has degree higher 3 or 4...
        if (n > 2) {
            double upperbound;
            double lowerbound;
            std::cout << "Please enter the upper and lower bound of the root.\n";
            std::cout << "Make sure the polynomial has different signs at the boundaries.\n";
            std::cout << "Upper bound of the root: ";
            std::cin >> upperbound;
            std::cout << "Lower bound of the root: ";
            std::cin >> lowerbound;
            double root = bisection(coeff, lowerbound, upperbound);
            std::cout << "\nOne root of this equation is " << std::setprecision(3) << root << "\n";
            std::cout << "This might not the only root of this equation. \n\n";
            return 0;
        }
    }
    
    
    
    // Function 2: Interpolation of (x,y) Data
    if (mode == 2) {
        int n = 0; // number of data points
        std::cout << "Welcome to interpolation of data! \n";
        std::cout << "How many data point do you have? (up to 5) ";
        std::cin >> n;
        std::vector<double> x(n);
        std::vector<double> y(n);
        std::cout << "Now, please enter the data points following instructions. \n";
        for (int i = 0; i < n; ++i) {
            std::cout << "Value of x_" << i << ": ";
            std::cin >> x[i];
            std::cout << "Value of y_" << i << ": ";
            std::cin >> y[i];
        }
        
        

        
        
    }
    
    
    
    
    
    
    
    
    return 0;
}



