#include <iostream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

ZZ pow(ZZ base, ZZ exp)
{
    ZZ result;
    result=1;
    while(exp!=0)
    {
        result*=base;
        exp--;
    }
    return result;
}

ZZ modulo(ZZ a, ZZ n)
{
    if(n<0)
    {
        ZZ zero;
        zero=0;
        cout << "n es menor a 0" << endl;
        return zero;
    }
    ZZ q;
    q = a / n;
    ZZ r;
    r = a - (q * n);
    if (r < 0)
    {
        q--;
        r = a - (q * n);
    }
    return r;
}


ZZ pow_base_exp__modulo_mod(ZZ base, ZZ exp, ZZ mod)
{
    ZZ result;
    result=1;
    base=modulo(base,mod);
    ZZ n;
    n=2;
    if(modulo(exp, n)==1)
    {
        result=base;
    }
    exp/=2;
    ZZ elevado;
    while(exp!=0)
    {
        elevado = pow(base, n);
        base = modulo( elevado, mod);
        if(modulo(exp, n)==1)
        {
            result=modulo(result*base,mod);
        }
        exp/=2;
    }
    return result;
}

int main()
{
    ZZ b,e,m,r;
    cin>>b;cin>>e;cin>>m;

    r=pow_base_exp__modulo_mod(b,e,m);
    cout<<r<<endl;
    return 0;
}
