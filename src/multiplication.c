#include "polynomial.h"

#include <stdint.h>

int MulPoly(const Polynomial poly1, const Polynomial poly2, Polynomial *poly)
{
    long i, j, k;
    int res;
    res = InitPoly(poly, poly1.deg + poly2.deg);
    if (res == EXIT_FAILURE)
    {
        perror("InitPoly failed @MulPoly");
        return EXIT_FAILURE;
    }

    for (i = 0; i <= poly->deg; ++i)
    {
        for (j = 0; j <= poly1.deg; ++j)
        {
            for (k = 0; k <= poly2.deg; ++k)
            {
                if (j + k == i)
                {
                    poly->coeff[i] += poly1.coeff[j] * poly2.coeff[k];
                    break;
                }
            }
        }
    }

    return EXIT_SUCCESS;
}

int MulScalar(const double scalar, const Polynomial poly1, Polynomial *poly)
{
    int res;
    res = InitPoly(poly, poly1.deg);
    if (res == EXIT_FAILURE)
    {
        perror("InitPoly failed @MulScalar");
        return EXIT_FAILURE;
    }

    for (long i = 0; i <= poly->deg; ++i)
    {
        poly->coeff[i] = scalar * poly1.coeff[i];
    }

    return EXIT_SUCCESS;
}
