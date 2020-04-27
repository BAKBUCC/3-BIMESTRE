#include "Vigenere.h"

Vigenere::Vigenere(string str)
{
    m =str;
    c.resize( m.length());
    d.resize( m.length());

}

string Vigenere::codificacion_con_alfNum()
{
    for(i=0, l=0; i<m.length(); i++,l++)
    {
        if (l==clave.length())
        {
            l=0;
        }
        suma=alfabeto_Num.find(m[i])+alfabeto_Num.find(clave[l]);
        mod=suma%(alfabeto_Num.length());
        c[i]=alfabeto_Num[mod];
    }
    return c;
}
string Vigenere::decodificacion_con_alfNum()
{
    total=alfabeto_Num.length();
    for(i=0, l=0; i<m.length(); i++,l++)
    {
        if (l==clave.length())
        {
            l=0;
        }
        resta=alfabeto_Num.find(m[i])-alfabeto_Num.find(clave[l]);
        mod=resta%total;
        if(mod<0)
        {
            mod=total+mod;
        }
        d[i]=alfabeto_Num[mod];
    }
    return d;
}

string Vigenere::codificacion_con_alfASCII()
{
    for(i=0, l=0; i<m.length(); i++,l++)
    {
        if (l==clave.length())
        {
            l=0;
        }
        suma=alfabeto.find(m[i])+alfabeto.find(clave[l]);
        mod=suma%alfabeto.length();
        c[i]=alfabeto[mod];
    }
    return c;
}
string Vigenere::decodificacion_con_alfASCII()
{
    total=alfabeto.length();
    for(i=0, l=0; i<m.length(); i++,l++)
    {
        if (l==clave.length())
        {
            l=0;
        }
        resta=alfabeto.find(m[i])-alfabeto.find(clave[l]);
        mod=resta%total;
        if(mod<0)
        {
            mod=total+mod;
        }
        d[i]=alfabeto[mod];
    }
    return d;
}

string Vigenere::codificacion_con_alfHEX()
{
    for(i=0, l=0; i<m.length(); i++,l++)
    {
        if (l==clave.length())
        {
            l=0;
        }
        cout<<showbase<<hex;
        suma=alfabeto.find(m[i])+alfabeto.find(clave[l]);
        mod=suma%alfabeto.length();;
        c[i]=alfabeto[mod];
        cout<<showbase<<dec;
    }
    return c;
}
string Vigenere::decodificacion_con_alfHEX()
{
    total=alfabeto.length();
    for(i=0, l=0; i<m.length(); i++,l++)
    {
        if (l==clave.length())
        {
            l=0;
        }
        cout<<showbase<<hex;
        resta=alfabeto.find(m[i])-alfabeto.find(clave[l]);
        mod=resta%total;
        if(mod<0)
        {
            mod=total+mod;
        }
        d[i]=alfabeto[mod];
        cout<<showbase<<dec;
    }
    return d;
}

string Vigenere::codificacion_Codigo_Mensaje()
{
    mensaje=false;
    for(i=0, l=0; i<m.length() ; i++,l++)
    {
        if(mensaje==true)
        {
            suma=alfabeto_Num.find(m[i])+alfabeto_Num.find(m[l]);
        }
        else
        {
            if (i==clave.length())
            {
                l=0;
                mensaje=true;
            }
            else
            {
                suma=alfabeto_Num.find(m[i])+alfabeto_Num.find(clave[l]);
            }
        }
        mod=suma%66;
        c[i]=alfabeto_Num[mod];
    }
    return c;
}
string Vigenere::decodificacion_Codigo_Mensaje()
{
    for(i=0, l=0; l<clave.length() ; i++,l++)
    {
        resta=alfabeto_Num.find(m[i])-alfabeto_Num.find(clave[l]);
        mod=resta%66;
        if(mod<0)
        {
            mod=66+mod;
        }
        d[i]=alfabeto_Num[mod];
    }
    l=0;
    while(i<m.length())
    {
        for(int unsigned j=0 ; j<clave.length() && i<m.length();i++,l++,j++)
        {
            resta=alfabeto_Num.find(m[i])-alfabeto_Num.find(d[l]);
            mod=resta%66;
            if(mod<0)
            {
                mod=66+mod;
            }
            d[i]=alfabeto_Num[mod];
        }
    }
    return d;
}



