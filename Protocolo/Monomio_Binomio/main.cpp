#include "Monomio_Binomio.h"

string alfabetoMayus("ABCDEFGHIJKLMNÑOPQRSTUVWXYZ.");

int main()
{
    int clave_num_1=2,clave_num_2=7;
    string clave_cadena("DENARIOS");
    string c,d;
    string m("ESTE ES UN MENSAJE CIFRADO");
    cout<<m<<endl;

    typedef Monomio_Binomio MB;
    MB e(clave_cadena,clave_num_1,clave_num_2,alfabetoMayus);

    c=e.cifrado(m);
    cout<<c<<endl;

    MB r(clave_cadena,clave_num_1,clave_num_2,alfabetoMayus);

    d=r.descifrado(c);
    cout<<d<<endl;
    return 0;
}
