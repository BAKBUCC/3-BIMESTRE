#include <iostream>
#include <Cesar.h>

void dibujar_comp()
{
    cout<<"  ________\n";
    cout<<" | ------ |\n";
    cout<<" | |    | |\n";
    cout<<" | ------ |\n";
    cout<<"  --------\n";
    cout<<"     | |\n";
    cout<<" ------------\n";
}

string alfabeto_Num = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";

int main()
{
    string m,c,d;
    int clave=3;

    cout<<"comp_Emisora"<<endl;
    dibujar_comp();
    cout<<"escriba su mensaje: ";
    getline(cin, m);

    Cesar emisor(clave,alfabeto_Num);

    cout<<endl;

    c=emisor.Codificacion_Alf(m);

    cout<<"\t|\n";
    cout<<"\t|\n";
    cout<<"\t|\tCodificando con clave: "<<c<<endl;
    cout<<"\t|\n";
    cout<<"\tV\n\n";

    Cesar receptor(clave,alfabeto_Num);

    cout<<"comp_Receptora"<<endl;
    dibujar_comp();
    d=receptor.Decodificacion_Alf(c);
    cout<<"mensaje recibido: "<<d<<endl;
}
