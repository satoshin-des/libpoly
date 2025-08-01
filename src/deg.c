#include "polynomial.h"

#include <stdio.h>
#include <math.h>
#include <complex.h>

int Deg(const Polynomial poly)
{
    if (poly.coeff == NULL)
    {
        return -1;
    }
    else if (poly.deg == 0)
    {
        return 0;
    }
    else
    {
        for (long i = poly.deg; i >= 0; --i)
        {
            if (cabs(poly.coeff[i]) > EPSILON)
            {
                return i;
            }
        }
    }

    // If all coefficients are zero, then returns 0
    return 0;
}
