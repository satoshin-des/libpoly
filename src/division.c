#include "polynomial.h"

#include <math.h>

int MonoDiv(const Polynomial mono1, const Polynomial mono2, Polynomial *mono)
{
    int res;
    if ((!IsMono(mono1)) || (!IsMono(mono2)))
    {
        res = puts("mono1 or mono2 are not monomial @MonoDiv");
        if (res == EOF)
        {
            perror("puts failed @MonoDiv");
            return EXIT_FAILURE;
        }
        return EXIT_FAILURE;
    }

    if (IsZero(mono1))
    {
        res = InitPoly(mono, 0);
        mono->coeff[0] = 0;
    }
    else if (IsZero(mono2))
    {
        perror("divided by zero @MonoDiv");
        return EXIT_FAILURE;
    }
    else
    {
        res = InitMono(mono, Deg(mono1) - Deg(mono2), (double)mono1.coeff[Deg(mono1)] / mono2.coeff[Deg(mono2)]);
        if (res == EXIT_FAILURE)
        {
            perror("InitPoly failed @MonoDiv");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

int DivPoly(const Polynomial poly1, const Polynomial poly2, Polynomial *rem, Polynomial *quo)
{
    int res;
    const long max_deg = fmax(poly1.deg, poly2.deg);
    Polynomial t1, t2, lt1, lt2;
    if (IsZero(poly1))
    {
        res = Copy(poly1, quo);
        if (res == EXIT_FAILURE)
        {
            perror("Copy failed @DivPoly");
            return EXIT_FAILURE;
        }
        res = InitMono(rem, 0, 0);
        if (res == EXIT_FAILURE)
        {
            perror("InitMono failed @DivPoly");
            return EXIT_FAILURE;
        }
    }
    else if (IsZero(poly2))
    {
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
        res = InitMono(quo, 0, 0);
        if (res == EXIT_FAILURE)
        {
            perror("InitMono failed @DivPoly");
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
            if(res == EXIT_FAILURE)
            {
                perror("Copy failed @DivPoly");
                return EXIT_FAILURE;
            }
        }
    }
    return EXIT_SUCCESS;
}
