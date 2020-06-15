#ifndef RSA_H
#define RSA_H

#include <iostream>
#include <string>
#include "Tools.h"

using namespace std;
using namespace NTL;

class RSA
{
    public:
        RSA(string ABC,ZZ n,ZZ clave_e);
        RSA(string ABC);
        string Alf;
        string cifrar(string);
        string descifrar(string);
        string new_m;
    private:
        Tools t;
        void Generar_claves();
        ZZ p, q, N, phiN, e, d;
        Vec<ZZ> primos;
};

#endif // RSA_H
