#ifndef VIGENERE_H
#define VIGENERE_H
#include <iostream>
#include <string>

using namespace std;


class Vigenere
{
    public:
        string m,c,d;
        int unsigned i,l;
        int suma,resta,mod;
        bool mensaje, haciendo;
        string alfabeto_Num = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
        Vigenere(string);
        string codificacion_con_alfNum();
        string decodificacion_con_alfNum();
        string codificacion_con_alfASCII();
        string decodificacion_con_alfASCII();
        string codificacion_Codigo_Mensaje();
        string decodificacion_Codigo_Mensaje();

    protected:

    private:

        string clave="Pablo Neruda";
        string str_decodificado;
};

#endif // VIGENERE_H
