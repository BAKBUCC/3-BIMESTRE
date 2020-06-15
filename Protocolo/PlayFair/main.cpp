#include "PlayFair.h"

string alfabetoMayus("abcdefghijklmnopqrstuvwxyz");

int main()
{
    string clave_cadena("playfair example");
    string c,d;
    string m("Hide the gold in the tree stump");
    cout<<m<<endl;

    typedef PlayFair PF;
    PF e(clave_cadena,alfabetoMayus);

//    c=e.cifrado(m);
//    cout<<c<<endl;
//
//    PF r(clave_cadena,alfabetoMayus);
//
//    d=r.descifrado(c);
//    cout<<d<<endl;
    return 0;
}
