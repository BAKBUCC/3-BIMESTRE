#ifndef CESAR_H
#define CESAR_H

#include <iostream>
#include <string>

using namespace std;

class Cesar
{
    string *str=new string;
    int *clave=new int;
    int *resto=new int;
    public:
        Cesar(string&, int&);
        void Codificacion();
        void Decodificacion();
        virtual ~Cesar();
};

#endif // CESAR_H
