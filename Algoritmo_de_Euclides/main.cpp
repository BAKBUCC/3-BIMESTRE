#include <iostream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;


ZZ Algoritmo_1(ZZ a, ZZ b, int i)
{
    ZZ *r=new ZZ;
    *r=a%b;

    if(*r==0)
    {
        return b;
    }
    else
    {
        a=b;
        b=*r;
    }
    delete r;
    i++;
    return Algoritmo_1(a,b,i);
}

ZZ Algoritmo_2(ZZ a, ZZ b, int i)
{

    ZZ *r=new ZZ;
    *r=a%b;

    if(*r==0)
    {
        return b;
    }
    if(*r>b/2)
    {
        *r=b-*r;
    }

    a=b;
    b=*r;
    i++;
    delete r;
    return Algoritmo_2(a,b,i);
}

ZZ Algoritmo_3(ZZ  a, ZZ  b, int i)
{
    if (b==0)
    {
        return a;
    }
    i++;
    return Algoritmo_3(b,a%b,i);
}

ZZ Algoritmo_4(ZZ  a, ZZ  b, int i)
{
    if(a<0)
    {
        a=-a;
    }
    if(b<0)
    {
        b=-b;
    }
    if(b>a)
    {
        return Algoritmo_4(b,a,i);
    }
    else if(b==0)
    {
        return a;
    }
    else if(a%2==0 && b%2==0)
    {
        return 2*Algoritmo_4(a/2,b/2,i);
    }
    else if(a%2==0 && b%2==1)
    {
        return Algoritmo_4(a/2,b,i);
    }
    else if(a%2==1 && b%2==0)
    {
        return Algoritmo_4(a,b/2,i);
    }
    else
    {
        ZZ *y=new ZZ;
        *y=b;
        if(a<0)
        {
            a=-a;
        }
        if(b<0)
        {
            b=-b;
        }
        return Algoritmo_4((a-b)/2,*y,i);
        delete y;
    }
}

ZZ Algoritmo_5(ZZ  x, ZZ  y, int i)
{
    i++;
    ZZ *g= new ZZ;
    *g=1;
    while(x%2==0 && y%2==0)
    {
        i++;
        x=x/2;
        y=y/2;
        (*g)=(*g)*2;
    }
    while(x!=0)
    {
        i++;
        while(x%2==0)
        {
            x=x/2;
        }
        while(y%2==0)
        {
            y=y/2;
        }

        ZZ *t=new ZZ;
        if(x<y)
        {
            (*t)=(-(x-y))/2;
        }
        else
        {
            (*t)=(x-y)/2;
        }

        if(x>=y)
        {
            x=(*t);
        }
        else
        {
            y=(*t);
        }
        delete t;
    }
    return ((*g)* y);
    delete g;
}

ZZ Algoritmo_6(ZZ a, ZZ b, int i)
{
    while(a!=b)
    {
        i++;
        if(a>b)
        {
            a=a-b;
        }
        else
        {
            b=b-a;
        }
        i++;
    }
    return a;
}

ZZ Algoritmo_Propuesta(ZZ a, ZZ b)
{
    ZZ n;
    n=2;
    ZZ mcd;
    mcd=1;
    while(n<a && n<b)
    {
        if(a%n==0 && b%n==0)
        {
            mcd*=n;
            a/=n;
            b/=n;
        }
        else
        {
            n++;
        }
    }
    return mcd;
}

int main()
{
    ZZ a;
    cin>>a;
    //a=412;
    ZZ b;
    cin>>b;
    //b=260;
    int i=0;
    cout<<"ALGORITMO 1"<<endl;
    cout<<"-----------"<<endl;
    cout<<"mcd de "<<a<<" y "<<b<<" : "<<Algoritmo_1(a,b,i)<<endl;
    cout<<"\n\nALGORITMO 2"<<endl;
    cout<<"-----------"<<endl;
    cout<<"mcd de "<<a<<" y "<<b<<" : "<<Algoritmo_2(a,b,i)<<endl;
    cout<<"\n\nALGORITMO 3"<<endl;
    cout<<"-----------"<<endl;
    cout<<"mcd de "<<a<<" y "<<b<<" : "<<Algoritmo_3(a,b,i)<<endl;
    cout<<"\n\nALGORITMO 4"<<endl;
    cout<<"-----------"<<endl;
    cout<<"mcd de "<<a<<" y "<<b<<" : "<<Algoritmo_4(a,b,i)<<endl;
    cout<<"\n\nALGORITMO 5"<<endl;
    cout<<"-----------"<<endl;
    cout<<"mcd de "<<a<<" y "<<b<<" : "<<Algoritmo_5(a,b,i)<<endl;
    cout<<"\n\nALGORITMO 6"<<endl;
    cout<<"-----------"<<endl;
    cout<<"mcd de "<<a<<" y "<<b<<" : "<<Algoritmo_6(a,b,i)<<endl;
    cout<<"\n\nALGORITMO 7"<<endl;
    cout<<"-----------"<<endl;
    cout<<"mcd de "<<a<<" y "<<b<<" : "<<Algoritmo_Propuesta(a,b)<<endl;
}
