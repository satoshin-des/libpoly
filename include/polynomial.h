#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <stdio.h>
#include <stdlib.h>

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
 * @brief Add two polynomials. poly <- poly1 + poly2
 * 
 * @param poly1 Polynomial to add
 * @param poly2 Polynomial to add
 * @param poly Polynomial to be added
 * @return int EXIT_SUCCESS if something error did not occur, EXIT_FAILURE else
 */
int AddPoly(const Polynomial poly1, const Polynomial poly2, Polynomial *poly);

/**
 * @brief Multiply two polynomials. poly <- poly1 * poly2
 * 
 * @param poly1 Polynomial to multiply
 * @param poly2 Polynomial to multiply
 * @param poly Polynomial to be multiplied
 * @return int EXIT_SUCCESS if something error did not occur, EXIT_FAILURE else
 */
int MulPoly(const Polynomial poly1, const Polynomial poly2, Polynomial *poly);

#endif // !POLYNOMIAL_H
