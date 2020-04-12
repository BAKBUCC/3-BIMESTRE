#include "Cesar.h"


Cesar::Cesar(string &str, int &clave)
:str(&str),clave(&clave){}

void Cesar::Codificacion()
{
    for(int unsigned i=0; i<str->length(); i++)
    {
        if(str->at(i)!=' ')
        {
            if(str->at(i)>='A' && str->at(i)<='Z')
            {
                if( *clave < ('Z'- str->at(i)) )
                {
                    str->at(i)+=*clave;
                }
                else
                {
                    *resto=*clave-('Z'-str->at(i));
                    str->at(i)='@'+ *resto;//si A sería 1, @ sería el 0
                }
            }
            else
            {
                if( *clave < ('z'- str->at(i)) )
                {
                    str->at(i)+=*clave;
                }
                else
                {
                    *resto=*clave-('z'- str->at(i));
                    str->at(i)='`'+*resto;//si A sería 1, @ sería el 0
                }
            }
        }
    }
}

void Cesar::Decodificacion()
{
    *clave=(26-*clave);
    for(int unsigned i=0; i<str->length(); i++)
    {
        if(str->at(i)!=' ')
        {
            if(str->at(i)>='A' && str->at(i)<='Z')
            {
                if( *clave < ('Z'- str->at(i)) )
                {
                    str->at(i)+=*clave;
                }
                else
                {
                    *resto=*clave-('Z'-str->at(i));
                    str->at(i)='@'+ *resto;//si A sería 1, @ sería el 0
                }
            }
            else
            {
                if( *clave < ('z'- str->at(i)) )
                {
                    str->at(i)+=*clave;
                }
                else
                {
                    *resto=*clave-('z'- str->at(i));
                    str->at(i)='`'+*resto;//si A sería 1, @ sería el 0
                }
            }
        }
    }
}

Cesar::~Cesar()
{
    delete str;
    delete clave;
    delete resto;
}
