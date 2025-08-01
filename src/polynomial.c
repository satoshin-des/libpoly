#include "polynomial.h"

#include <stdio.h>

int InitPoly(Polynomial *poly)
{
    if (poly == NULL)
    {
        return EXIT_FAILURE;
    }

    poly->deg = -1;
    poly->coeff = NULL;
    poly->var = 0;

    return EXIT_SUCCESS;
}

void FreePoly(Polynomial *poly)
{
    if (poly == NULL)
    {
        return;
    }

    poly->deg = -1;
    if (poly->coeff != NULL)
    {
        free(poly->coeff);
        poly->coeff = NULL;
    }
    poly->var = 0;
}
