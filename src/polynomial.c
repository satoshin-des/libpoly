#include "polynomial.h"

#include <stdio.h>

int InitPoly(Polynomial *poly)
{
    poly->deg = 0;
    poly->coeff = NULL;
}

void FreePoly(Polynomial *poly)
{
    poly->deg = -1;
    if (poly->coeff != NULL)
    {
        free(poly->coeff);
        poly->coeff = NULL;
    }
    poly->var = 0;
}
