#include "polynomial.h"

#include <stdio.h>
#include <stdlib.h>

int SubtrPoly(const Polynomial poly1, const Polynomial poly2, Polynomial *poly)
{
    int res;
    if (poly1.deg > poly2.deg)
    {
        res = MakePoly(poly, poly1.deg);
        if (res == EXIT_FAILURE)
        {
            perror("MakePoly failed @SubtrPoly");
            return EXIT_FAILURE;
        }
    }
    else
    {
        res = MakePoly(poly, poly2.deg);
        if (res == EXIT_FAILURE)
        {
            perror("MakePoly failed @SubtrPoly");
            return EXIT_FAILURE;
        }
    }

    for (long i = 0; i <= poly->deg; ++i)
    {
        if ((i <= poly1.deg) && (i <= poly2.deg))
        {
            poly->coeff[i] = poly1.coeff[i] - poly2.coeff[i];
        }
        else if ((i > poly1.deg) && (i <= poly2.deg))
        {
            poly->coeff[i] = -poly2.coeff[i];
        }
        else if ((i <= poly1.deg) && (i > poly2.deg))
        {
            poly->coeff[i] = poly1.coeff[i];
        }
    }

    return EXIT_SUCCESS;
}
