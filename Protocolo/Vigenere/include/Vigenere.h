#ifndef VIGENERE_H
#define VIGENERE_H

#include <iostream>
#include <string>
#include "Tools.h"

using namespace std;


class Vigenere
{
    public:
        Tools h;
        string nuevoMensaje,alf;
        int unsigned posm,posc,j;
        string::iterator i,l;
        int suma,resta,mod,total;
        bool activo_m;

        Vigenere(string,string);
        string codificacion_con_alfPuesto(string);
        string decodificacion_con_alfPuesto(string);

        string codificacion_con_alfHEX(string);
        string decodificacion_con_alfHEX(string);

        string codificacion_Codigo_y_luego_Mensaje(string);
        string decodificacion_Codigo_y_luego_Mensaje(string);

    private:
        string cl;
};

#endif // VIGENERE_H
