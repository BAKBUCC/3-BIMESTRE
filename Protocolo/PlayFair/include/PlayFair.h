#ifndef PLAYFAIR_H
#define PLAYFAIR_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using std::ostringstream;

class PlayFair
{
    public:
        PlayFair(string,string);
        string Alfabetizado(string);
        void Mensajeado(string&);
        bool same_fila(string::iterator);
        bool same_colum(string::iterator);
        string cifrado(string);
        string descifrado(string);

    private:
        string cl_p,Alf;
        ostringstream new_m;
        int unsigned i,tamanhio=25,posicion;
        bool misma_fila, misma_colum;
        string::iterator j;
};

#endif // PLAYFAIR_H
