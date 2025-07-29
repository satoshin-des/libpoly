#include "polynomial.h"

int GCD(const Polynomial poly1, const Polynomial poly2, Polynomial *d)
{
    int res;
    if (IsZero(poly2))
    {
        res = Copy(poly1, d);
        if (res == EXIT_FAILURE)
        {
            return EXIT_FAILURE;
        }
    }
    else
    {
        Polynomial r, q;
        InitPoly(&r);
        InitPoly(&q);
        res = DivPoly(poly1, poly2, &r, &q);
        FreePoly(&q);
        if (res == EXIT_FAILURE)
        {
            FreePoly(&r);
            return EXIT_FAILURE;
        }
        res = GCD(poly2, r, d);
        if (res == EXIT_FAILURE)
        {
            FreePoly(&r);
            return EXIT_FAILURE;
        }
        FreePoly(&r);
    }
    NormalizeCoeff(d);
    return EXIT_SUCCESS;
}
