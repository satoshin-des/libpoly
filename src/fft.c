#include "polynomial.h"

#include <stdio.h>
#include <math.h>
#include <complex.h>

int FFT(const long n, const double complex omega, const Polynomial a, Polynomial *alpha)
{
    int res;
    if (n == 0)
    {
        // InitPoly(alpha);
        res = MakePoly(alpha, 0);
        if (res == EXIT_FAILURE)
        {
            perror("MakePoly failed @FFT");
            return EXIT_FAILURE;
        }
        alpha->coeff[0] = a.coeff[0];
    }
    else
    {
        const long t = pow(2, n - 1);
        const double complex omega_sq = omega * omega;
        double complex omega_i = 1.0, tmp;
        Polynomial beta, gamma, a_even, a_odd;

        res = MakePoly(alpha, t + t);
        if(res == EXIT_FAILURE)
        {
            return EXIT_FAILURE;
        }

        res = InitPoly(&beta);
        if (res == EXIT_FAILURE)
        {
            perror("InitPoly failed @FFT");
            return EXIT_FAILURE;
        }
        res = InitPoly(&gamma);
        if (res == EXIT_FAILURE)
        {
            perror("InitPoly failed @FFT");
            return EXIT_FAILURE;
        }
        res = MakePoly(&beta, t);
        if (res == EXIT_FAILURE)
        {
            perror("MakePoly failed @FFT");
            return EXIT_FAILURE;
        }
        res = MakePoly(&gamma, t);
        if (res == EXIT_FAILURE)
        {
            perror("MakePoly failed @FFT");
            return EXIT_FAILURE;
        }

        res = InitPoly(&a_even);
        if (res == EXIT_FAILURE)
        {
            perror("InitPoly failed @FFT");
            return EXIT_FAILURE;
        }
        res = InitPoly(&a_odd);
        if (res == EXIT_FAILURE)
        {
            perror("InitPoly failed @FFT");
            return EXIT_FAILURE;
        }
        res = MakePoly(&a_even, t);
        if (res == EXIT_FAILURE)
        {
            perror("MakePoly failed @FFT");
            return EXIT_FAILURE;
        }
        res = MakePoly(&a_odd, t);
        if (res == EXIT_FAILURE)
        {
            perror("MakePoly failed @FFT");
            return EXIT_FAILURE;
        }

        for (long i = 0; i <= t; ++i)
        {
            a_even.coeff[i] = a.coeff[i << 1];
            a_odd.coeff[i] = a.coeff[(i << 1) + 1];
        }

        res = FFT(n - 1, omega_sq, a_even, &beta);
        if (res == EXIT_FAILURE)
        {
            perror("FFT failed @FFT");
            return EXIT_FAILURE;
        }
        res = FFT(n - 1, omega_sq, a_odd, &gamma);
        if (res == EXIT_FAILURE)
        {
            perror("FFT failed @FFT");
            return EXIT_FAILURE;
        }

        FreePoly(&a_even);
        FreePoly(&a_odd);

        for (long i = 0; i < t; ++i)
        {
            tmp = omega_i * gamma.coeff[i];
            alpha->coeff[i] = beta.coeff[i] + tmp;
            alpha->coeff[i + t] = beta.coeff[i] - tmp;
        }

        FreePoly(&beta);
        FreePoly(&gamma);
    }

    return EXIT_SUCCESS;
}
