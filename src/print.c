#include "polynomial.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>

int PrintPoly(const Polynomial poly)
{
    int res;
    if (IsZero(poly))
    {
        res = printf("0");
    }
    else if (IsMono(poly))
    {
        // Case of real number
        if (fabs(cimag(poly.coeff[Deg(poly)])) < EPSILON)
        {
            // Case of that real part is integer
            if (fabs(creal(poly.coeff[Deg(poly)]) - round(creal(poly.coeff[Deg(poly)]))) < EPSILON)
            {
                res = printf("%ld*x^%d", (long)creal(poly.coeff[Deg(poly)]), Deg(poly));
            }
            // Case of that real part is not integer
            else
            {
                res = printf("%lf*x^%d", creal(poly.coeff[Deg(poly)]), Deg(poly));
            }
        }
        // Case of pure imaginary number
        else if (fabs(creal(poly.coeff[Deg(poly)])) < EPSILON)
        {
            // Case of that imaginary part is integer
            if (fabs(cimag(poly.coeff[Deg(poly)]) - round(cimag(poly.coeff[Deg(poly)]))) < EPSILON)
            {
                res = printf("%ldi*x^%d", (long)cimag(poly.coeff[Deg(poly)]), Deg(poly));
            }
            // Case of that imaginary part is not integer
            else
            {
                res = printf("%lfi*x^%d", cimag(poly.coeff[Deg(poly)]), Deg(poly));
            }
        }
        else
        {
            // Case of that real part is integer
            if (fabs(creal(poly.coeff[Deg(poly)]) - round(creal(poly.coeff[Deg(poly)]))) < EPSILON)
            {
                // Case of that imaginary part is integer
                if (fabs(cimag(poly.coeff[Deg(poly)]) - round(cimag(poly.coeff[Deg(poly)]))) < EPSILON)
                {
                    if (cimag(poly.coeff[Deg(poly)]) < 0)
                    {
                        res = printf("(%ld%ldi)*x^%d", (long)creal(poly.coeff[Deg(poly)]), (long)cimag(poly.coeff[Deg(poly)]), Deg(poly));
                    }
                    else
                    {
                        res = printf("(%ld+%ldi)*x^%d", (long)creal(poly.coeff[Deg(poly)]), (long)cimag(poly.coeff[Deg(poly)]), Deg(poly));
                    }
                }
                // Case of that imaginary part is not integer
                else
                {
                    if (cimag(poly.coeff[Deg(poly)]) < 0)
                    {
                        res = printf("(%ld%lfi)*x^%d", (long)creal(poly.coeff[Deg(poly)]), cimag(poly.coeff[Deg(poly)]), Deg(poly));
                    }
                    else
                    {
                        res = printf("(%ld+%lfi)*x^%d", (long)creal(poly.coeff[Deg(poly)]), cimag(poly.coeff[Deg(poly)]), Deg(poly));
                    }
                }
            }
            // Case of that real part is not integer
            else
            {
                // Case of that imaginary part is integer
                if (fabs(cimag(poly.coeff[Deg(poly)]) - round(cimag(poly.coeff[Deg(poly)]))) < EPSILON)
                {
                    if (cimag(poly.coeff[Deg(poly)]) < 0)
                    {
                        res = printf("(%lf%ldi)*x^%d", creal(poly.coeff[Deg(poly)]), (long)cimag(poly.coeff[Deg(poly)]), Deg(poly));
                    }
                    else
                    {
                        res = printf("(%lf+%ldi)*x^%d", creal(poly.coeff[Deg(poly)]), (long)cimag(poly.coeff[Deg(poly)]), Deg(poly));
                    }
                }
                // Case of that imaginary part is not integer
                else
                {
                    if (cimag(poly.coeff[Deg(poly)]) < 0)
                    {
                        res = printf("(%lf%lfi)*x^%d", creal(poly.coeff[Deg(poly)]), cimag(poly.coeff[Deg(poly)]), Deg(poly));
                    }
                    else
                    {
                        res = printf("(%lf+%lfi)*x^%d", creal(poly.coeff[Deg(poly)]), cimag(poly.coeff[Deg(poly)]), Deg(poly));
                    }
                }
            }
        }
    }
    else
    {
        for (long i = Deg(poly); i >= 0; --i)
        {
            if (i == Deg(poly))
            {
                // Case of real number
                if (fabs(cimag(poly.coeff[i])) < EPSILON)
                {
                    // Case of that real part is integer
                    if (fabs(creal(poly.coeff[i]) - round(creal(poly.coeff[i]))) < EPSILON)
                    {
                        res = printf("%ld*x^%ld", (long)creal(poly.coeff[i]), i);
                    }
                    // Case of that real part is not integer
                    else
                    {
                        res = printf("%lf*x^%ld", creal(poly.coeff[i]), i);
                    }
                }
                // Case of pure imaginary number
                else if (fabs(creal(poly.coeff[i])) < EPSILON)
                {
                    // Case of that imaginary part is integer
                    if (fabs(cimag(poly.coeff[i]) - round(cimag(poly.coeff[i]))) < EPSILON)
                    {
                        res = printf("%ldi*x^%ld", (long)cimag(poly.coeff[i]), i);
                    }
                    // Case of that imaginary part is not integer
                    else
                    {
                        res = printf("%lfi*x^%ld", cimag(poly.coeff[i]), i);
                    }
                }
                else
                {
                    // Case of that real part is integer
                    if (fabs(creal(poly.coeff[i]) - round(creal(poly.coeff[i]))) < EPSILON)
                    {
                        // Case of that imaginary part is integer
                        if (fabs(cimag(poly.coeff[i]) - round(cimag(poly.coeff[i]))) < EPSILON)
                        {
                            if (cimag(poly.coeff[i]) < 0)
                            {
                                res = printf("(%ld%ldi)*x^%ld", (long)creal(poly.coeff[i]), (long)cimag(poly.coeff[i]), i);
                            }
                            else
                            {
                                res = printf("(%ld+%ldi)*x^%ld", (long)creal(poly.coeff[i]), (long)cimag(poly.coeff[i]), i);
                            }
                        }
                        // Case of that imaginary part is not integer
                        else
                        {
                            if (cimag(poly.coeff[i]) < 0)
                            {
                                res = printf("(%ld%lfi)*x^%ld", (long)creal(poly.coeff[i]), cimag(poly.coeff[i]), i);
                            }
                            else
                            {
                                res = printf("(%ld+%lfi)*x^%ld", (long)creal(poly.coeff[i]), cimag(poly.coeff[i]), i);
                            }
                        }
                    }
                    // Case of that real part is not integer
                    else
                    {
                        // Case of that imaginary part is integer
                        if (fabs(cimag(poly.coeff[i]) - round(cimag(poly.coeff[i]))) < EPSILON)
                        {
                            if (cimag(poly.coeff[i]) < 0)
                            {
                                res = printf("(%lf%ldi)*x^%ld", creal(poly.coeff[i]), (long)cimag(poly.coeff[i]), i);
                            }
                            else
                            {
                                res = printf("(%lf+%ldi)*x^%ld", creal(poly.coeff[i]), (long)cimag(poly.coeff[i]), i);
                            }
                        }
                        // Case of that imaginary part is not integer
                        else
                        {
                            if (cimag(poly.coeff[i]) < 0)
                            {
                                res = printf("(%lf%lfi)*x^%ld", creal(poly.coeff[i]), cimag(poly.coeff[i]), i);
                            }
                            else
                            {
                                res = printf("(%lf+%lfi)*x^%ld", creal(poly.coeff[i]), cimag(poly.coeff[i]), i);
                            }
                        }
                    }
                }
            }
            else if (i == 0)
            {
                // Case of real number
                if (fabs(cimag(poly.coeff[i])) < EPSILON)
                {
                    // Case of that real part is integer
                    if (fabs(creal(poly.coeff[i]) - round(creal(poly.coeff[i]))) < EPSILON)
                    {
                        if (creal(poly.coeff[i]) > 0)
                        {
                            res = printf("+%ld", (long)creal(poly.coeff[i]));
                        }
                        else if (creal(poly.coeff[i]) < 0)
                        {
                            res = printf("%ld", (long)creal(poly.coeff[i]));
                        }
                    }
                    // Case of that real part is not integer
                    else
                    {
                        if (creal(poly.coeff[i]) > 0)
                        {
                            res = printf("+%lf", creal(poly.coeff[i]));
                        }
                        else if (creal(poly.coeff[i]) < 0)
                        {
                            res = printf("%ld", (long)creal(poly.coeff[i]));
                        }
                    }
                }
                // Case of pure imaginary number
                else if (fabs(creal(poly.coeff[i])) < EPSILON)
                {
                    // Case of that imaginary part is integer
                    if (fabs(cimag(poly.coeff[i]) - round(cimag(poly.coeff[i]))) < EPSILON)
                    {
                        if (cimag(poly.coeff[i]) > 0)
                        {
                            res = printf("+%ldi", (long)cimag(poly.coeff[i]));
                        }
                        else
                        {
                            res = printf("%ldi", (long)cimag(poly.coeff[i]));
                        }
                    }
                    // Case of that imaginary part is not integer
                    else
                    {
                        if (cimag(poly.coeff[i]) > 0)
                        {
                            res = printf("+%lfi", cimag(poly.coeff[i]));
                        }
                        else
                        {
                            res = printf("%lfi", cimag(poly.coeff[i]));
                        }
                    }
                }
                else
                {
                    // Case of that real part is integer
                    if (fabs(creal(poly.coeff[i]) - round(creal(poly.coeff[i]))) < EPSILON)
                    {
                        // Case of that imaginary part is integer
                        if (fabs(cimag(poly.coeff[i]) - round(cimag(poly.coeff[i]))) < EPSILON)
                        {
                            if (cimag(poly.coeff[i]) < 0)
                            {
                                res = printf("+(%ld%ldi)", (long)creal(poly.coeff[i]), (long)cimag(poly.coeff[i]));
                            }
                            else
                            {
                                res = printf("+(%ld+%ldi)", (long)creal(poly.coeff[i]), (long)cimag(poly.coeff[i]));
                            }
                        }
                        // Case of that imaginary part is not integer
                        else
                        {
                            if (cimag(poly.coeff[i]) < 0)
                            {
                                res = printf("+(%ld%lfi)", (long)creal(poly.coeff[i]), cimag(poly.coeff[i]));
                            }
                            else
                            {
                                res = printf("+(%ld+%lfi)", (long)creal(poly.coeff[i]), cimag(poly.coeff[i]));
                            }
                        }
                    }
                    // Case of that real part is not integer
                    else
                    {
                        // Case of that imaginary part is integer
                        if (fabs(cimag(poly.coeff[i]) - round(cimag(poly.coeff[i]))) < EPSILON)
                        {
                            if (cimag(poly.coeff[i]) < 0)
                            {
                                res = printf("+(%lf%ldi)", creal(poly.coeff[i]), (long)cimag(poly.coeff[i]));
                            }
                            else
                            {
                                res = printf("+(%lf+%ldi)", creal(poly.coeff[i]), (long)cimag(poly.coeff[i]));
                            }
                        }
                        // Case of that imaginary part is not integer
                        else
                        {
                            if (cimag(poly.coeff[i]) < 0)
                            {
                                res = printf("+(%lf%lfi)", creal(poly.coeff[i]), cimag(poly.coeff[i]));
                            }
                            else
                            {
                                res = printf("+(%lf+%lfi)", creal(poly.coeff[i]), cimag(poly.coeff[i]));
                            }
                        }
                    }
                }
            }
            else if (i == 1)
            {
                // Case of real number
                if (fabs(cimag(poly.coeff[i])) < EPSILON)
                {
                    // Case of that real part is integer
                    if (fabs(creal(poly.coeff[i]) - round(creal(poly.coeff[i]))) < EPSILON)
                    {
                        if (creal(poly.coeff[i]) > 0)
                        {
                            res = printf("+%ld*x", (long)creal(poly.coeff[i]));
                        }
                        else if (creal(poly.coeff[i]) < 0)
                        {
                            res = printf("%ld*x", (long)creal(poly.coeff[i]));
                        }
                    }
                    // Case of that real part is not integer
                    else
                    {
                        if (creal(poly.coeff[i]) > 0)
                        {
                            res = printf("+%lf*x", creal(poly.coeff[i]));
                        }
                        else if (creal(poly.coeff[i]) < 0)
                        {
                            res = printf("%ld*x", (long)creal(poly.coeff[i]));
                        }
                    }
                }
                // Case of pure imaginary number
                else if (fabs(creal(poly.coeff[i])) < EPSILON)
                {
                    // Case of that imaginary part is integer
                    if (fabs(cimag(poly.coeff[i]) - round(cimag(poly.coeff[i]))) < EPSILON)
                    {
                        if (cimag(poly.coeff[i]) > 0)
                        {
                            res = printf("+%ldi*x", (long)cimag(poly.coeff[i]));
                        }
                        else
                        {
                            res = printf("%ldi*x", (long)cimag(poly.coeff[i]));
                        }
                    }
                    // Case of that imaginary part is not integer
                    else
                    {
                        if (cimag(poly.coeff[i]) > 0)
                        {
                            res = printf("+%lfi*x", cimag(poly.coeff[i]));
                        }
                        else
                        {
                            res = printf("%lfi*x", cimag(poly.coeff[i]));
                        }
                    }
                }
                else
                {
                    // Case of that real part is integer
                    if (fabs(creal(poly.coeff[i]) - round(creal(poly.coeff[i]))) < EPSILON)
                    {
                        // Case of that imaginary part is integer
                        if (fabs(cimag(poly.coeff[i]) - round(cimag(poly.coeff[i]))) < EPSILON)
                        {
                            if (cimag(poly.coeff[i]) < 0)
                            {
                                res = printf("+(%ld%ldi)*x", (long)creal(poly.coeff[i]), (long)cimag(poly.coeff[i]));
                            }
                            else
                            {
                                res = printf("+(%ld+%ldi)*x", (long)creal(poly.coeff[i]), (long)cimag(poly.coeff[i]));
                            }
                        }
                        // Case of that imaginary part is not integer
                        else
                        {
                            if (cimag(poly.coeff[i]) < 0)
                            {
                                res = printf("+(%ld%lfi)*x", (long)creal(poly.coeff[i]), cimag(poly.coeff[i]));
                            }
                            else
                            {
                                res = printf("+(%ld+%lfi)*x", (long)creal(poly.coeff[i]), cimag(poly.coeff[i]));
                            }
                        }
                    }
                    // Case of that real part is not integer
                    else
                    {
                        // Case of that imaginary part is integer
                        if (fabs(cimag(poly.coeff[i]) - round(cimag(poly.coeff[i]))) < EPSILON)
                        {
                            if (cimag(poly.coeff[i]) < 0)
                            {
                                res = printf("+(%lf%ldi)*x", creal(poly.coeff[i]), (long)cimag(poly.coeff[i]));
                            }
                            else
                            {
                                res = printf("+(%lf+%ldi)*x", creal(poly.coeff[i]), (long)cimag(poly.coeff[i]));
                            }
                        }
                        // Case of that imaginary part is not integer
                        else
                        {
                            if (cimag(poly.coeff[i]) < 0)
                            {
                                res = printf("+(%lf%lfi)*x", creal(poly.coeff[i]), cimag(poly.coeff[i]));
                            }
                            else
                            {
                                res = printf("+(%lf+%lfi)*x", creal(poly.coeff[i]), cimag(poly.coeff[i]));
                            }
                        }
                    }
                }
            }
            else
            {
                // Case of real number
                if (fabs(cimag(poly.coeff[i])) < EPSILON)
                {
                    // Case of that real part is integer
                    if (fabs(creal(poly.coeff[i]) - round(creal(poly.coeff[i]))) < EPSILON)
                    {
                        if (creal(poly.coeff[i]) > 0)
                        {
                            res = printf("+%ld*x^%ld", (long)creal(poly.coeff[i]), i);
                        }
                        else if (creal(poly.coeff[i]) < 0)
                        {
                            res = printf("%ld*x^%ld", (long)creal(poly.coeff[i]), i);
                        }
                    }
                    // Case of that real part is not integer
                    else
                    {
                        if (creal(poly.coeff[i]) > 0)
                        {
                            res = printf("+%lf*x^%ld", creal(poly.coeff[i]), i);
                        }
                        else if (creal(poly.coeff[i]) < 0)
                        {
                            res = printf("%ld*x^%ld", (long)creal(poly.coeff[i]), i);
                        }
                    }
                }
                // Case of pure imaginary number
                else if (fabs(creal(poly.coeff[i])) < EPSILON)
                {
                    // Case of that imaginary part is integer
                    if (fabs(cimag(poly.coeff[i]) - round(cimag(poly.coeff[i]))) < EPSILON)
                    {
                        if (cimag(poly.coeff[i]) > 0)
                        {
                            res = printf("+%ldi*x^%ld", (long)cimag(poly.coeff[i]), i);
                        }
                        else
                        {
                            res = printf("%ldi*x^%ld", (long)cimag(poly.coeff[i]), i);
                        }
                    }
                    // Case of that imaginary part is not integer
                    else
                    {
                        if (cimag(poly.coeff[i]) > 0)
                        {
                            res = printf("+%lfi*x^%ld", cimag(poly.coeff[i]), i);
                        }
                        else
                        {
                            res = printf("%lfi*x^%ld", cimag(poly.coeff[i]), i);
                        }
                    }
                }
                else
                {
                    // Case of that real part is integer
                    if (fabs(creal(poly.coeff[i]) - round(creal(poly.coeff[i]))) < EPSILON)
                    {
                        // Case of that imaginary part is integer
                        if (fabs(cimag(poly.coeff[i]) - round(cimag(poly.coeff[i]))) < EPSILON)
                        {
                            if (cimag(poly.coeff[i]) < 0)
                            {
                                res = printf("+(%ld%ldi)*x^%ld", (long)creal(poly.coeff[i]), (long)cimag(poly.coeff[i]), i);
                            }
                            else
                            {
                                res = printf("+(%ld+%ldi)*x^%ld", (long)creal(poly.coeff[i]), (long)cimag(poly.coeff[i]), i);
                            }
                        }
                        // Case of that imaginary part is not integer
                        else
                        {
                            if (cimag(poly.coeff[i]) < 0)
                            {
                                res = printf("+(%ld%lfi)*x^%ld", (long)creal(poly.coeff[i]), cimag(poly.coeff[i]), i);
                            }
                            else
                            {
                                res = printf("+(%ld+%lfi)*x^%ld", (long)creal(poly.coeff[i]), cimag(poly.coeff[i]), i);
                            }
                        }
                    }
                    // Case of that real part is not integer
                    else
                    {
                        // Case of that imaginary part is integer
                        if (fabs(cimag(poly.coeff[i]) - round(cimag(poly.coeff[i]))) < EPSILON)
                        {
                            if (cimag(poly.coeff[i]) < 0)
                            {
                                res = printf("+(%lf%ldi)*x^%ld", creal(poly.coeff[i]), (long)cimag(poly.coeff[i]), i);
                            }
                            else
                            {
                                res = printf("+(%lf+%ldi)*x^%ld", creal(poly.coeff[i]), (long)cimag(poly.coeff[i]), i);
                            }
                        }
                        // Case of that imaginary part is not integer
                        else
                        {
                            if (cimag(poly.coeff[i]) < 0)
                            {
                                res = printf("+(%lf%lfi)*x^%ld", creal(poly.coeff[i]), cimag(poly.coeff[i]), i);
                            }
                            else
                            {
                                res = printf("+(%lf+%lfi)*x^%ld", creal(poly.coeff[i]), cimag(poly.coeff[i]), i);
                            }
                        }
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
    return EXIT_SUCCESS;
}

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
            res = PrintPoly(poly);
            if (res == EXIT_FAILURE)
            {
                perror("PrintPoly failed @PrintFmt");
                return EXIT_FAILURE;
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
