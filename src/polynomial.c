#include "polynomial.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>

int InitPoly(Polynomial *poly, const long deg)
{
    poly->deg = deg;
    poly->coeff = (double *)malloc((deg + 1) * sizeof(double));
    if(poly->coeff == NULL)
    {
        perror("malloc failed @InitPoly");
        return -1;
    }

    poly->var = 'x';

    return 0;
}

void SetVar(Polynomial *poly, const char var)
{
    poly->var = var;
}

int PrintFmt(const char *format, ...)
{
    int res = 0;
    long i;
    Polynomial poly;
    va_list args;
    va_start(args, format);

    while (*format)
    {
        if ((*format == '%') && (*(format + 1) == 'p'))
        {
            poly = va_arg(args, Polynomial);
            for (i = poly.deg; i >= 0; --i)
            {
                if (i == poly.deg)
                {
                    if (poly.coeff[i] > 0)
                    {
                        res = printf("%lf*x^%ld", poly.coeff[i], i);
                    }
                    else if (poly.coeff[i] < 0)
                    {
                        res = printf("-%lf*x^%ld", poly.coeff[i], i);
                    }
                }
                else if (i == 0)
                {
                    if (poly.coeff[i] > 0)
                    {
                        res = printf("+%lf", poly.coeff[i]);
                    }
                    else if (poly.coeff[i] < 0)
                    {
                        res = printf("-%lf", poly.coeff[i]);
                    }
                }
                else
                {
                    if (poly.coeff[i] > 0)
                    {
                        res = printf("+%lf*x^%ld", poly.coeff[i], i);
                    }
                    else if (poly.coeff[i] < 0)
                    {
                        res = printf("-%lf*x^%ld", poly.coeff[i], i);
                    }
                }

                if (res < 0)
                {
                    perror("printf failed @PrintFmt");
                    return -1;
                }
            }
            format += 2;
        }
        else
        {
            res = putchar(*format);
            if ((res < 0) || (res == EOF))
            {
                perror("putchar failed @PrintFmt");
                return -1;
            }

            ++format;
        }
    }

    va_end(args);

    return 0;
}
