#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <fstream>
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
    while (mode != 1 && mode != 2 && mode != 3 && mode != 4) {
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
            
            //print out the results
            std::ofstream fout;
            fout.open("log");
            fout << "-------------------------------- \n\n";
            fout << "Your equation is: \n";
            fout << coeff[0] << " + " << coeff[1] << "*x = 0 \n";
            fout << "The root is: \n";
            fout << "x = " << -1 * coeff[0] / coeff[1] << "\n\n";
            fout << "-------------------------------- \n\n";
            fout.close();
            
            return 0;
        }
        
        // if this function has degree 2...
        if (n == 2) {
            double delta = pow(coeff[1],2) - 4 * coeff[0] * coeff[2];
            if (delta < 0) {
                std::cout << "No real root! \n";
                return 0;
            }
            double x1 = (-1 * coeff[1] + sqrt(delta)) / (2 * coeff[2]);
            double x2 = (-1 * coeff[1] - sqrt(delta)) / (2 * coeff[2]);
            solve_quadratic_eq(coeff);
            
            //print out the results
            std::ofstream fout;
            fout.open("log");
            fout << "-------------------------------- \n\n";
            fout << "Your equation is: \n\n";
            fout << coeff[0] << " + " << coeff[1] << "*x + " << coeff[2] << "*x^2 = 0 \n\n";
            fout << "The roots are: \n";
            fout << "x_1 = " << x1 << ", x_2 = " << x2 << "\n\n";
            fout << "-------------------------------- \n\n";
            fout.close();
            
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
            
            //print out the results
            std::ofstream fout;
            fout.open("log");
            fout << "-------------------------------- \n\n";
            fout << "Your equation is: \n\n";
            if (n == 3) {
                fout << coeff[0] << " + " << coeff[1] << "*x + " << coeff[2] << "*x^2 + " << coeff[3] << "*x^3 = 0 \n\n";
            }
            else
                fout << coeff[0] << " + " << coeff[1] << "*x + " << coeff[2] << "*x^2 + " << coeff[3] << "*x^3 + " << coeff[4] << "*x^4 = 0 \n\n";
            fout << "Lower bound of the root: " << lowerbound << "\n";
            fout << "Upper bound of the root: " << upperbound << "\n\n";
            fout << "The root is: \n";
            fout << "x = " << root << "\n\n";
            fout << "This might not the only root of this equation. \n\n";
            fout << "-------------------------------- \n\n";
            fout.close();
            
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
        
        double t = 0;
        std::cout << "At which x do you want to estimate the value of y? ";
        std::cin >> t;
        
        std::cout << "Via Lanrange polynomial, the estimated value of the function y(x) at x = " << t << " is: " << langange(t, x, y) << " \n\n";
        
        return 0;
    }

    
    
    // Function 3: Estimating Derivaticves
    if (mode == 3) {
        int n = 0;
        std::cout << "Welcome to estimating derivaticves! \n";
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
        
        double t = 0;
        std::cout << "At which x do you want to estimate the derivative of y? ";
        std::cin >> t;
        
        std::cout << "The estimated derivative of the function y(x) at x = " << t << " is: " << differentiate(t, x, y) << " \n";
        std::cout << "The estimation may have error depending on the data. \n\n";
        
        return 0;
        
    }
    
    
    // Function 4: Integtation of Data
    if (mode == 4) {
        int n = 0;
        std::cout << "Welcome to integration of data! \n";
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



