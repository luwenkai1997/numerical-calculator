#include <iostream>
#include <iomanip>
#include <cmath>
#include "solve_eq.h"
#include "calculus.h"



int main() {
    int mode = 0;
    
    // Ask the user to choose the function
    std::cout << "Welcome to use Wenkai's calculator! \n";
    std::cout << "Here are the functions of this calculator: \n\n";
    std::cout << "1. Solving Polynomial Equations \n";
    std::cout << "2. Interpolation of Data \n";
    std::cout << "3. Estimating Derivaticves \n";
    std::cout << "4. Integtation of Data \n\n";
    std::cout << "Please enter the function you want to use: ";
    std::cin >> mode;
    
    // check whether the input is valid
    while (mode != 1 && mode != 2 && mode && 3 && mode != 4) {
        std::cout << "Invalid input! Please enter 1, 2, 3, or 4: ";
        std::cin >> mode;
    }
    
    
    
    
    
    
    return 0;
}



