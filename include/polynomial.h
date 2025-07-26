#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <stdio.h>
#include <stdlib.h>

#define EPSILON 1e-10

/**
 * @brief Structure of polynomial
 *
 */
typedef struct
{
    long deg;
    double *coeff;
    char var;
} Polynomial;

/**
 * @brief Initialization of polynomial
 *
 * @param poly Polynomial
 * @param deg Degree of polynomial
 * @return int EXIT_SUCCESS if something error did not occur, EXIT_FAILURE else
 */
int InitPoly(Polynomial *poly, const long deg);

/**
 * @brief Initialization of monomial
 *
 * @param poly Polynomial
 * @param deg Degree of monomial
 * @param coeff Coefficient of monomial
 * @return int EXIT_SUCCESS if something error did not occur, EXIT_FAILURE else
 */
int InitMono(Polynomial *poly, const long deg, const double coeff);

/**
 * @brief Clean polynomial
 *
 * @param poly Polynomial
 */
void ClearPoly(Polynomial *poly);

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
 * @brief Degree of poly
 *
 * @param poly Polynomial
 * @return int Degree of poly. -1 if poly is 0
 */
int Deg(const Polynomial poly);

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
double LC(const Polynomial poly);

/**
 * @brief Leading term of polynomial
 *
 * @param poly Polynomial
 * @param lt Leading term of ply
 * @return int EXIT_SUCCESS if something error did not occur, EXIT_FAILURE else
 */
int LT(const Polynomial poly, Polynomial *lt);

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
int MulScalar(const double scalar, const Polynomial poly1, Polynomial *poly);

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
 * @return int
 */
int DivPoly(const Polynomial poly1, const Polynomial poly2, Polynomial *rem, Polynomial *quo);

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

#endif // !POLYNOMIAL_H
