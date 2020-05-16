#include "Herramientas.h"

Herramientas::Herramientas()
{
    //ctor
}

int Herramientas::modulo(int a,int n)
{
    if(n<=0)//solo puede ser positivo
    {
        return 0;
    }

    q=a/n;

    r = a-(n*q);

    if(r<0)
    {
        r = a-(n*(q-1));//con esto noo permitimos que el residuo sea 0
    }

    return r;
}
