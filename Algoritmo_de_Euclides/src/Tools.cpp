#include "Tools.h"

Tools::Tools()
{
    //ctor
}

ZZ Tools::modulo(ZZ a,ZZ n)
{
    if(n>0)
    {
        q=a/n;

        r = a-(n*q);

        if(r<0)
        {
            r = a-(n*(q-1));//con esto noo permitimos que el residuo sea 0
        }

        return r;
    }
}

ZZ Tools::modulo(ZZ a,int n)
{
    if(n>0)//solo puede ser positivo
    {
        q=a/n;

        r = a-(n*q);

        if(r<0)
        {
            r = a-(n*(q-1));//con esto noo permitimos que el residuo sea 0
        }

        return r;
    }
}

