#include <Vernam.h>

int main()
{
    string clave = "948/nu";
    Vernam emisor(clave);
    string a= emisor.cifrar("Hola");
    cout << emisor.cifrar(a);
    return 0;
}
