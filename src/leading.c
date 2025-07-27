#include "polynomial.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double LC(const Polynomial poly)
{
    for (long i = poly.deg; i >= 0; --i)
    {
        if (poly.coeff[i] != 0)
        {
            return poly.coeff[i];
        }
    }

    return 0;
}

int LT(const Polynomial poly, Polynomial *lt)
{
    int res;

    for (long i = poly.deg; i >= 0; --i)
    {
        if (fabs(poly.coeff[i]) > EPSILON)
        {
            res = InitPoly(lt, i);
            if (res == EXIT_FAILURE)
            {
                perror("InitPoly failed @LT");
                return EXIT_FAILURE;
            }
            lt->coeff[i] = poly.coeff[i];
            return EXIT_SUCCESS;
        }
    }

    return EXIT_FAILURE;
}
