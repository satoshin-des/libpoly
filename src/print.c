#include "polynomial.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>

int PrintFmt(const char *format, ...)
{
    int res = 0;
    long i;
    int n_int;
    long n_long;
    long long n_long_long;
    float a_float;
    double a_double;
    Polynomial poly;
    va_list args;
    va_start(args, format);

    while (*format)
    {
        if ((*format == '%') && (*(format + 1) == 'p'))
        {
            poly = va_arg(args, Polynomial);
            if (IsZero(poly))
            {
                res = printf("0");
            }
            else if (IsMono(poly))
            {
                if (fabs(poly.coeff[Deg(poly)] - round(poly.coeff[Deg(poly)])) < EPSILON)
                {
                    res = printf("%ld*x^%d", (long)poly.coeff[Deg(poly)], Deg(poly));
                }
                else
                {
                    res = printf("%lf*x^%d", poly.coeff[Deg(poly)], Deg(poly));
                }
            }
            else
            {
                for (i = Deg(poly); i >= 0; --i)
                {
                    if (i == Deg(poly))
                    {
                        if (poly.coeff[i] > 0)
                        {
                            if (fabs(poly.coeff[i] - round(poly.coeff[i])) < EPSILON)
                            {
                                res = printf("%ld*x^%ld", (long)poly.coeff[i], i);
                            }
                            else
                            {
                                res = printf("%lf*x^%ld", poly.coeff[i], i);
                            }
                        }
                        else if (poly.coeff[i] < 0)
                        {
                            if (fabs(poly.coeff[i] - round(poly.coeff[i])) < EPSILON)
                            {
                                res = printf("%ld*x^%ld", (long)poly.coeff[i], i);
                            }
                            else
                            {
                                res = printf("%lf*x^%ld", poly.coeff[i], i);
                            }
                        }
                    }
                    else if (i == 0)
                    {
                        if (poly.coeff[i] > 0)
                        {
                            if (fabs(poly.coeff[i] - round(poly.coeff[i])) < EPSILON)
                            {
                                res = printf("+%ld", (long)poly.coeff[i]);
                            }
                            else
                            {
                                res = printf("+%lf", poly.coeff[i]);
                            }
                        }
                        else if (poly.coeff[i] < 0)
                        {
                            if (fabs(poly.coeff[i] - round(poly.coeff[i])) < EPSILON)
                            {
                                res = printf("%ld", (long)poly.coeff[i]);
                            }
                            else
                            {
                                res = printf("%lf", poly.coeff[i]);
                            }
                        }
                    }
                    else
                    {
                        if (poly.coeff[i] > 0)
                        {
                            if (fabs(poly.coeff[i] - round(poly.coeff[i])) < EPSILON)
                            {
                                res = printf("+%ld*x^%ld", (long)poly.coeff[i], i);
                            }
                            else
                            {
                                res = printf("+%lf*x^%ld", poly.coeff[i], i);
                            }
                        }
                        else if (poly.coeff[i] < 0)
                        {
                            if (fabs(poly.coeff[i] - round(poly.coeff[i])) < EPSILON)
                            {
                                res = printf("%ld*x^%ld", (long)poly.coeff[i], i);
                            }
                            else
                            {
                                res = printf("%lf*x^%ld", poly.coeff[i], i);
                            }
                        }
                    }

                    if (res < 0)
                    {
                        perror("printf failed @PrintFmt");
                        return EXIT_FAILURE;
                    }
                }
            }
            format += 2;
        }
        else if ((*format == '%') && (*(format + 1) == 'd'))
        {
            n_int = va_arg(args, int);
            res = printf("%d", n_int);
            if (res < 0)
            {
                perror("printf failed @PrintFmt");
                return EXIT_FAILURE;
            }
            format += 2;
        }
        else if ((*format == '%') && (*(format + 1) == 'l') && (*(format + 2) == 'd'))
        {
            n_long = va_arg(args, long);
            res = printf("%ld", n_long);
            if (res < 0)
            {
                perror("printf failed @PrintFmt");
                return EXIT_FAILURE;
            }
            format += 3;
        }
        else if ((*format == '%') && (*(format + 1) == 'l') && (*(format + 2) == 'l') && (*(format + 3) == 'd'))
        {
            n_long_long = va_arg(args, long long);
            res = printf("%lld", n_long_long);
            if (res < 0)
            {
                perror("printf failed @PrintFmt");
                return EXIT_FAILURE;
            }
            format += 4;
        }
        else if ((*format == '%') && (*(format + 1) == 'f'))
        {
            a_float = va_arg(args, double);
            res = printf("%f", a_float);
            if (res < 0)
            {
                perror("printf failed @PrintFmt");
                return EXIT_FAILURE;
            }
            format += 2;
        }
        else if ((*format == '%') && (*(format + 1) == 'l') && (*(format + 2) == 'f'))
        {
            a_double = va_arg(args, double);
            res = printf("%lf", a_double);
            if (res < 0)
            {
                perror("printf failed @PrintFmt");
                return EXIT_FAILURE;
            }
            format += 3;
        }
        else
        {
            res = putchar(*format);
            if ((res < 0) || (res == EOF))
            {
                perror("putchar failed @PrintFmt");
                return EXIT_FAILURE;
            }

            ++format;
        }
    }

    va_end(args);

    return EXIT_SUCCESS;
}
