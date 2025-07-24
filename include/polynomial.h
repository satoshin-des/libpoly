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
    char val;
} Polynomial;

/**
 * @brief Initialization of polynomial
 *
 * @param poly Polynomial
 * @param deg Degree of polynomial
 * @return int 0 if something error did not occur, -1 else
 */
int InitPoly(Polynomial *poly, const long deg);

/**
 * @brief Print
 * 
 * @param format 
 * @param ... 
 * @return int 0 if something error did not occur, -1 else
 */
int PrintFmt(const char *format, ...);

#endif // !POLYNOMIAL_H
