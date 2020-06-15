#include <iostream>
#include "Tools.h"
#include <NTL/ZZ.h>
#include <ctime>


using namespace std;
using namespace NTL;

Tools h;

ZZ Algoritmo_1(ZZ a, ZZ b, int i)
{
    ZZ *r=new ZZ;
    *r=h.modulo(a,b);

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
    *r=h.modulo(a,b);

    if(*r==0)
    {
        return b;
    }
    if(*r>b/2) // aqui poner bitset
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
    return Algoritmo_3(b,h.modulo(a,b),i);
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
    else if(h.modulo(a,2)==0 && h.modulo(b,2)==0)
    {
        return 2*Algoritmo_4(a/2,b/2,i);// aqui poner bitset
    }
    else if(h.modulo(a,2)==0 && h.modulo(b,2)==1)
    {
        return Algoritmo_4(a/2,b,i);// aqui poner bitset
    }
    else if(h.modulo(a,2)==1 && h.modulo(b,2)==0)
    {
        return Algoritmo_4(a,b/2,i);// aqui poner bitset
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
        return Algoritmo_4((a-b)/2,*y,i);// aqui poner bitset
        delete y;
    }
}

ZZ Algoritmo_5(ZZ  x, ZZ  y, int i)
{
    i++;
    ZZ *g= new ZZ;
    *g=1;
    while(h.modulo(x,2)==0 && h.modulo(y,2)==0)
    {
        i++;
        x=x/2;
        y=y/2;
        (*g)=(*g)*2;
    }
    while(x!=0)
    {
        i++;
        while(h.modulo(x,2)==0)
        {
            x=x/2;
        }
        while(h.modulo(y,2)==0)
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

ZZ Algoritmo_6(ZZ a, ZZ b, int i) //este es muy lento
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
    ZZ r;
    r=h.modulo(a,b);
    while(r!=0)
    {
        r=h.modulo(a,b);
        if(r==0)
        {
            return b;
        }
        if(r > (b>>1))
        {
            r=b-r;
        }

        a=b;
        b=r;
    }
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
    unsigned t0, t1;

    t0=clock();
    cout<<"ALGORITMO 1"<<endl;
    cout<<"-----------"<<endl;
    cout<<"mcd de "<<a<<" y "<<b<<" : "<<Algoritmo_1(a,b,i)<<endl;
    t1 = clock();

    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;

    t0=clock();
    cout<<"\n\nALGORITMO 2"<<endl;
    cout<<"-----------"<<endl;
    cout<<"mcd de "<<a<<" y "<<b<<" : "<<Algoritmo_2(a,b,i)<<endl;
    t1 = clock();

    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;


    t0=clock();
    cout<<"\n\nALGORITMO 3"<<endl;
    cout<<"-----------"<<endl;
    cout<<"mcd de "<<a<<" y "<<b<<" : "<<Algoritmo_3(a,b,i)<<endl;
    t1 = clock();

    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;


    t0=clock();
    cout<<"\n\nALGORITMO 4"<<endl;
    cout<<"-----------"<<endl;
    cout<<"mcd de "<<a<<" y "<<b<<" : "<<Algoritmo_4(a,b,i)<<endl;
    t1 = clock();

    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;


    t0=clock();
    cout<<"\n\nALGORITMO 5"<<endl;
    cout<<"-----------"<<endl;
    cout<<"mcd de "<<a<<" y "<<b<<" : "<<Algoritmo_5(a,b,i)<<endl;
    t1 = clock();

    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;


    t0=clock();
    cout<<"\n\nALGORITMO 7"<<endl;
    cout<<"-----------"<<endl;
    cout<<"mcd de "<<a<<" y "<<b<<" : "<<Algoritmo_Propuesta(a,b)<<endl;
    t1 = clock();

    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;

    t0=clock();
    cout<<"\n\nALGORITMO 6"<<endl;
    cout<<"-----------"<<endl;
    cout<<"mcd de "<<a<<" y "<<b<<" : "<<Algoritmo_6(a,b,i)<<endl;
    t1 = clock();

    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;

}
