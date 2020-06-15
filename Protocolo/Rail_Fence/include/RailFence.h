#ifndef RAILFENCE_H
#define RAILFENCE_H

#include <iostream>
#include <string>

using namespace std;


class RailFence
{
    public:
        RailFence(int);
        void sube_o_baja(int unsigned&,bool&);
        string cifrado(string);
        string descifrado(string);
    private:
        string str;
        int unsigned cl, ite_m, ite_cl, m_size;
        bool bajar;
};

#endif // RAILFENCE_H
