#include "Cesar.h"


Cesar::Cesar(string m)
{
    str=m;
    c.resize( str.length());
    d.resize( str.length());
}

string Cesar::Codificacion()
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
                    resto=clave-('Z'-str.at(i));
                    str.at(i)='@'+ resto;//si A sería 1, @ sería el 0
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
                    resto=clave-('z'- str.at(i));
                    str.at(i)='`'+resto;//si A sería 1, @ sería el 0
                }
            }
        }
    }
    return str;
}

string Cesar::Decodificacion()
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
                    resto=clave-((str.at(i))-'A');
                    str.at(i)='['- resto;//si Z sería 26, [ sería el 27
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
                    resto=clave-((str.at(i))-'a');
                    str.at(i)='{'-resto;//si z sería 26, { sería el 27
                }
            }
        }
    }
    return str;
}

string Cesar::Codificacion_Alf()
{
    j=0;
    for(string::const_iterator i = str.begin(); i!=str.end(); i++)
    {
        pos = alfabeto_Num.find(*i);
        pos+=clave;
        mod=pos%(alfabeto_Num.length());
        c[j]=alfabeto_Num[mod];
        j++;
    }
    return c;
}

string Cesar::Decodificacion_Alf()
{
    total=alfabeto_Num.length();
    j=0;
    for(string::const_iterator i = str.begin(); i!=str.end(); i++)
    {
        pos = alfabeto_Num.find(*i);
        pos-=clave;
        mod=pos%total;
        if(mod<0)
        {
            mod=total+mod;
        }
        c[j]=alfabeto_Num[mod];
        j++;
    }
    return c;
}

