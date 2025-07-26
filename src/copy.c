#include "polynomial.h"

int Copy(const Polynomial poly1, Polynomial *poly)
{
    int res;
    res = InitPoly(poly, poly1.deg);
    if (res == EXIT_FAILURE)
    {
        perror("InitPoly failed @Copy");
        return EXIT_FAILURE;
    }

    for (long i = 0; i <= poly1.deg; ++i)
    {
        poly->coeff[i] = poly1.coeff[i];
    }

    return EXIT_SUCCESS;
}
