#include "polynomial.h"

int MakePoly(Polynomial *poly, const long deg)
{
    poly->deg = deg;
    if (deg < 0)
    {
        poly->coeff = NULL;
    }
    else
    {
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
    }

    poly->var = 'x';

    return EXIT_SUCCESS;
}
