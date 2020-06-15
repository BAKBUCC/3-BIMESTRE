#ifndef POLYBIOS_H
#define POLYBIOS_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using std::ostringstream;

class Polybios
{
    public:
        Polybios(string);
        string Alfabetizado(string);
        string cifrado(string);
        string descifrado(string);
        int modulo(int, int);

    private:
        string Alf;
        ostringstream new_m;
        int unsigned i,tamanhio=25,posicion;
        string::iterator j;
};

#endif // POLYBIOS_H
