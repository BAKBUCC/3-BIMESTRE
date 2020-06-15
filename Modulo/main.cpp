#include <iostream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

ZZ modulo(ZZ a, ZZ n)
{
    ZZ q=a/n;
    ZZ r=a-(q*n);
    if(r<0)
    {
        q++;
        r=a-(q*n);
    }
    return r;
}

int main()
{
    ZZ a,n;
    a=1723345,n=11;
    cout<<modulo(a,n)<<endl;
    return 0;
}
