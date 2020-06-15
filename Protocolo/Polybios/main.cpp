#include "Polybios.h"

string alfabeto("abcdefghijklmnopqrstuvwxyz");

int main()
{
    string m("el caballo se mueve en ele");
    string c,d;
    cout<<m<<endl;

    typedef Polybios P;
    P e(alfabeto);

    c=e.cifrado(m);
    cout<<c<<endl;

    P r(alfabeto);

    d=r.descifrado(c);
    cout<<d<<endl;
    return 0;
}
