#include "polynomial.h"

int Deg(const Polynomial poly)
{
    for (long i = poly.deg; i >= 0; --i)
    {
        if (poly.coeff[i] != 0)
        {
            if ((i == 0) && (poly.coeff[i] == 0))
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
