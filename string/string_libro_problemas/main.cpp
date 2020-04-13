#include <iostream>
#include <string.h>
#include <string>
#include <cstdlib>
#include<time.h>
#include <stdlib.h>

using namespace std;

void rot13(string &refString)
{
    int resto;
    for(int unsigned i=0; i<refString.length(); i++)
    {
        if(refString.at(i)!=' ')
        {
            if(refString.at(i)>='A' && refString.at(i)<='Z')
            {
                if(13<=('Z'-refString.at(i)))
                {
                    refString.at(i)+=13;
                }
                else
                {
                    resto=13-('Z'-refString.at(i));
                    refString.at(i)='@'+resto;//si A ser�a 1, @ ser�a el 0
                }
            }
            else
            {
                if(13<=('z'-refString.at(i)))
                {
                    refString.at(i)+=13;
                }
                else
                {
                    resto=13-('z'-refString.at(i));
                    refString.at(i)='`'+resto;//si A ser�a 1, @ ser�a el 0
                }
            }
        }
    }
}



string concatenacion(const string nombre, const string apellido)
{
    return (nombre+" "+apellido);
}

string palabra_azar()
{
    srand(time(NULL));
    string palabras[6]={"julio", "sentido", "conversacion", "monitor", "ahorcado", "tareas"};
    return palabras[rand()%6];
}

string palabra_codificada(string p)
{
    int longitud =p.length();
    string cod(longitud,'X');
    return cod;
}

void errores(int i)
{
    if(i==1)
    {
        cout<<" 0"<<endl;
    }
    if(i==2)
    {
        cout<<" 0"<<endl;
        cout<<" |"<<endl;
    }
    if(i==3)
    {
        cout<<" 0"<<endl;
        cout<<"/|"<<endl;
    }
    if(i==4)
    {
        cout<<" 0"<<endl;
        cout<<"/|\\"<<endl;
    }
    if(i==5)
    {
        cout<<" 0"<<endl;
        cout<<"/|\\"<<endl;
        cout<<" |"<<endl;
    }
    if(i==6)
    {
        cout<<" 0"<<endl;
        cout<<"/|\\"<<endl;
        cout<<" |"<<endl;
        cout<<"/"<<endl;
    }
    if(i==7)
    {
        cout<<" 0"<<endl;
        cout<<"/|\\"<<endl;
        cout<<" |"<<endl;
        cout<<"/ \\"<<endl;
    }
    if(i==8)
    {
        cout<<" |"<<endl;
        cout<<" 0"<<endl;
        cout<<"/|\\"<<endl;
        cout<<" |"<<endl;
        cout<<"/ \\"<<endl;
    }
    /*|
      0
     /|\
      |
     / \
     */
}

void ahorcado(string p_verdadera, string p_codificada)
{
    system("cls");
    cout<<p_codificada<<endl;
    cout<<"coloque letras: ";
    string letra;
    cin>>letra;
    int unsigned posicion;
    int n_errores=0;
    while(p_codificada!=p_verdadera && n_errores!=8)
    {
        system("cls");
        posicion = p_verdadera.find( letra );
        while(posicion != string::npos)
        {
            p_codificada.replace( posicion, 1, letra );
            posicion = p_verdadera.find( letra, posicion +1 );
        }
        cout<<p_codificada<<endl;
        posicion = p_verdadera.find( letra );//es para que el string::npos no sea igual al -1
        if (posicion == string::npos)
        {
            n_errores++;
        }
        errores(n_errores);
        if(p_codificada!=p_verdadera && n_errores!=8)
        {
            cin>>letra;
        }
    }
    if (n_errores==8)
    {
        cout<<"perdiste"<<endl;
        cout<<"la palabra correcta es: "<<p_verdadera<<endl;
    }
    else if(p_codificada==p_verdadera)
    {
        cout<<"ganaste crack"<<endl;
    }
}



void insert_mitad(string &refString)
{
    //SIN SABER DE "INSERT"
    /*
    string reemplazo(6,'*');
    refString.resize( refString.length() + 1);
    for(int unsigned i=0; i<refString.length()/2+1; i++)
    {
        refString[refString.length()-i]=refString[refString.length()-i-1];
    }
    int posicion=refString.length()/2;
    refString.replace( posicion, 1, reemplazo );
    cout<<refString<<endl;
    */
    refString.insert( refString.length()/2, "******" );
}

void reemp_sig_puntua_to_esp(string &refString)
{
    string sig_pun [10]={",",";",".",":","\"","!","�","�","?","'"};
    int unsigned posicion;
    int i=0;

    // reemplaza todos los sig. de puntuacion con un espacio
    while (i<=9) //  string::npos es cuando no halla lo que quer�a
    {
        posicion=refString.find(sig_pun[i]);
        if(posicion == string::npos)
        {
            i++;
            posicion=refString.find(sig_pun[i]);
        }
        else
        {
        refString.replace( posicion, 1, " " );
        posicion = refString.find( sig_pun[i], posicion + 1 ); // itera la posicion para delante
        }
    }
}

void token(string &refString)
{
    int longitud = refString.length();
    char *ptr2 = new char[ longitud + 1 ];

    refString.copy( ptr2, longitud, 0 );
    ptr2[ longitud ] = '\0';

    char *pch;
    pch = strtok(ptr2," ");
    while (pch != NULL)
    {
        cout<<pch<<endl;
        pch = strtok (NULL, " ");
    }
    delete [] ptr2;
}

void print_alreves(string str)
{
    string::const_iterator iterador1 = str.end() -1;
    while ( iterador1 != str.begin()-1 )
    {
        cout << *iterador1;
        iterador1--;
    }
}

void print_array(string a[], int cant)
{
    for (int i=0; i<cant; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void selection_sort(string *ptr, int cant)
{
    int i,j;
    string *check, *me_muevo;
    for(i=0; i<cant; i++)
    {
        me_muevo=ptr;
        check=ptr+1;
        for(j=i+1; j<cant;j++)
        {
            if(*check<*me_muevo)
            {
                me_muevo=check;
            }
            check++;
        }

        ptr->swap(*me_muevo);
        ptr++;
    }
}

int main()
{
    string m=("Se tu mismo");
    rot13(m);
    cout<<m<<endl;
        /*
    18.21 Escriba un programa que introduzca una l�nea de texto, reemplace todos los signos de puntuaci�n con espacios y utilice
    la funci�n strtok de la biblioteca de cadenas estilo C para dividir el objeto string en palabras individuales (tokens).
    */
    string l_texto;
    cout<<"inserte linea de texto con signos de puntuacion: ";
    getline(cin,l_texto);

    reemp_sig_puntua_to_esp(l_texto);
    cout<<l_texto<<endl;
    token(l_texto);

    /*
    18.22 Escriba un programa que introduzca una l�nea de texto y la imprima al rev�s. Use iteradores en su soluci�n.
    */
    cout<<"inserte linea de texto para imprimirlo alreves: ";
    getline(cin,l_texto);
    cout<<endl;
    print_alreves(l_texto);
    cout<<endl;

    /*
   18.7 (Cifrado simple) Cierta informaci�n en Internet se puede cifrar con un algoritmo simple conocido como �rot13�, el
    cual rota cada car�cter 13 posiciones en el alfabeto. As�, 'a' corresponde a 'n', y 'x' corresponde a 'k'. rot13 es un ejemplo
    del cifrado de clave sim�trica. Con este tipo de cifrado, tanto el que cifra como el que descifra utilizan la misma clave.

    a) Escriba un programa que cifre un mensaje usando rot13.

    b) Escriba un mensaje que descifre el mensaje codificado usando 13 como la clave.

    c) Despu�s de escribir los programas de los incisos (a) y (b), responda brevemente a la siguiente pregunta: si no cono-
    ciera la clave para el inciso (b), �qu� tan dif�cil cree usted que ser�a quebrantar el c�digo? �Qu� pasar�a si tuviera
    acceso a un poder de c�mputo considerable ( por ejemplo, supercomputadoras)? En el ejercicio 18.26 le pediremos
    que escriba un programa para lograr esto.
    */
    //a)
//    string m=("Se tu mismo");
//    rot13(m);
//    cout<<endl;

    //b)
    cout<<"solo 13 personas lo han descubierto, solo tienes que volver a hacia atr�s."<<endl;
    cin.ignore();
    //c) a la primera pregunta responder� que ser�a muy dif�cil ya que estar�a derivando en much�simas posibilidades
    //a la segunda pregunta resposder� que ser�a un poco m�s facil ya que podr�a poner funciones con todos los descifradores que
    //han existido e har�a imprimir los resultados solo cuando exista una oraci�n con sentido.

    /*
    18.11 Escriba un programa que introduzca por separado un primer nombre y un apellido, y que concatene los dos en un
    nuevo objeto string.
    */

    string apellido, nombre;
    cout<<"\n\nApellido: ";
    cin>>apellido;
    cout<<"\nNombre: ";
    cin>>nombre;

    string nom_y_ape=concatenacion(nombre, apellido);
    cout<<nom_y_ape<<endl;
    system("PAUSE()");

    /*
    18.12 Escriba un programa para jugar al ahorcado. El programa debe elegir una palabra (que se codifica directamente en el
    programa, o se lee de un archivo de texto) y mostrar lo siguiente:
    Adivine la palabra: XXXXXX
    Cada X representa una letra. El usuario trata de adivinar las letras en la palabra. Deber� mostrarse la respuesta apropiada
    (si o no) despu�s de cada intento de adivinar. Despu�s de cada intento incorrecto, muestre el diagrama con otra parte del
    cuerpo incluida. Despu�s de siete intentos incorrectos, el usuario deber� colgarse. La pantalla debe tener la siguiente
    apariencia:

      0
     /|\
      |
     / \
    */
    string palabra= palabra_azar();
    string p_codificado=palabra_codificada(palabra);
    ahorcado(palabra,p_codificado);
    system("PAUSE()");

    /*
    18.19 Escriba un programa que inserte los caracteres "******" en la mitad exacta de un objeto string.
    */
    system("cls");
    cout<<"inserte su palabra: ";
    cin>>palabra;
    insert_mitad(palabra);
    cout<<palabra<<endl;
    cin.ignore();

    /*
    18.27 Escriba una versi�n de la rutina de ordenamiento por selecci�n (figura 8.28) que ordene objetos string. Use la funci�n
    swap en su soluci�n.
    */
    cout<<"antes de ordenar"<<endl;
    string orden[6]={"hoyin","musica","masticar","avion","estrella","hunter"};
    print_array(orden,6);
    string *ptr=orden;
    selection_sort(ptr,6);
    cout<<"\n\ndespues de ordenar"<<endl;
    print_array(orden,6);

}

