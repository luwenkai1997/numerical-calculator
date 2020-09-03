# Final Project: Numerical Calculator 

![title picture](https://github.com/luwenkai1997/pic-10c-final-project/blob/master/title_picture.jpg)

## Background

This quarter, I took MATH 151A: Numerical Methods, and learned several ways to solve different math problems. I realized that solving real-life math problems with numerical methods is very different from solving problems with algebraic or analysis tools, so I decided to write these numerical methods in C++ codes to get a useful tool for future use. 

## Introduction

This project can help to solve some basic mathematical problems using numerical methods. It has four funcitons: 

1. Solving Polynomial Equations in R

2. Interpolation of (x,y) Data

3. Estimating Derivaticves

4. Integtation of Data

For each function, the data and results will be written into a file "log.txt". 

## Function 1: Solving Polynomial Equations in R

Function 1 can help to solve a polynomial function with degree less than or equal to 4.

For functions with degree 2, we can get exact roots through [quadratic formula](https://en.wikipedia.org/wiki/Quadratic_formula).

For functions with degree 3 or higher, we will only get 1 root through [bisection method](https://en.wikipedia.org/wiki/Bisection_method). There might be other roots existing other than the root this program provides. 

[test case of degree 1 function](https://github.com/luwenkai1997/pic-10c-final-project/blob/master/test_case/test_case_1)

[test case of degree 2 function](https://github.com/luwenkai1997/pic-10c-final-project/blob/master/test_case/test_case_2)

[test case of degree 3 function](https://github.com/luwenkai1997/pic-10c-final-project/blob/master/test_case/test_case_3)

## Function 2: Interpolation of (x,y) Data

Function 2 can help to aprroximate the value of a function through [Lagrange Polynomials](https://en.wikipedia.org/wiki/Lagrange_polynomial). 

[test case of y(x)=x^2+1 with 3 data points](https://github.com/luwenkai1997/pic-10c-final-project/blob/master/test_case/test_case_4)

## Function 3: Estimating Derivaticves

Function 3 can help to estimate the derivative of a function with at most 5 data points. The approximation might not be accurate when the data size is small or the x data are very close to 0. 

[test case of y(x)=x^2 with 5 data points](https://github.com/luwenkai1997/pic-10c-final-project/blob/master/test_case/test_case_5)

## Function 4: Integration of Data

Function 4 can help to estimate the integral of an unknown function y(x) with up to 10 (x,y) data points. This approximation is done by [Composite Numerical Integration](https://www3.nd.edu/~zxu2/acms40390F15/Lec-4.4.pdf). The approximation might not be accurate when the data size is small or the x data are large in absolute values.

[test case of y(x)=x with 6 data points](https://github.com/luwenkai1997/pic-10c-final-project/blob/master/test_case/test_case_6)

## Challenges I Meet

1. I'm not sure whether I should use template to allow for different types of input. 

I try to use template in the header files so that the users can use various types of inputs for the coefficients, but at the same time I realize that no matter which type of input we use, the output of the program (e.g. roots of an equation or estimate of the derivative) will always be in the type of double, so template is not necessary in this program. 

2. How to calculate the coefficients in Lagrange Polynomials.

To get the coefficients in Lagrange Polynomial, I use several for-loops to calculate in the header file, which looks ugly. I try to use iterators for make the code look better, but eventually I don't see a big difference since the structure of input is quite simple. Therefore, I choose to use for-loop. 

## Reference

Numerical Analysis (10th edition) by Richard L. Burden, J. Douglas Faires, and Annette M. Burden. 

