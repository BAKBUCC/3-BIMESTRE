#ifndef CESAR_H
#define CESAR_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include<time.h>

using namespace std;

class Cesar
{
    int clave;
    int *resto=new int;
    public:
        Cesar();
        string Codificacion(string);
        string Decodificacion(string);
        virtual ~Cesar();
};

#endif // CESAR_H
