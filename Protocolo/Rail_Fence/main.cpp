#include "RailFence.h"


int main()
{
    int clave=3;
    string m,c,d;

    getline(cin,m);

    typedef RailFence Rf;

    Rf e(clave);
    c=e.cifrado(m);
    cout<<"\""<<c<<"\""<<endl;

    Rf r(clave);
    d=r.descifrado(c);
    cout<<"\""<<d<<"\""<<endl;

    return 0;
}
