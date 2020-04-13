#include "Cesar.h"


Cesar::Cesar()
{
    clave=3;
}

string Cesar::Codificacion(string  str)
{
    for(int unsigned i=0; i<str.length(); i++)
    {
        if(str.at(i)!=' ')
        {
            if(str.at(i)>='A' && str.at(i)<='Z')
            {
                if( clave <= ('Z'- str.at(i)) )
                {
                    str.at(i)+=clave;
                }
                else
                {
                    *resto=clave-('Z'-str.at(i));
                    str.at(i)='@'+ *resto;//si A ser�a 1, @ ser�a el 0
                }
            }
            else
            {
                if( clave <= ('z'- str.at(i)) )
                {
                    str.at(i)+=clave;
                }
                else
                {
                    *resto=clave-('z'- str.at(i));
                    str.at(i)='`'+*resto;//si A ser�a 1, @ ser�a el 0
                }
            }
        }
    }
    return str;
}

string Cesar::Decodificacion(string str)
{
    for(int unsigned i=0; i<str.length(); i++)
    {
        if(str.at(i)!=' ')
        {
            if(str.at(i)>='A' && str.at(i)<='Z')
            {
                if( clave <= (str.at(i))-'A')
                {
                    str.at(i)-=clave;
                }
                else
                {
                    *resto=clave-((str.at(i))-'A');
                    str.at(i)='['- *resto;//si Z ser�a 26, [ ser�a el 27
                }
            }
            else
            {
                if( clave <= (str.at(i))-'a' )
                {
                    str.at(i)-=clave;
                }
                else
                {
                    *resto=clave-((str.at(i))-'a');
                    str.at(i)='{'-*resto;//si z ser�a 26, { ser�a el 27
                }
            }
        }
    }
    return str;
}

Cesar::~Cesar()
{
    delete resto;
}
