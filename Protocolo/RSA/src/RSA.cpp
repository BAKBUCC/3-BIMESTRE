#include "RSA.h"

RSA::RSA(string ABC, ZZ n, ZZ clave_e)//emisor
{
    Alf=ABC;
    N=n;
    e=clave_e;
}

RSA::RSA(string ABC)//recetor
{
    Alf=ABC;
    Generar_claves();
}

string RSA::cifrar(string m)
{
    return new_m;
}

string RSA::descifrar(string m)
{
    return new_m;
}

void RSA::Generar_claves()
{
    long long num, x;
    num = 1000000000000000000;
    t.Generar_num_Primos_hasta_n_en_vector_v(num, primos);
    do
    {
        x=t.Num_Aleatorio(num/2);
        p=primos[x];
        x=t.Num_Aleatorio(num/2);
        q=primos[x];
        cout<<p<<" "<<q<<endl;
    }while(p>10000 && q>10000);
    N=p*q;
    phiN=(p-1)*(q-1);
}
