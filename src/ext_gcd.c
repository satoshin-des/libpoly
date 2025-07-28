#include "polynomial.h"

int ExtGCD(const Polynomial poly1, const Polynomial poly2, Polynomial *d, Polynomial *a, Polynomial *b)
{
    long i;
    int res;
    Polynomial r0, r1, s0, s1, t0, t1, tmp, q;

    res = Copy(poly1, &r0);
    if (res == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }
    res = Copy(poly2, &r1);
    if (res == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }
    res = MakeMono(&s0, 0, 1);
    if (res == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }
    res = MakeMono(&s1, 0, 0);
    if (res == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }
    res = MakeMono(&t0, 0, 0);
    if (res == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }
    res = MakeMono(&t1, 0, 1);
    if (res == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }

    for (i = 1; !IsZero(r1); ++i)
    {
        res = DivPoly(r0, r1, &tmp, &q);
        if (res == EXIT_FAILURE)
        {
            return EXIT_FAILURE;
        }
        res = MulPoly(q, r1, &tmp);
        if (res == EXIT_FAILURE)
        {
            return EXIT_FAILURE;
        }
        res = SubtrPoly(r0, tmp, &r1);
        if (res == EXIT_FAILURE)
        {
            return EXIT_FAILURE;
        }
        res = MulPoly(q, s1, &tmp);
        if (res == EXIT_FAILURE)
        {
            return EXIT_FAILURE;
        }
        res = SubtrPoly(s0, tmp, &s1);
        if (res == EXIT_FAILURE)
        {
            return EXIT_FAILURE;
        }
        res = MulPoly(q, t1, &tmp);
        if (res == EXIT_FAILURE)
        {
            return EXIT_FAILURE;
        }
        res = SubtrPoly(t0, tmp, &t1);
        if (res == EXIT_FAILURE)
        {
            return EXIT_FAILURE;
        }
    }
    res = Copy(r0, d);
    if (res == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }
    if ((i & 1) == 0)
    {
        res = Minus(t1, a);
        if (res == EXIT_FAILURE)
        {
            return EXIT_FAILURE;
        }
        res = Copy(s1, b);
        if (res == EXIT_FAILURE)
        {
            return EXIT_FAILURE;
        }
    }
    else
    {
        res = Copy(t1, a);
        if (res == EXIT_FAILURE)
        {
            return EXIT_FAILURE;
        }
        res = Minus(s1, b);
        if (res == EXIT_FAILURE)
        {
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
