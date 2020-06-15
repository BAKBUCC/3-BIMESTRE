#include "Monomio_Binomio.h"

Monomio_Binomio::Monomio_Binomio(string clave_palabra, int clave_num_1, int clave_num_2, string abc)
{
    cl_p=clave_palabra;
    cl_n_1=clave_num_1;
    cl_n_2=clave_num_2;
    Alf=Alfabetizado(abc);
}

string Monomio_Binomio::Alfabetizado(string abc)
{
    bool palabra_fin=false;
    Alf.resize(tamanhio);
    for(i=0,j=cl_p.begin(); i<tamanhio; j++)
    {
        if (cl_n_1==i || cl_n_2==i)
        {
            i++;
        }

        if(palabra_fin!=true)
        {
            posicion = Alf.find(*j);
            if(posicion==string::npos)
            {
                Alf.at(i)=*j;
                i++;
            }
            if((j+1)==cl_p.end())
            {
                palabra_fin=true;
                j=abc.begin();
            }
        }
        else
        {
            posicion=Alf.find(*j);
            if(posicion==string::npos)
            {
                Alf.at(i)=*j;
                i++;
            }
        }
    }
    return Alf;
}

string Monomio_Binomio::cifrado(string m)
{
    for(j=m.begin(); j!=m.end(); j++)
    {
        if((*j)==' ')
        {
            j++;
            new_m<<" ";
        }
        posicion = Alf.find(*j);
        if(posicion>=0 && posicion<10)
        {
            new_m<<to_string(posicion);
        }
        else
        {
            if(posicion/10==1)
            {
                new_m<<cl_n_1<<to_string(posicion%10);
            }
            else
            {
                new_m<<cl_n_2<<to_string(posicion%10);
            }
        }
    }
    return new_m.str();
}

string Monomio_Binomio::descifrado(string m)
{
    for(j=m.begin(); j!=m.end();)
    {
        if((*j)==' ')
        {
            j++;
            new_m<<" ";
        }
        i=(*j)-'0';
        if(i!=cl_n_1 && i!=cl_n_2)
        {
            new_m<<Alf.at(i);
            j++;
        }
        else if(i==cl_n_1)
        {
            j++;
            i=(*j)-'0';
            i+=10;
            new_m<<Alf.at(i);
            j++;
        }
        else if(i==cl_n_2)
        {
            j++;
            i=(*j)-'0';
            i+=20;
            new_m<<Alf.at(i);
            j++;
        }
    }
    return new_m.str();
}
