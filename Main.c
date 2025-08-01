#include "polynomial.h"

#include <complex.h>

int main()
{
    Polynomial f, g, h;
    Polynomial m, n;

    InitPoly(&f);
    InitPoly(&g);
    InitPoly(&h);
    InitPoly(&m);
    InitPoly(&n);

    MakePoly(&f, 2);
    MakePoly(&g, 3);
    MakeMono(&m, 10, 5);
    MakeMono(&n, 4, 2);
    f.coeff[0] = 1;
    f.coeff[1] = 2 * I;
    f.coeff[2] = -1;
    g.coeff[0] = 1;
    g.coeff[1] = 3 * I;
    g.coeff[2] = -3;
    g.coeff[3] = -I;

    // sum
    AddPoly(f, g, &h);
    PrintFmt("f=%p\n", f);
    PrintFmt("g=%p\n", g);
    PrintFmt("h=%p\n", h);

    // diff
    SubtrPoly(f, g, &h);
    PrintFmt("f-g=%p\n", h);

    // scalar prod
    MulScalar(10, f, &h);
    PrintFmt("10f=%p\n", h);

    // prod
    MulPoly(f, g, &h);
    PrintFmt("f*g=%p\n", h);

    GCD(f, g, &h);
    PrintFmt("GCD(f, g) = %p\n", h);

    // div
    DivPoly(g, f, &h, &n);
    PrintFmt("g=f*(%p)+%p\n", n, h);

    // cos
    MaclaurinExp(COS_FUNC, 10, &h);
    PrintFmt("cos = %p\n", h);

    PrintFmt("cos(pi) = %lf\n", Substitute(h, 3.1415926535897932384626433832));

    FFT(2, I, g, &h);
    PrintFmt("FFT(g) = %p\n", h);

    FreePoly(&f);
    FreePoly(&g);
    FreePoly(&h);
    FreePoly(&m);
    FreePoly(&n);

    return 0;
}
