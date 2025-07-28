#include "polynomial.h"

#include <stdio.h>
#include <stdlib.h>

int MakeMono(Polynomial *poly, const long deg, const double coeff)
{
    int res;
    res = MakePoly(poly, deg);
    if (res == EXIT_FAILURE)
    {
        perror("MakePoly failed @MakeMono");
        return EXIT_FAILURE;
    }
    poly->coeff[deg] = coeff;
    for(long i = 0; i < deg; ++i)
    {
        poly->coeff[i] = 0;
    }

    return EXIT_SUCCESS;
}
