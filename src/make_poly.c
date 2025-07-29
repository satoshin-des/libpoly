#include "polynomial.h"

#include <stdio.h>
#include <errno.h>

int MakePoly(Polynomial *poly, const long deg)
{
    if (poly == NULL)
    {
        errno = EPERM;
        perror("MakePoly error :NULL polynomial passed");
        return EXIT_FAILURE;
    }

    poly->deg = deg;
    if (poly->coeff != NULL)
    {
        free(poly->coeff);
        poly->coeff = NULL;
    }
    poly->coeff = (double *)malloc((deg + 1) * sizeof(double));
    if (poly->coeff == NULL)
    {
        perror("malloc failed @MakePoly");
        return EXIT_FAILURE;
    }
    for (long i = 0; i <= deg; ++i)
    {
        poly->coeff[i] = 0.0;
    }

    poly->var = 'x';

    return EXIT_SUCCESS;
}
