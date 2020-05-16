#include "Cesar.h"


Cesar::Cesar(int clave, string abc)
{
    cl=clave;
    alf=abc;
    total=alf.length();
}

string Cesar::Codificacion_Alf(string mensaje)
{
    nuevoMensaje.resize( mensaje.length());
    j=0;

    for(string::const_iterator i = mensaje.begin(); i!=mensaje.end(); i++)
    {
        pos = alf.find(*i);

        pos += cl;

        mod = h.modulo(pos,total);

        nuevoMensaje[j]=alf[mod];

        j++;
    }
    return nuevoMensaje;
}

string Cesar::Decodificacion_Alf(string mensaje_cifrado)
{
    nuevoMensaje.resize( mensaje_cifrado.length());
    j=0;

    for(string::const_iterator i = mensaje_cifrado.begin(); i != mensaje_cifrado.end(); i++)
    {
        pos = alf.find(*i);

        pos -= cl;

        mod = h.modulo(pos,total);
        cout<<mod<<endl;

        nuevoMensaje[j] = alf[mod];
        j++;
    }
    return nuevoMensaje;
}
