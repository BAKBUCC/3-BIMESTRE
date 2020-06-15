#include "RailFence.h"

RailFence::RailFence(int clave)
{
    cl=clave;
}

void RailFence::sube_o_baja(int unsigned &ite_cl,bool &bajar)
{
    if(bajar!=false)
    {
        if((ite_cl+1)==cl)
        {
            bajar=false; //comenzará a subir en la matriz
            ite_cl--;//va a subir en la matriz
        }
        else
        {
            ite_cl++; //va a seguir bajando en la matriz
        }
    }
    else
    {
        if((ite_cl-1)==-1)
        {
            bajar=true;
            ite_cl++;
        }
        else
        {
            ite_cl--;//va a subir en la matriz
        }
    }
}

string RailFence::cifrado(string m)
{
    m_size=m.length();
    str.resize(m_size*cl);
    bajar=true;

    for(ite_m=0, ite_cl=0; ite_m < m_size; ite_m++)
    {
        str.at((m_size*ite_cl)+ite_m) = m.at(ite_m);
        sube_o_baja(ite_cl,bajar);
    }

    return str;
}

string RailFence::descifrado(string m)
{
    m_size=(m.length()/cl);
    str.resize(m_size);
    bajar=true;

    for(ite_m=0, ite_cl=0; ite_m < m_size; ite_m++)
    {
        str.at(ite_m)=m.at((m_size*ite_cl)+ite_m);
        sube_o_baja(ite_cl,bajar);
    }

    return str;
}
