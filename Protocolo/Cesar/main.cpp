#include <iostream>
#include <Cesar.h>



int main()
{
    string *str=new string;

    Cesar emisor;
    Cesar receptor;

    cout<<"comp_Emisora"<<endl;
    cout<<"  ________\n";
    cout<<" | ------ |\n";
    cout<<" | |    | |\n";
    cout<<" | ------ |\n";
    cout<<"  --------\n";
    cout<<"     | |\n";
    cout<<" ------------\n";

    cout<<"escriba su mensaje: ";
    getline(cin, *str);

    cout<<endl;

    *str=emisor.Codificacion(*str);

    cout<<"\t|\n";
    cout<<"\t|\n";
    cout<<"\t|\tCodificando con clave: "<<*str<<endl;
    cout<<"\t|\n";
    cout<<"\tV\n\n";

    cout<<"comp_Receptora"<<endl;
    cout<<"  ________\n";
    cout<<" | ------ |\n";
    cout<<" | |    | |\n";
    cout<<" | ------ |\n";
    cout<<"  --------\n";
    cout<<"     | |\n";
    cout<<" ------------\n";
    *str=receptor.Decodificacion(*str);
    cout<<"mensaje recibido: "<<*str<<endl;

    delete str;
}
