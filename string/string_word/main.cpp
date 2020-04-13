#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;


void minu_MAYUS(string &refString)
{
    for(int unsigned i=0; i<refString.length(); i++)
    {
        if(refString.at(i)!=' ')
        {
            if(refString.at(i)>='A' && refString.at(i)<='Z')
            {
                    refString.at(i)+=32;
            }
            else
            {
                refString.at(i)-=32;
            }
        }
    }
}

string int_to_string(int e)
{
    return to_string(e);
}

string concatenacion(string a, string b)
{
    return a + b;
}

int string_to_int(string str)
{
    int longitud = str.length();
    char *ptr2 = new char[ longitud + 1 ];

    str.copy( ptr2, longitud, 0 );
    ptr2[ longitud ] = '\0';
    char *c=ptr2;
    delete [] ptr2;
    return atoi(c);
}

int numero_de_palabras(string oracion, string p_busco)
{
    int cant=0;
    int unsigned posicion = oracion.find( p_busco );

     while (posicion!=string::npos)
     {
         cant++;
         posicion = oracion.find( p_busco, posicion + 1 );
     }
    return cant;
}

void dar_string_n_characters(string &str)
{
    cout<<"que cantidad de characters quiere?: ";
    int cant;
    cin>>cant;
    str.resize( str.length() + cant);
}

void print_new_line(string cadena)
{
    string::const_iterator iterador1 = cadena.begin();
    while ( iterador1 != cadena.end() )
    {
        cout <<"\'"<<*iterador1<<"\'"<<endl;
        iterador1++;
    }
}

void insertar_medio(string &str_1,string str_2)
{
    str_1.insert(str_1.length()/2, str_2 );
}

void cambio_de_palabras(string &oracion, string p_busco, string p_reemp)
{
    int unsigned posicion = oracion.find( p_busco );

     while (posicion!=string::npos)
     {
         oracion.replace( posicion, p_busco.length(), p_reemp );
         posicion = oracion.find( p_busco, posicion + 1 );
     }
}

void comparacion(string comp_1, string comp_2)
{
    if (comp_1==comp_2)
    {
        cout<<comp_1<<" = "<<comp_2<<endl;
    }
    else
    {
        if (comp_1>comp_2)
        {
            cout<<comp_1<<" > "<<comp_2<<endl;
        }
        else
        {
            cout<<comp_1<<" < "<<comp_2<<endl;
        }
    }
}

void escribir_arch_numeros()
{
    srand(time(NULL));
    int cant=rand()%(10);
    ofstream archivo;
    archivo.open("numeros.txt", ios::out);
    if(archivo.fail())
    {
        cout<<"no se pudo abrir el archivo"<<endl;
        exit(1);
    }
    for(int i=0; i<=cant; i++)
    {
        int num=rand()%(1000);
        archivo<<num<<" ";
    }
    archivo.close();
}

int leer_arch_numeros()
{
    int suma;
    int num=0;
    ifstream archivo;
    archivo.open("numeros.txt", ios::in);
    if(archivo.fail())
    {
        cout<<"no se pudo abrir el archivo"<<endl;
        exit(1);
    }
    archivo>>num;
    while(!archivo.eof())
    {
        suma+=num;
        cout<<num<<endl;
        archivo>>num;
    }
    archivo.close();
    return suma;
}

int main()
{
    //1.	Convertir un objeto string a un array de tipo char, y viceversa.


    //2.	¿Cuál es la diferencia entre la función capacity y la función size de la clase string?
//           Una diferencia muy resaltante es que capacity a lo menos tiene el tamaño del string mientras que size es siempre exactamente
//           el tamaño del string.

    //3.	Convertir las letras de un string de minúsculas a mayúsculas, y las mayúsculas a minúsculas.
    string Mn("AAAZZHH azazahgj");
    minu_MAYUS(Mn);
    cout<<Mn<<endl;
    /*
        4.	Recibir dos números por consola en variables tipo entero, luego construir un objeto string
            que concatene el primer número seguido del segundo número. Imprimir la cadena resultante,
            y en una nueva línea su valor multiplicado por 2. Usar funciones para convertir de string a entero y visceversa.

            Ejemplo:

                        Input:
                        15
                        135

                        Output:
                        15135
                        30270
    */
    int int_1, int_2;
    cout<<"ingrese un numero: ";
    cin>>int_1;
    cout<<"ingrese otro numero: ";
    cin>>int_2;
    string str_1=int_to_string(int_1);
    string str_2=int_to_string(int_2);
    string concatenado=concatenacion(str_1,str_2);
    cout<<concatenado<<endl;
    int int_3 = string_to_int(concatenado);
    cout<<int_3*2<<endl;



    //5.	Crear un objeto string que esté formado por 1000 caracteres ‘a’, escribiendo una sola línea de código.

    string mil(1000,'a');
    cout<<mil<<"tamaño: "<<mil.length()<<endl;

    //6.	Convertir la cadena: “Yo desaprobe el curso de Algebra Abstracta” a la cadena: “Yo aprobe el curso de Algebra Abstracta”.

    string cadena_modificable("“Yo desaprobe el curso de Algebra Abstracta”");
    cout<<cadena_modificable<<endl;

    cadena_modificable.erase(4,3);
    cout<<cadena_modificable<<endl;

    cin.ignore();
    /*
        7.	Recibir dos strings por entrada estándar, una frase y una palabra. Contar cuántas veces aparece la palabra en la frase.

                        Ejemplo:
                        Input:
                            Como poco coco como, poco coco compro.
                            coco
                        Output:
                            2
    */
    string cadena;
    string palabra;
    cout<<"introduzca una oración con palabras que se repitan si usted quiere: ";
    getline(cin,cadena);
    cout<<"introduzca la palabra a buscar: ";
    cin>>palabra;

    int n_palabras=numero_de_palabras(cadena, palabra);
    cout<<"la cantidad de \'"<< palabra<<"\' en la oración\n \""<<cadena<<"\"\n es: "<<n_palabras<<endl;

    //8.	Recibir un string de longitud N e imprimir cada letra del string en una nueva línea usando iteradores.
    string c="";
    dar_string_n_characters(c);
    print_new_line(c);

    /*
        9.	Recibir dos strings por consola e imprimir un string que tenga al segundo string en la mitad el primer
            string. El primer string siempre tiene tamaño par.

                  Ejemplo:
                    Input:
                        gato
                        ti

                    Output:
                        gatito
    */

    cout<<"coloque una palabra: ";
    string p_1;
    cin>>p_1;
    cout<<"\ncoloque la palabra que quiere en el medio de la anterior palabra: ";
    string p_2;
    cin>>p_2;
    insertar_medio(p_1,p_2);
    cout<<"\n"<<p_1<<endl;

    cin.ignore();
    /*
    10.	Recibir tres strings por consola, buscar todas las apariciones del segundo string en el primero y reemplazarlas por
        el tercer string recibido.

        Ejemplo:
            Input:
                Cuando te diga que te creo, no me creas, porque ya no creo lo que creo.
                creo
                temo
            Output:
                Cuando te diga que te temo, no me creas, porque ya no temo lo que temo.
    */

    cout<<"introduzca una oración con palabras que se repitan si usted quiere: ";
    getline(cin,cadena);
    cout<<"introduzca la palabra a buscar: ";
    cin>>palabra;
    string reemp;
    cout<<"introduzca su reemplazo: ";
    cin>>reemp;

    cambio_de_palabras(cadena, palabra, reemp);
    cout<<"nueva oración: "<<cadena<<endl;

    /*
    11.	Dadas dos palabras, imprimir la que es lexicográficamente mayor.

         Ejemplo:
            Input:
                Algebra
                Abstracta
            Output:
                Algebra
    */

    string comp_1, comp_2;
    cout<<"introdusca su primer palabra: ";
    cin>>comp_1;
    cout<<"\nintrodusca su segunda palabra: ";
    cin>>comp_2;
    comparacion(comp_1, comp_2);

    cin.ignore();
    /*
    12.	Crear una función que reciba un número N (N va de 1 a 10), y que
        escriba N números con valores que van de 1 a 1000 en un archivo llamado “numeros.txt”.
    */

    escribir_arch_numeros();

    /*
    13.	Leer los números en el archivo “numeros.txt” de la pregunta 10 e imprimir la sumatoria.
    */
    cout<<"la suma de los numeros dentro del archivo \"numeros.txt\" es :"<<leer_arch_numeros()<<endl;
}
