#include "polynomial.h"

int IsMono(const Polynomial poly)
{
    long n_nonzero_term = 0;
    for (long i = 0; i <= poly.deg; ++i)
    {
        if (poly.coeff[i] != 0)
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
        if (poly.coeff[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}
