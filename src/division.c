#include "polynomial.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

int MonoDiv(const Polynomial mono1, const Polynomial mono2, Polynomial *mono)
{
    int res;
    if (!IsMono(mono1))
    {
        res = puts("mono1 is not monomial @MonoDiv");
        if (res == EOF)
        {
            perror("puts failed @MonoDiv");
            return EXIT_FAILURE;
        }
        return EXIT_FAILURE;
    }
    else if(!IsMono(mono2))
    {
        res = puts("mono2 is not monomial @MonoDiv");
        if (res == EOF)
        {
            perror("puts failed @MonoDiv");
            return EXIT_FAILURE;
        }
        return EXIT_FAILURE;
    }

    if (IsZero(mono1))
    {
        res = MakePoly(mono, 0);
        mono->coeff[0] = 0;
    }
    else if (IsZero(mono2))
    {
        errno = EPERM;
        perror("divided by zero @MonoDiv");
        return EXIT_FAILURE;
    }
    else
    {
        res = MakeMono(mono, Deg(mono1) - Deg(mono2), (double)mono1.coeff[Deg(mono1)] / mono2.coeff[Deg(mono2)]);
        if (res == EXIT_FAILURE)
        {
            perror("MakePoly failed @MonoDiv");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

int DivPoly(const Polynomial poly1, const Polynomial poly2, Polynomial *rem, Polynomial *quo)
{
    int res;
    Polynomial t1, t2, lt1, lt2;

    InitPoly(&t1);
    InitPoly(&t2);
    InitPoly(&lt1);
    InitPoly(&lt2);

    if (IsZero(poly1))
    {
        res = Copy(poly1, quo);
        if (res == EXIT_FAILURE)
        {
            perror("Copy failed @DivPoly");
            return EXIT_FAILURE;
        }
        res = MakeMono(rem, 0, 0);
        if (res == EXIT_FAILURE)
        {
            perror("MakeMono failed @DivPoly");
            return EXIT_FAILURE;
        }
    }
    else if (IsZero(poly2))
    {
        errno = EPERM;
        perror("divided by zero @DivPoly");
        return EXIT_FAILURE;
    }
    else
    {
        res = Copy(poly1, rem);
        if (res == EXIT_FAILURE)
        {
            perror("Copy failed @DivPoly");
            return EXIT_FAILURE;
        }
        res = MakeMono(quo, 0, 0);
        if (res == EXIT_FAILURE)
        {
            perror("MakeMono failed @DivPoly");
            return EXIT_FAILURE;
        }
        while ((!IsZero(*rem)) && (Deg(*rem) >= Deg(poly2)))
        {
            res = LT(*rem, &lt1);
            if (res == EXIT_FAILURE)
            {
                perror("LT failed @DivPoly");
                return EXIT_FAILURE;
            }
            res = LT(poly2, &lt2);
            if (res == EXIT_FAILURE)
            {
                perror("LT failed @DivPoly");
                return EXIT_FAILURE;
            }
            res = MonoDiv(lt1, lt2, &t1);
            if (res == EXIT_FAILURE)
            {
                perror("MonoDiv failed @DivPoly");
                return EXIT_FAILURE;
            }
            res = AddPoly(*quo, t1, &t2);
            if (res == EXIT_FAILURE)
            {
                perror("AddPoly failed @DivPoly");
                return EXIT_FAILURE;
            }
            res = Copy(t2, quo);
            if (res == EXIT_FAILURE)
            {
                perror("Copy failed @DivPoly");
                return EXIT_FAILURE;
            }
            res = MulPoly(t1, poly2, &t2);
            if (res == EXIT_FAILURE)
            {
                perror("MulPoly failed @DivPoly");
                return EXIT_FAILURE;
            }
            res = SubtrPoly(*rem, t2, &t1);
            if (res == EXIT_FAILURE)
            {
                perror("SubtrPoly failed @DivPoly");
                return EXIT_FAILURE;
            }
            res = Copy(t1, rem);
            if (res == EXIT_FAILURE)
            {
                perror("Copy failed @DivPoly");
                return EXIT_FAILURE;
            }
        }
    }
    return EXIT_SUCCESS;
}
