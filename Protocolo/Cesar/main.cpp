#include <iostream>
#include <Cesar.h>
#include <stdlib.h>
#include<time.h>

using namespace std;

int main()
{
    string *str=new string;
    int *clave=new int;
    int *i=new int;
    *i=1;

    while(*str!="chao")
    {
        cout<<"  comp_"<<*i<<endl;

        cout<<" ________\n";
        cout<<"| ------ |\n";
        cout<<"| |    | |\n";
        cout<<"| ------ |\n";
        cout<<" --------\n";
        cout<<"    | |\n";
        cout<<"------------\n";

        cout<<"escriba su mensaje: ";
        getline(cin, *str);
        srand(time(NULL));
        *clave=rand()%(26);
        cout<<endl;
        Cesar c(*str, *clave);
        c.Codificacion();

        cout<<"\t|\n";
        cout<<"\t|\n";
        cout<<"\t|\tCodificando con clave: "<<*clave<<": "<<*str<<endl;
        cout<<"\t|\n";
        cout<<"\tV\n\n";

        if(*i==1)
        {
            *i=2;
        }
        else if(*i==2)
        {
            *i=1;
        }

        cout<<"  comp_"<<*i<<endl;
        cout<<" ________\n";
        cout<<"| ------ |\n";
        cout<<"| |    | |\n";
        cout<<"| ------ |\n";
        cout<<" --------\n";
        cout<<"    | |\n";
        cout<<"------------\n";
        c.Decodificacion();
        cout<<"mensaje recibido: "<<*str<<endl;

        system("PAUSE()");
        system("cls");
    }
    delete str;
    delete clave;
    delete i;
}
