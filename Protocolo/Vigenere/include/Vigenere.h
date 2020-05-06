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
        string alfabeto="ÇüéâäàåçêëèïîìÄÅÉæÆôöòûù®ÖÜø£Ø×ƒ !\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_"
                        "`abcdefghijklmnopqrstuvwxyz{|}~";
        string posHex[127]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F",
                        "10","11","12","13","14","15","16","17","18","19","1A","1B","1C","1D","1E","1F",
                        "20","21","22","23","24","25","26","27","28","29","2A","2B","2C","2D","2E","2F",
                        "30","31","32","33","34","35","36","37","38","39","3A","3B","3C","3D","3E","3F",
                        "40","41","42","43","44","45","46","47","48","49","4A","4B","4C","4D","4E","4F",
                        "50","51","52","53","54","55","56","57","58","59","5A","5B","5C","5D","5E","5F",
                        "60","61","62","63","64","65","66","67","68","69","6A","6B","6C","6D","6E","6F",
                        "70","71","72","73","74","75","76","77","78","79","7A","7B","7C","7D","7E"};
        int find_Pos_Hex(string);

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
