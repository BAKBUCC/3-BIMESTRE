#include "Vigenere.h"
#include <fstream>

string alfabeto_Num("abcdefghijklmnopqrstuvwxyz -ABCDEFGHIJKLMNOPQRSTUVWXYZ,.0123456789");
string alfabeto("ÇüéâäàåçêëèïîìÄÅÉæÆôöòûù®ÖÜø£Ø×ƒ !\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_"
                        "`abcdefghijklmnopqrstuvwxyz{|}~");
string posHex[127]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F",
                    "10","11","12","13","14","15","16","17","18","19","1A","1B","1C","1D","1E","1F",
                    "20","21","22","23","24","25","26","27","28","29","2A","2B","2C","2D","2E","2F",
                    "30","31","32","33","34","35","36","37","38","39","3A","3B","3C","3D","3E","3F",
                    "40","41","42","43","44","45","46","47","48","49","4A","4B","4C","4D","4E","4F",
                    "50","51","52","53","54","55","56","57","58","59","5A","5B","5C","5D","5E","5F",
                    "60","61","62","63","64","65","66","67","68","69","6A","6B","6C","6D","6E","6F",
                    "70","71","72","73","74","75","76","77","78","79","7A","7B","7C","7D","7E"};
string alfabetoMayusculas("ABCDEFGHIJKLMN~OPQRSTUVWXYZ");


string leer_archivo()
{
    string concatenacion;
    string p;
    ifstream archivo;
    archivo.open("texto.txt", ios::in);
    if(archivo.fail())
    {
        cout<<"no se pudo abrir el archivo"<<endl;
        exit(1);
    }
    while(!archivo.eof())
    {
        archivo>>p;
        concatenacion+=p;
        concatenacion+=" ";
    }
    archivo.close();
    return concatenacion;
}

void aqui_cada_10(string &refString)
{
    int tamanio=refString.length();
    for(int i=1; i<=(tamanio/10); i++)
    {
        refString.insert( 10*i, "AQUI" );
    }
    Tools h;
    int modulo = h.modulo(tamanio,4);
    if (modulo>0)
    {
        string Ws(4-modulo,'W');//a 4 - resto =cantidad de espacios que le falta para que el tamaño sea multiplo de 4
        refString+=Ws;
    }
}

void introducir_cifrado(string &texto, string &clave)
{
    cin.ignore();
    cout<<"texto:\n";
    getline(cin,texto);

    cout<<"clave:\n";
    getline(cin,clave);

    cout<<"\n ~     ~";
    cout<<"\n 0     0";
    cout<<"\n    ?";
    cout<<"\n       ";
    cout<<"\n ~~~O";
}

string mensaje_Hecho()
{
        string frase("Puedo escribir los versos mas tristes esta noche. "
                        "Escribir, por ejemplo: La noche esta estrellada, "
                        "y tiritan, azules, los astros, a lo lejos. "
                        "El viento de la noche gira en el cielo y canta. "
                        "Puedo escribir los versos mas tristes esta noche. "
                        "Yo la quise, y a veces ella tambien me quiso.");

    return frase;
}


int main()
{
//    string alfabeto="ÇüéâäàåçêëèïîìÄÅÉæÆôöòûù®ÖÜø£Ø×ƒ !\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_"
//                        "`abcdefghijklmnopqrstuvwxyz{|}~";
//    cout<<alfabeto.length()<<endl;
//    cout<<alfabeto.find('a')<<endl;
//    string alfabeto_Num = "abcdefghijklmnopqrstuvwxyz -ABCDEFGHIJKLMNOPQRSTUVWXYZ,.0123456789";
//    cout<<alfabeto_Num.length()<<endl;


    //ingreso de texto plano por archivo
//    string frase=leer_archivo();

    //ingreso de texto plano por interfaz
    cout<<"Quiere colocar un texto( 1 ) o lo quiere ya hecho( 2 )?\n";
    int num;
    string frase,clave;
    cin>>num;

    if( num==1 )
    {
        introducir_cifrado(frase,clave);
    }
    else if( num==2 )
    {
        frase=mensaje_Hecho();
        clave="Rony Rodrigo Sicos Barrera (101-10-46034)";
    }
    else
    {
        return 0;
    }


    //para agregar a la frase los "AQUI" descomente la sgte. linea
    //aqui_cada_10(frase);
    string c,d;

    cout<<"\nmensaje original: "<<frase<<endl;

    cout<<"\n\n¿Qué alfabeto quiere utilizar?: \n(1)Alf. Numerico \n(2)Codico ASCII\n(3)Codico HEX \n(4)utilizar de CODIGO: codigo más mensaje\n\n";
    cin>>num;

    if(num==1)
    {
        Vigenere emisor(clave, alfabeto_Num);
        c = emisor.codificacion_con_alfPuesto(frase);
        cout<<"\n\nmensaje codificado con alfabeto numerico:"<<c<<endl;

        Vigenere receptor(clave, alfabeto_Num);
        d = receptor.decodificacion_con_alfPuesto(c);
        cout<<"\n\nmensaje decodificado con alfabeto numerico: "<<d<<endl;
    }
    if(num==2)
    {
        Vigenere emisor(clave, alfabeto);
        c = emisor.codificacion_con_alfPuesto(frase);
        cout<<"\n\nmensaje codificado con ASCII: "<<c<<endl;

        Vigenere receptor(clave, alfabeto);
        d = receptor.decodificacion_con_alfPuesto(c);
        cout<<"\n\nmensaje decodificado con ASCII: "<<d<<endl;
    }
    if(num==3)
    {
        Vigenere emisor(clave, alfabeto);
        c = emisor.codificacion_con_alfHEX(frase);
        cout<<"\n\nmensaje codificado con HEX: "<<c<<endl;

        Vigenere receptor(clave, alfabeto);
        d = receptor.decodificacion_con_alfHEX(c);
        cout<<"\n\nmensaje decodificado con HEX: "<<d<<endl;
    }
    if(num==4)
    {
        Vigenere emisor(clave, alfabeto_Num);
        c = emisor.codificacion_Codigo_y_luego_Mensaje(frase);
        cout<<"\n\nmensaje codificado con codigo más mensaje: "<<c<<endl;

        Vigenere receptor(clave, alfabeto_Num);
        d = receptor.decodificacion_Codigo_y_luego_Mensaje(c);
        cout<<"\n\nmensaje decodificado con codigo más mensaje: "<<d<<endl;
    }
    if(num==5)
    {
        Vigenere emisor(clave, alfabetoMayusculas);
        c = emisor.codificacion_Codigo_y_luego_Mensaje(frase);
        cout<<"\n\nmensaje codificado con codigo más mensaje: "<<c<<endl;

        Vigenere receptor(clave, alfabetoMayusculas);
        d = receptor.decodificacion_Codigo_y_luego_Mensaje(c);
        cout<<"\n\nmensaje decodificado con codigo más mensaje: "<<d<<endl;
    }

    return 0;
}


