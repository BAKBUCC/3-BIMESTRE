#include <iostream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

ZZ mod(ZZ a, ZZ b)
{
    ZZ q,r;
    q = a/b;
    if(a>=0)
    {
        r = a-(b*q);
    }
    else
    {
        r = (a-(b*q))-b;
    }
    return r;
}

void divisibilidad(ZZ a, ZZ b)
{
    cout<<"\n\n";
    if(a>=0)
    {
        cout<<a<<" = "<<b<<"("<<a/b<<") + "<<mod(a,b)<<endl;
    }
    else
    {
        cout<<a<<" = "<<b<<"("<<(a/b)+1<<") + "<<mod(a,b)<<endl;
    }
}

int main()
{
    ZZ a,b;
    cout<<"a: ";
    cin>>a;
    cout<<"\nb: ";
    cin>>b;
    divisibilidad(a,b);
    return 0;
}
