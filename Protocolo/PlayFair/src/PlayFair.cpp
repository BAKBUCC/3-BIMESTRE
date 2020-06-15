#include "PlayFair.h"

PlayFair::PlayFair(string clave_palabra, string abc)
{
    cl_p=clave_palabra;
    Alf=Alfabetizado(abc);
}

string PlayFair::Alfabetizado(string abc)
{
    bool palabra_fin=false;
    Alf.resize(tamanhio);
    for(i=0,j=cl_p.begin(); i<tamanhio; j++)
    {
        if((*j)==' ')
        {
            j++;
        }
        if(palabra_fin!=true)
        {
            posicion = Alf.find(*j);
            if((*j)=='j')
            {
                posicion=Alf.find('i');
            }

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
            if((*j)=='j')
            {
                posicion=Alf.find('i');
            }
            if(posicion==string::npos)
            {
                Alf.at(i)=*j;
                i++;
            }
        }
    }
    return Alf;
}

void PlayFair::Mensajeado(string &m)
{
    for(i=0,j=m.begin(); j!=m.end(); j++,i++)
    {
        if((*j)==(*(j+1)))
        {
            m.insert(i,"x");
        }
    }
}

string PlayFair::cifrado(string m)
{
    Mensajeado(m);
    for(j=m.begin(); j!=m.end(); j++)
    {
        if(misma_fila==true)
        {

        }
    }
    return new_m.str();
}

bool PlayFair::same_fila(string::iterator j)
{
    if(Alf.)
}


string PlayFair::descifrado(string m)
{
    Mensajeado(m);
    for(j=m.begin(); j!=m.end(); j++)
    {
        if(misma_fila==true)
        {
            posicion=Alf.find(*j);
            if((posicion+1)%5==0)//está en la ultima columna
            {
                new_m<<to_string(Alf.at(posicion-4));
            }
            else
            {
                new_m<<to_string(Alf.at(posicion+1));
            }
            j++;
            posicion=Alf.find(*j);
            if((posicion+1)%5==0)//está en la ultima columna
            {
                new_m<<to_string(Alf.at(posicion-4));
            }
            else
            {
                new_m<<to_string(Alf.at(posicion+1));
            }
        }
        else if(misma_colum==true)
        {
            posicion=Alf.find(*j);
            if((posicion+5)<25)//está en la ultima fila
            {
                new_m<<to_string(Alf.at(posicion%5));
            }
            else
            {
                new_m<<to_string(Alf.at(posicion+5));
            }
            j++;
            posicion=Alf.find(*j);
            if((posicion+5)<25)//está en la ultima fila
            {
                new_m<<to_string(Alf.at(posicion%5));
            }
            else
            {
                new_m<<to_string(Alf.at(posicion+5));
            }
        }
        else //DIFERENTE  FILA Y COLUMNA
        {

        }

    }
    return new_m.str();
}
