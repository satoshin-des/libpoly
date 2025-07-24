#include "polynomial.h"

int main()
{
    Polynomial f;

    InitPoly(&f, 3);
    for(long i = 0; i < 4; ++i)
    {
        f.coeff[i] = i + 1;
    }
    PrintFmt("f=%p\n", f);

    return 0;
}
