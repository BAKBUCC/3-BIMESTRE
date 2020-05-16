#include "Vigenere.h"

Vigenere::Vigenere(string clave, string abc)
{
    cl=clave;
    alf=abc;
    total = alf.length();
}

string Vigenere::codificacion_con_alfPuesto(string mensaje)
{
    nuevoMensaje.resize( mensaje.length());
    for(i = mensaje.begin(),l = cl.begin(), j=0; i!=mensaje.end(); i++,l++,j++)
    {
        if (l!=cl.end())
        {
            l=cl.begin();
        }
        suma = alf.find(*i) + alf.find (*l);

        mod = h.modulo(suma,total);

        nuevoMensaje[j]=alf[mod];
    }
    return nuevoMensaje;
}
string Vigenere::decodificacion_con_alfPuesto(string mensaje)
{
    nuevoMensaje.resize( mensaje.length());
    for(i = mensaje.begin(),l = cl.begin(), j=0; i!=mensaje.end(); i++,l++,j++)
    {
        if (l!=cl.end())
        {
            l=cl.begin();
        }

        resta = alf.find(*i) - alf.find(*l);

        mod = h.modulo(resta,total);

        nuevoMensaje[j]=alf[mod];
    }
    return nuevoMensaje;
}

string Vigenere::codificacion_con_alfHEX(string mensaje)
{
    nuevoMensaje.resize( mensaje.length());
    for(i = mensaje.begin(),l = cl.begin(), j=0; i!=mensaje.end(); i++,l++,j++)
    {
        if (l!=cl.end())
        {
            l=cl.begin();
        }
        cout<<showbase<<hex;

        suma = alf.find(*i) + alf.find(*l);

        mod = h.modulo(suma,total);

        nuevoMensaje[j] = alf[mod];

        cout<<showbase<<dec;
    }
    return nuevoMensaje;
}
string Vigenere::decodificacion_con_alfHEX(string mensaje)
{
    nuevoMensaje.resize( mensaje.length());
    for(i = mensaje.begin(),l = cl.begin(), j=0; i!=mensaje.end(); i++,l++,j++)
    {
        if (l!=cl.end())
        {
            l=cl.begin();
        }

        cout<<showbase<<hex;

        resta = alf.find(*i) - alf.find(*l);

        mod = h.modulo(resta,total);

        nuevoMensaje[j] = alf[mod];

        cout<<showbase<<dec;
    }
    return nuevoMensaje;
}

string Vigenere::codificacion_Codigo_y_luego_Mensaje(string mensaje)
{
    nuevoMensaje.resize( mensaje.length());
    activo_m = false;

    for(i = mensaje.begin(),l = cl.begin(), j=0; i!=mensaje.end(); i++,l++,j++)
    {
        if(activo_m==true)
        {
            suma = alf.find(*i) + alf.find(*l);
        }
        else
        {
            if (l==cl.end())
            {
                activo_m=true;
                l=mensaje.begin();
                l--;
                i--;
                j--;
            }
            else
            {
                suma = alf.find(*i)+alf.find(*l);
            }
        }

        mod=h.modulo(suma,total);

        nuevoMensaje[j] = alf[mod];
    }
    return nuevoMensaje;
}

string Vigenere::decodificacion_Codigo_y_luego_Mensaje(string mensaje)
{
    nuevoMensaje.resize( mensaje.length());
    for(i = mensaje.begin(),l = cl.begin(), j=0; l<cl.end(); i++,l++,j++)
    {
        resta = alf.find(*i) - alf.find(*l);

        mod = h.modulo(resta,total);

        nuevoMensaje[j]=alf[mod];
    }

    l=nuevoMensaje.begin();

    while( i < mensaje.end() )
    {
        for( int unsigned m=0; m<cl.length() && i!=mensaje.end() ; i++,l++,j++,m++)
        {
            resta = alf.find(*i) - alf.find(*l);

            mod = h.modulo(resta,total);

            nuevoMensaje[j]=alf[mod];
        }
    }
    return nuevoMensaje;
}
