#include "polynomial.h"

int main()
{
    Polynomial f, g, h;

    InitPoly(&f, 3);
    InitPoly(&g, 5);
    for (long i = 0; i <= f.deg; ++i)
    {
        f.coeff[i] = i + 1;
    }
    for (long i = 0; i <= g.deg; ++i)
    {
        g.coeff[i] = i + 7;
    }
    AddPoly(f, g, &h);
    PrintFmt("f=%p\n", f);
    PrintFmt("g=%p\n", g);
    PrintFmt("h=%p\n", h);
    MulPoly(f, g, &h);
    PrintFmt("h=%p\n", h);
    MulScalar(10, f, &h);
    PrintFmt("h=%p\n", h);

    ClearPoly(&f);
    ClearPoly(&g);
    ClearPoly(&h);

    return 0;
}
