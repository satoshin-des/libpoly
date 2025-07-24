#include "polynomial.h"

int main()
{
    Polynomial f, g;

    InitPoly(&f, 3);
    for(long i = 0; i < 4; ++i)
    {
        f.coeff[i] = i + 1;
    }
    AddPoly(f, f, &g);
    PrintFmt("f=%p\n", f);
    PrintFmt("g=%p\n", g);

    return 0;
}
