#include "polynomial.h"

#include <stdio.h>
#include <stdlib.h>

int MulPoly(const Polynomial poly1, const Polynomial poly2, Polynomial *poly)
{
    long i, j, k;
    int res;

    res = MakePoly(poly, poly1.deg + poly2.deg);
    if (res == EXIT_FAILURE)
    {
        perror("MakePoly failed @MulPoly");
        return EXIT_FAILURE;
    }

    if (Deg(poly1) == 0)
    {
        res = MulScalar(poly1.coeff[0], poly2, poly);
        if(res == EXIT_FAILURE)
        {
            return EXIT_FAILURE;
        }
    }
    else if (Deg(poly2) == 0)
    {
        res = MulScalar(poly2.coeff[0], poly1, poly);
        if(res == EXIT_FAILURE)
        {
            return EXIT_FAILURE;
        }
    }
    else
    {
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
    }

    return EXIT_SUCCESS;
}

int MulScalar(const double scalar, const Polynomial poly1, Polynomial *poly)
{
    int res;
    res = MakePoly(poly, poly1.deg);
    if (res == EXIT_FAILURE)
    {
        perror("MakePoly failed @MulScalar");
        return EXIT_FAILURE;
    }

    for (long i = 0; i <= poly->deg; ++i)
    {
        poly->coeff[i] = scalar * poly1.coeff[i];
    }

    return EXIT_SUCCESS;
}

int Minus(const Polynomial poly1, Polynomial *poly)
{
    int res;
    res = MakePoly(poly, poly1.deg);
    if (res == EXIT_FAILURE)
    {
        perror("MakePoly failed @Minus");
        return EXIT_FAILURE;
    }

    for (long i = 0; i <= poly->deg; ++i)
    {
        poly->coeff[i] = -poly1.coeff[i];
    }

    return EXIT_SUCCESS;
}
