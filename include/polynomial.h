#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#include "math_func_ids.h"

#define ERR_STR_LEN 200 // length of strings that prints when errors occured
#define EPSILON 1e-10   // Tolerance used for floating-point comparisons to handle precision errors

/**
 * @brief Structure of polynomial
 *
 */
typedef struct
{
    long deg;
    double complex *coeff;
    char var;
} Polynomial;

/**
 * @brief Initialize polynomial
 *
 * @param poly Polynomial to initialize
 * @return int EXIT_SUCCESS if something error did not occur, EXIT_FAILURE else
 */
int InitPoly(Polynomial *poly);

/**
 * @brief Make new polynomial
 *
 * @param poly Polynomial
 * @param deg Degree of polynomial
 * @return int EXIT_SUCCESS if something error did not occur, EXIT_FAILURE else
 */
int MakePoly(Polynomial *poly, const long deg);

/**
 * @brief Make new monomial
 *
 * @param poly Polynomial
 * @param deg Degree of monomial
 * @param coeff Coefficient of monomial
 * @return int EXIT_SUCCESS if something error did not occur, EXIT_FAILURE else
 */
int MakeMono(Polynomial *poly, const long deg, const double complex coeff);

/**
 * @brief Clean polynomial
 *
 * @param poly Polynomial
 */
void FreePoly(Polynomial *poly);

/**
 * @brief Set variable of polynomial (default variable is x)
 *
 * @param poly Polynomial
 * @param var variable character
 */
void SetVar(Polynomial *poly, const char var);

/**
 * @brief Print
 *
 * @param format
 * @param ...
 * @return int EXIT_SUCCESS if something error did not occur, EXIT_FAILURE else
 */
int PrintFmt(const char *format, ...);

/**
 * @brief Print polynomial
 * 
 * @param poly Polynomial to print
 * @return int EXIT_SUCCESS if something error did not occur, EXIT_FAILURE else
 */
int PrintPoly(const Polynomial poly);

/**
 * @brief Degree of poly
 *
 * @param poly Polynomial
 * @return int Degree of poly. -1 if poly is 0
 */
int Deg(const Polynomial poly);

/**
 * @brief Normalize degree of polynomial, i.e., ignore haed zero terms
 *
 * @param poly Polynomial to normalize
 */
void NormalizeDeg(Polynomial *poly);

/**
 * @brief Normalize coefficients of polynomial, i.e., make polynomial monic
 *
 * @param poly Polynomial to normalize
 */
void NormalizeCoeff(Polynomial *poly);

/**
 * @brief Copy polynomial
 *
 * @param poly1 Polynomial to copy
 * @param poly Polynomial to be overwritten
 * @return int EXIT_SUCCESS if something error did not occur, EXIT_FAILURE else
 */
int Copy(const Polynomial poly1, Polynomial *poly);

/**
 * @brief Leading coefficient of polynomial
 *
 * @param poly Polynomial
 * @return double Leading coefficient of poly
 */
double complex LC(const Polynomial poly);

/**
 * @brief Leading term of polynomial
 *
 * @param poly Polynomial
 * @param lt Leading term of ply
 * @return int EXIT_SUCCESS if something error did not occur, EXIT_FAILURE else
 */
int LT(const Polynomial poly, Polynomial *lt);

/**
 * @brief Substitute value to polynomial
 *
 * @param polynomial Polynomail to be substituted
 * @param a Value to substitute
 * @return double poly(a)
 */
double complex Substitute(const Polynomial poly, const double complex a);

/**
 * @brief Add two polynomials. poly <- poly1 + poly2
 *
 * @param poly1 Polynomial to add
 * @param poly2 Polynomial to add
 * @param poly Polynomial to be added
 * @return int EXIT_SUCCESS if something error did not occur, EXIT_FAILURE else
 */
int AddPoly(const Polynomial poly1, const Polynomial poly2, Polynomial *poly);

/**
 * @brief Subtract two polynomials. poly <- poly1 - poly2
 *
 * @param poly1
 * @param poly2
 * @param poly
 * @return int
 */
int SubtrPoly(const Polynomial poly1, const Polynomial poly2, Polynomial *poly);

/**
 * @brief Multiply two polynomials. poly <- poly1 * poly2
 *
 * @param poly1 Polynomial to multiply
 * @param poly2 Polynomial to multiply
 * @param poly Polynomial to be multiplied
 * @return int EXIT_SUCCESS if something error did not occur, EXIT_FAILURE else
 */
int MulPoly(const Polynomial poly1, const Polynomial poly2, Polynomial *poly);

/**
 * @brief Multipy polynomial and scalar value. poly <- scalar * poly1
 *
 * @param scalar Scalar value to multipy
 * @param poly1 Polynomial to multiply
 * @param poly Polynomial to be multiplied
 * @return int EXIT_SUCCESS if something error did not occur, EXIT_FAILURE else
 */
int MulScalar(const double complex scalar, const Polynomial poly1, Polynomial *poly);

/**
 * @brief Negativize polynomial. poly1 <- -poly
 *
 * @param poly Polynomial to negativize
 * @param poly1 Negativized polyomial
 * @return int EXIT_SUCCESS if something error did not occur, EXIT_FAILURE else
 */
int Minus(const Polynomial poly1, Polynomial *poly);

/**
 * @brief Divide two monomials. mono <- mono1 / mono2
 *
 * @param mono1 Monomial to be  divided
 * @param mono2 Monomial to divide
 * @param mono Quotient of mono1 / mono2
 * @return int EXIT_SUCCESS if something error did not occur, EXIT_FAILURE else
 */
int MonoDiv(const Polynomial mono1, const Polynomial mono2, Polynomial *mono);

/**
 * @brief Divide two polynomial. poly <- poly1 / poly2
 *
 * @param poly1 Polynomial to be divided
 * @param poly2 Polynomial to divide
 * @param poly Quotient of poly1 / poly2
 * @return int EXIT_SUCCESS if something error did not occur, EXIT_FAILURE else
 */
int DivPoly(const Polynomial poly1, const Polynomial poly2, Polynomial *rem, Polynomial *quo);

/**
 * @brief Compute greatest common divisor(GCD) of two polynomials poly1 and poly2
 *
 * @param poly1 Polynomial
 * @param poly2 Polynomial
 * @param d GCD of poly1 and poly2
 * @param a poly1/d
 * @param b poly2/d
 * @return int EXIT_SUCCESS if something error did not occur, EXIT_FAILURE else
 */
int GCD(const Polynomial poly1, const Polynomial poly2, Polynomial *d);

/**
 * @brief Compute approximate polynomial of a given function using Maclaurin expansion
 *
 * @param func_name Name of function (defined as macros).
 * @param deg Degree of apprximate polynomial.
 * @param poly Polynomial to be computed.
 * @return int EXIT_SUCCESS if something error did not occur, EXIT_FAILURE else
 */
int MaclaurinExp(const int func_name, const long deg, Polynomial *poly);

/**
 * @brief 
 * 
 * @param n 
 * @param omega 
 * @param a 
 * @param alpha 
 * @return int 
 */
int FFT(const long n, const double complex omega, const Polynomial a, Polynomial* alpha);

/**
 * @brief Test if poly is monomial or not
 *
 * @param poly polynomial to be tested
 * @return int 1 if poly is monomial, 0 if not
 */
int IsMono(const Polynomial poly);

/**
 * @brief Test if poly is 0
 *
 * @param poly polynomial to be testeed
 * @return int 1 if poly is 0, 0 if not
 */
int IsZero(const Polynomial poly);

/**
 * @brief Test if poly is monic polynomial ot not
 *
 * @param poly polynomial to be tested
 * @return int 1 if poly is monic, 0 if not
 */
int IsMonic(const Polynomial poly);

#endif // !POLYNOMIAL_H
