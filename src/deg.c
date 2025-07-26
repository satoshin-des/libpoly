#include "polynomial.h"

#include <math.h>

int Deg(const Polynomial poly)
{
    for (long i = poly.deg; i >= 0; --i)
    {
        if (fabs(poly.coeff[i]) > EPSILON)
        {
            if ((i == 0) && (fabs(poly.coeff[i]) < EPSILON))
            {
                return -1;
            }
            else
            {
                return i;
            }
        }
    }
}
