#include "polynomial.h"

int main()
{
    Polynomial f, g, h;
    Polynomial m, n;

    InitPoly(&f, 3);
    InitPoly(&g, 5);
    InitMono(&m, 10, 5);
    InitMono(&n, 4, 2);
    for (long i = 0; i <= f.deg; ++i)
    {
        f.coeff[i] = i + 1;
    }
    for (long i = 0; i <= g.deg; ++i)
    {
        g.coeff[i] = i + 7;
    }
    // sum
    AddPoly(f, g, &h);
    PrintFmt("f=%p\n", f);
    PrintFmt("g=%p\n", g);
    PrintFmt("h=%p\n", h);

    // diff
    SubtrPoly(f, g, &h);
    PrintFmt("f+g=%p\n", h);

    // prod
    MulPoly(f, g, &h);
    PrintFmt("f+g=%p\n", h);

    // scalar prod
    MulScalar(10, f, &h);
    PrintFmt("f+g=%p\n", h);

    // div
    DivPoly(g, f, &h, &n);
    PrintFmt("g=f*(%p)+%p\n", n, h);

    // cos
    MaclaurinExp(COS_FUNC, 10, &h);
    PrintFmt("cos = %p\n", h);

    ClearPoly(&f);
    ClearPoly(&g);
    ClearPoly(&h);

    return 0;
}
