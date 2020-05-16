#ifndef CESAR_H
#define CESAR_H

#include <iostream>
#include "Tools.h"

class Cesar
{
    int pos, mod, j, total,cl;
    string nuevoMensaje;
    Tools h;

    public:
        Cesar(int,string);
        string alf;
        string Codificacion_Alf(string);
        string Decodificacion_Alf(string);
};

#endif // CESAR_H
