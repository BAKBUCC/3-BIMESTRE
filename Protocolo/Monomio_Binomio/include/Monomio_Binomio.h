#ifndef MONOMIO_BINOMIO_H
#define MONOMIO_BINOMIO_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using std::ostringstream;

class Monomio_Binomio
{
    public:
        Monomio_Binomio(string,int,int,string);
        string Alfabetizado(string);
        string cifrado(string);
        string descifrado(string);

    private:
        string cl_p,Alf;
        ostringstream new_m;
        int unsigned cl_n_1,cl_n_2,i,tamanhio=30,posicion;
        string::iterator j;

};

#endif // MONOMIO_BINOMIO_H
