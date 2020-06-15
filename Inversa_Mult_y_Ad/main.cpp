#include <iostream>
#include "Tools.h"

using namespace std;

int mcd(int a, int b, Tools h)
{
    cout<<a<<" = "<<a/b<<"("<<b<<")";
    int *r=new int;
    *r=h.modulo(a,b);
    cout<<" + "<<*r<<endl;

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
    return mcd(a,b,h);
}

void Inversas_Add(int conjuntoZ)
{
    Tools h;
    for(int i=1; i<conjuntoZ; i++)
    {
        for(int j=1; j<conjuntoZ; j++)
        {
            if (h.modulo(i+j,conjuntoZ)==0)
            {
                cout<<"("<<i<<"+"<<j<<") mod "<<conjuntoZ<<"= 0\n";
            }
        }
    }
}

void Inversas_Mult(int conjuntoZ)
{
    Tools h;
    for(int i=0; i<conjuntoZ; i++)
    {
        for(int j=0; j<conjuntoZ; j++)
        {
            if (h.modulo(i*j,conjuntoZ)==1)
            {
                cout<<"{"<<i<<","<<j<<"}\n";
            }
        }
    }
}


int main()
{
    string alf="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout<<alf.find("P")<<endl;


//    int Z,a,b;
//    cout<<"Z: ";
//    cin>>Z;
//    cout<<"Inv_ADD: \n";
//    Inversas_Add(Z);
//    cout<<"\n\nInv_MULT: \n";
//    Inversas_Mult(Z);
//    cout<<"a: ";
//    cin>>a;
//    cout<<"\nb: ";
//    cin>>b;
//    cout<<"\n\nMCD("<<a<<" , "<<b<<")\n";
//    Tools h;
//    cout<<"mcd: "<<mcd(a,b,h)<<endl;
}
