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
    res = MakeMono(lt, Deg(poly), poly.coeff[Deg(poly)]);
    if (res == EXIT_FAILURE)
    {
        perror("MakeMono failed @LT");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
