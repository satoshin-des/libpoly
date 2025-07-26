#include "polynomial.h"

int InitMono(Polynomial *poly, const long deg, const double coeff)
{
    int res;
    res = InitPoly(poly, deg);
    if (res == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }

    poly->coeff[deg] = coeff;

    return EXIT_SUCCESS;
}
