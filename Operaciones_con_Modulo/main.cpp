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
        q--;
        r=a-(q*n);
    }
    return r;
}

ZZ suma(ZZ a, ZZ b)
{
    return a+b;
}

ZZ resta(ZZ a, ZZ b)
{
    cout<<a<<" "<<b<<endl;
    return a-b;
}

ZZ multiplicacion(ZZ a, ZZ b)
{
    return a*b;
}
typedef ZZ(*pf)(ZZ,ZZ);
ZZ ejecuta(ZZ a,pf func, ZZ b, ZZ n)
{
    return func( modulo(a,n), modulo(b,n) );
}

ZZ XmodN_op_YmodN_todo_modN(ZZ x, pf funcion, ZZ y, ZZ n)
{
    return modulo(ejecuta(x,funcion,y,n),n);
}

int main()
{
    pf p[3] = {suma,resta,multiplicacion};
    ZZ a,b,n;

    a=1723345,b=2124945, n=11;
    ZZ c;
    for(int i=0; i<3; i++)
    {
        c=XmodN_op_YmodN_todo_modN(a,p[i],b,n);
        cout<<c<<endl;
    }
    return 0;
}
