#include "polynomial.h"

#include <math.h>

int IsMono(const Polynomial poly)
{
    long n_nonzero_term = 0;
    for (long i = 0; i <= poly.deg; ++i)
    {
        if (fabs(poly.coeff[i]) > EPSILON)
        {
            ++n_nonzero_term;
        }

        if (n_nonzero_term >= 2)
        {
            return 0;
        }
    }
    return 1;
}

int IsZero(const Polynomial poly)
{
    for (long i = 0; i <= poly.deg; ++i)
    {
        if (fabs(poly.coeff[i]) > EPSILON)
        {
            return 0;
        }
    }
    return 1;
}

int IsMonic(const Polynomial poly)
{
    if (fabs(poly.coeff[Deg(poly)] - 1) < EPSILON)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
