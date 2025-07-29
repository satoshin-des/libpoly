#include "polynomial.h"

#include <stdio.h>
#include <math.h>

void NormalizeDeg(Polynomial *poly)
{
    while ((poly->deg > 0) && (fabs(poly->coeff[poly->deg]) < EPSILON))
    {
        --poly->deg;
    }
}

void NormalizeCoeff(Polynomial *poly)
{
    NormalizeDeg(poly);
    if (poly->deg == 0)
    {
        poly->coeff[0] = 1.0;
    }
    else
    {
        for (long i = 0; i < poly->deg; ++i)
        {
            poly->coeff[i] /= poly->coeff[poly->deg];
        }
    }
}
