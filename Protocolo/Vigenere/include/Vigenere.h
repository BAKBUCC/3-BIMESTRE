#ifndef VIGENERE_H
#define VIGENERE_H
#include <iostream>
#include <string>

using namespace std;


class Vigenere
{
    public:
        string m,c,d;
        int unsigned i,l,posm,posc;
        int suma,resta,mod,total;
        bool mensaje, haciendo;
        string alfabeto_Num = "abcdefghijklmnopqrstuvwxyz -ABCDEFGHIJKLMNOPQRSTUVWXYZ,.0123456789";
        string alfabeto="«ьйвдаезклипомƒ≈…ж∆фцтыщЃ÷№ш£Ў„Г !\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_"
                        "`abcdefghijklmnopqrstuvwxyz{|}~";
        Vigenere(string);
        string codificacion_con_alfNum();
        string decodificacion_con_alfNum();

        string codificacion_con_alfASCII();
        string decodificacion_con_alfASCII();

        string codificacion_con_alfHEX();
        string decodificacion_con_alfHEX();

        string codificacion_Codigo_Mensaje();
        string decodificacion_Codigo_Mensaje();

    private:

        //string clave="Javier Arturo Quinte Sanchez 161-10-37659";
        string clave="Rony Rodrigo Sicos Barrera 191-10-46034";
        string str_decodificado;
};

#endif // VIGENERE_H
