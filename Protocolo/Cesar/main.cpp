#include <iostream>
#include <Cesar.h>



int main()
{
    string m,c,d;


    cout<<"comp_Emisora"<<endl;
    cout<<"  ________\n";
    cout<<" | ------ |\n";
    cout<<" | |    | |\n";
    cout<<" | ------ |\n";
    cout<<"  --------\n";
    cout<<"     | |\n";
    cout<<" ------------\n";

    cout<<"escriba su mensaje: ";
    getline(cin, m);

    Cesar emisor(m);

    cout<<endl;

    c=emisor.Codificacion_Alf();

    cout<<"\t|\n";
    cout<<"\t|\n";
    cout<<"\t|\tCodificando con clave: "<<c<<endl;
    cout<<"\t|\n";
    cout<<"\tV\n\n";

    Cesar receptor(c);

    cout<<"comp_Receptora"<<endl;
    cout<<"  ________\n";
    cout<<" | ------ |\n";
    cout<<" | |    | |\n";
    cout<<" | ------ |\n";
    cout<<"  --------\n";
    cout<<"     | |\n";
    cout<<" ------------\n";
    d=receptor.Decodificacion_Alf();
    cout<<"mensaje recibido: "<<d<<endl;


}
