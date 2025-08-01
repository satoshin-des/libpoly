#include "polynomial.h"

#include <stdio.h>
#include <math.h>
#include <complex.h>

double complex Substitute(const Polynomial poly, const double complex a)
{
    double complex ans = 0.0;
    for (long i = 0; i <= poly.deg; ++i)
    {
        if (fabs(poly.coeff[i]) > EPSILON)
        {
            ans += poly.coeff[i] * pow(a, i);
        }
    }
    return ans;
}
