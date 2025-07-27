#include "polynomial.h"

int MaclaurinExp(const int func_name, const long deg, Polynomial *poly)
{
    int res;
    res = InitPoly(poly, deg);
    if (res == EXIT_FAILURE)
    {
        perror("InitPoly failed @MaclaurinExp");
        return EXIT_FAILURE;
    }

    double t;

    switch (func_name)
    {
    case SIN_FUNC:
        t = 1.0;
        for (long i = 1; i <= deg; i += 2)
        {
            if (i == 1)
            {
                t = 1.0;
            }
            else
            {
                t *= 1.0 / ((i - 1) * i);
            }

            if (((((i - 1) >> 1) & 1)) == 0)
            {
                poly->coeff[i] = t;
            }
            else
            {
                poly->coeff[i] = -t;
            }
        }
        break;

    case COS_FUNC:
        t = 1.0;
        for (long i = 0; i <= deg; i += 2)
        {
            if (i == 0)
            {
                t = 1.0;
            }
            else
            {
                t *= 1.0 / ((i - 1) * i);
            }

            if ((((i >> 1) & 1)) == 0)
            {
                poly->coeff[i] = t;
            }
            else
            {
                poly->coeff[i] = -t;
            }
        }
        break;

    default:
        perror("Undefined function was to be maclaurin-expanded");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
