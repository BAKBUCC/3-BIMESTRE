#ifndef CESAR_H
#define CESAR_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include<time.h>

using namespace std;

class Cesar
{
    int resto, pos, mod, j, total;
    string c, d, str;

    public:
        Cesar(string);
        string Codificacion();
        string Decodificacion();
        string alfabeto_Num = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
        string Codificacion_Alf();
        string Decodificacion_Alf();

    private:
        int clave=3;
};

#endif // CESAR_H
