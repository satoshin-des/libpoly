#include "polynomial.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int Copy(const Polynomial poly1, Polynomial *poly)
{
    int res;
    if (poly == NULL)
    {
        errno = EPERM;
        perror("Copy error: polynomial to output is NULL");
        return EXIT_FAILURE;
    }

    if ((poly1.deg < 0) || (poly1.coeff == NULL))
    {
        res = MakePoly(poly, 0);
        if (res == EXIT_FAILURE)
        {
            errno = EPERM;
            perror("Copy error: input polynomial is NULL");
            return EXIT_FAILURE;
        }
    }
    res = MakePoly(poly, poly1.deg);
    if (res == EXIT_FAILURE)
    {
        perror("MakePoly failed @Copy");
        return EXIT_FAILURE;
    }
    for (long i = 0; i <= poly1.deg; ++i)
    {
        poly->coeff[i] = poly1.coeff[i];
    }
    poly->var = poly1.var;

    return EXIT_SUCCESS;
}
