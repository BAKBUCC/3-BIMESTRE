#include "Afin.h"

Afin::Afin(string abc)
{
	Alfabeto = abc;
    tamanho = Alfabeto.size();
	GenerarClaves();
}

Afin::Afin(string abc, int clave_a, int clave_b)
{
	Alfabeto = abc;
    tamanho = Alfabeto.size();
	inv_a = t.inversa_mult_de_a_en_Zn(tamanho,clave_a);
	b = clave_b;
}

string Afin::Cifrar(string mensaje)
{
    new_Mensaje.resize(mensaje.length());
    j = 0;

    for (i = mensaje.begin(); i != mensaje.end(); i++)
    {
        pos = Alfabeto.find(*i);

        pos *= a;
        pos += b;

        mod = t.modulo(pos,tamanho);

        new_Mensaje[j] = Alfabeto[mod];

        j++;
    }
    return new_Mensaje;
}

string Afin::Descifrar(string mensaje_cifrado)
{
    new_Mensaje.resize(mensaje_cifrado.length());
    j = 0;

    for (i = mensaje_cifrado.begin(); i != mensaje_cifrado.end(); i++)
    {
        pos = Alfabeto.find(*i);

        pos -= b;
        pos *= inv_a;

        mod = t.modulo(pos, tamanho);

        new_Mensaje[j] = Alfabeto[mod];
        j++;
    }
    return new_Mensaje;
}

void Afin::GenerarClaves()
{
    bool correlativos = false;
    do
    {
        a = t.Num_Aleatorio();
        if (t.MCD(a, tamanho) == 1)
        {
            correlativos = true;
        }
    } while (correlativos == false);

    a=t.modulo(a,tamanho);

    b = t.Num_Aleatorio();
    b = t.modulo(b,tamanho);
}
