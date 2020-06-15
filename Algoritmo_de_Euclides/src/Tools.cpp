#include "Tools.h"

Tools::Tools()
{
    //ctor
}

ZZ Tools::modulo(ZZ a,ZZ n)
{
    if(n<0)
    {
        cout << "n es menor a 0" << endl;
        return n;
    }
    q = a / n;
    r = a - (q * n);
    if (r < 0)
    {
        q--;
        r = a - (q * n);
    }
    return r;
}

ZZ Tools::modulo(ZZ a,int n)
{
    if(n<0)
    {
        cout << "n es menor a 0" << endl;
        return a;
    }
    q = a / n;
    r = a - (q * n);
    if (r < 0)
    {
        q--;
        r = a - (q * n);
    }
    return r;
}

