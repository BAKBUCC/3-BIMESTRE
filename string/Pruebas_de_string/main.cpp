#include <iostream>
#include <string>

using namespace std;

void imprimirEstadisticas( const string &refString )// al string que pondremos aqui como nadie debe cambiarlo, debe ser constante y
{                                                    // tambien se pone como referencia
    cout << "capacidad: " << refString.capacity() // la capacidad puede ser igual al tamaño actual del string o mayor
    << "\ntamanio max: " << refString.max_size()  // es la máxima capacidad que puede tener un string//si nos pasamos saldra "length_error."
    << "\ntamanio: " << refString.size() //es el tamaño del string ejemplo: letra.tamanño= 5
    << "\nlongitud: " << refString.length() // es lo mismo que el tamaño pero se le llama longitud
    << "\nvacia: " << refString.empty(); //si está vacio saldrá "true", si esta ocupado saldrá "false"
}

int main()
{
    /*
    string nombre( 8, 'x' );
    cout<<nombre<<endl;//waoooouu

    string mes = "Marzo"; // igual que: string mes( "Marzo" ); //check
    cout<<mes<<endl;
    cout<<mes.size()<<endl;
    cout<<mes.length()<<endl;//size y length sacan el tamaño

    mes[4]='q';//M esta en la posicion "0", a esta en la pos. "1" y así sucesuavemente //posdata lo he modificado
    cout<<mes<<endl;

    string cadena;
    getline( cin, cadena );//puedo obtener más de una cadena y permite imprimirla
    cout<<cadena<<endl;

    string objetoString;
    cin >> objetoString;
    cout<<objetoString<<endl;//solo imprime hasta llegar al espacio

    string cadena1("cat");
    string cadena2;
    string cadena3;

    cadena2 = cadena1; //se asigna cadena1 a cadena2
    cadena3.assign(cadena1);//lo mismo de arriba pero cadena3
    cout << "cadena1: " << cadena1 << "\ncadena2: " << cadena2<< "\ncadena3: " << cadena3 << "\n\n";

    //assign tambien tiene otra funcion de copiar un numero especificdo de caracteres. ejemplo
    string cadenaDestiny;
    string cadenaOrigen("CALLAOECHIVOLOPULPIN");
    cadenaDestiny.assign(cadenaOrigen,7,7);//el 7 es el subindice de la letra c y el otro 7 es la cantidad de letras que quiero copiar
    cout<<"cadena Origen= "<<cadenaOrigen<<"\ncadenaDestiny desde la c hasta la n= "<<cadenaDestiny<<"\n\n";

    cadena2[0]=cadena3[2]='r';

    cout << "cadena1: " << cadena1 << "\ncadena2: " << cadena2<< "\ncadena3: " << cadena3 << "\n\n";

    for ( unsigned int i = 0; i < cadena3.length(); i++ )
    {
        cout << cadena3.at( i )<<endl;//at ataca a cada caracter del string
    }

    //concatenación
    string cadena4(cadena1+"apulta");
    string cadena5;

    //esto es la sobrecarga
    cadena3+="peta";
    cadena1.append("acumba");//el append lo coloca al final

    // adjunta las ubicaciones de los subíndices 4 hasta el final de cadena1 para
    // crear la cadena "cumba" (al principio, cadena5 estaba vacía)
    cadena5.append( cadena1, 4, cadena1.length() - 4 );//(lo que le quiero poner al final, desde que subindice le pongo, cuantas
                                                        //letras le pongo)

    cout << "\n\nDespues de concatenar:\ncadena1: " << cadena1
    << "\ncadena2: " << cadena2 << "\ncadena3: " << cadena3
    << "\ncadena4: " << cadena4 << "\ncadena5: " << cadena5 << endl;
    */

    /*
    //COMPARACIONES
    string pero="skbdbkskjc  asjj as  asj casj ";
    string cadena1("Probandoando las funciones de comparacion.");
    string cadena2("Hola");
    string cadena3("probador");
    string cadena4(cadena2);

    cout<<pero<<endl;
    cout << "cadena1: " << cadena1 << "\ncadena2: " << cadena2
    << "\ncadena3: " << cadena3 << "\ncadena4: " << cadena4 << "\n\n";
    //creo que solo imprime una palabra cuando se pide.(el getline es más recomendable
    // comparación de cadena1 y cadena4

    if (cadena1==cadena4)
    {
        cout<<"cadena1==cadena4\n";
    }
    else
    {
        if (cadena1>cadena4)//segun el numero que te proporciona los caracteres ASCII ejm: Xopa>AKAJSBDKSABD porque 'X'
        {
            cout<<"cadena1 > cadena4\n";
        }
        else
        {
            cout<<"cadena1 < cadena4\n";
        }
    }
    int resultado = cadena1.compare(cadena2);// resultado se le asigna 0 si los objetos string son equivalentes,
                                             // un número positivo si cadena1 es lexicográficamente
                                             // mayor que cadena2, o un número negativo si cadena1 es lexicográficamente menor que cadena2.
    // Debido a que una cadena que empieza con 'P'(Proband..) se considera lexicográficamente mayor que una cadena que empieza con 'H'(Hola),
    // a resultado se le asigna un valor mayor que 0,

    //lo que yo entendi es que se evalua por como comenzo hasta el final según el conjunto de caracteres ASCII, ese será el mayor

    if (resultado==0)
    {
        cout<<"cadena1.compare(cadena2)==0\n";
    }
    else
    {
        if (resultado>0)
        {
            cout<<"cadena1.compare(cadena2)>0\n"<<endl;
        }
        else
        {
            cout<<"cadena1.compare(cadena2)<0\n";
        }
    }

    //Comparación en porciones
    resultado = cadena1.compare( 1, 4, cadena3, 1, 4 );// palabra x(subindice de x que desde ahí se va a comparar, cantidad de letras
                                                       // despues, palabra y, inicio, cantidad)
    // resultado = cadena4.compare( 0, cadena2.length(), cadena2 );// esto es lo mismo de arriba pero sin preguntarle a la cadena 2 desde
      // se compara Hola con Hola y sale 0                         // donde quiere empezar y cuanta longitud quiere
    // resultado = cadena2.compare( 0, 3, cadena4 );//otro ejemplo
      // se compara Hol con Hola y por obvias razones, al ir iterando de caracter a caracter, al momento de quedarse solo el a, gana el Hola
      // por default xd
    if (resultado==0)
    {
        cout << "cadena1.compare( 1, 4, cadena3, 1, 4 )==0 \n";
    }
    else
    {
        if (resultado>0)
        {
            cout << "cadena1.compare( 1, 4, cadena3, 1, 4 )>0\n";
        }
        else
        {
            cout << "cadena1.compare( 1, 4, cadena3, 1, 4 )>0\n";
        }
    }
    */

    /*
    //SUBCADENAS
    string cadena1("El aeroplano aterrizo a tiempo.");
    cout<<cadena1.substr(7,5)<<endl;//7 es el subindice de "p" y 5 es la cantidad de caracteres desde ahí pa delante

    //INTERCAMBIO
    string primero("uno");
    string segundo("dos");

    cout<<"antes del cambio\nprimero: "<<primero<<"\nsegundo: "<<segundo<<endl;
    primero.swap(segundo);//es útil para implementar programas que ordenan cadenas.

    cout << "\n\nDespues de swap:\nprimero: " << primero<< "\nsegundo: " << segundo << endl;
    */


    /*
    //CARACTERISTICAS DE UN STRING

    //funcion de arribota, para que no subas xd
//    void imprimirEstadisticas( const string &refString )// al string que pondremos aqui como nadie debe cambiarlo, debe ser constante y
//{                                                    // tambien se pone como referencia
//    cout << "capacidad: " << refString.capacity() // la capacidad puede ser igual al tamaño actual del string o mayor
//    << "\ntamanio max: " << refString.max_size()  // es la máxima capacidad que puede tener un string//si nos pasamos saldra "length_error."
//    << "\ntamanio: " << refString.size() //es el tamaño del string ejemplo: letra.tamanño= 5
//    << "\nlongitud: " << refString.length() // es lo mismo que el tamaño pero se le llama longitud
//    << "\nvacia: " << refString.empty(); //si está vacio saldrá "true", si esta ocupado saldrá "false"
//}

    string cadena1;
    cout << "Estadísticas antes de la entrada:\n" << boolalpha;//el boolalpha hace que el 1 y el 0 se impriman como true y false
    imprimirEstadisticas(cadena1);

    cout<<"\n\nEscriba una Cadena: ";
    cin>>cadena1;// delimitada por espacio en blanco, ya que todo lo que no se imprime se queda en el buffer de entrada
    cout << "La cadena introducida fue: " << cadena1;

    cout << "\nEstadísticas despues de la entrada:\n";
    imprimirEstadisticas(cadena1);

    // adjunta 46 caracteres a cadena1
    cadena1 += "1234567890abcdefghijklmnopqrstuvwxyz1234567890";
    cout << "\n\ncadena1 es ahora: " << cadena1 << endl;
    imprimirEstadisticas( cadena1 );

    // agrega 10 elementos a cadena1
    cadena1.resize( cadena1.length() + 10);
    cout << "\n\nEstadisticas despues de cambiar el tamanio en base a (length + 10):\n";
    imprimirEstadisticas( cadena1 );

    */

    /*
    //BÚSQUEDA DE SUBCADENAS Y CARACTERES EN UN STRING

    string cadena1("mediodia es 12 pm; medianoche no es.");
    int ubicacion;

    // encuentra "es" en las ubicaciones 9 y 33
    cout<<"Cadena original:\n" << cadena1
    <<"\n\n(find) \"es\" se encontro en: "<<cadena1.find("es") // busca la palabra desde el comienzo de cadena1 y da su posicion
    <<"\n(rfind) \"es\" se encontro en: "<< cadena1.rfind("es"); // busca la palabra desde el final y da su posicion

    // encuentra 'e' en la ubicación 1
    ubicacion=cadena1.find_first_of("liesop");// esta funcion busca desde el comienzo de cadena1 si existe una ocurrencia de caracter con la palabra liesop
    cout<<"\n\n(find_first_of) encontro '"<<cadena1[ubicacion]
    <<"' del grupo \"liesop\" en: "<<ubicacion;

    // encuentra 's' en la ubicación 34
    ubicacion=cadena1.find_last_of("liesop");// busca la ocurrencia de caracter desde el final
    cout<<"\n\n(find_last_of) encontro '"<<cadena1[ubicacion]
    <<"' del grupo \"liesop\" en: "<<ubicacion;

    // encuentra '1' en la ubicación 12
    ubicacion=cadena1.find_first_not_of("medop ias"); // esto busca desde el comienzo el caracter que no se encuentra en cadena1 que si se encuentra
    cout<<"\n\n(find_first_not_of) '"<<cadena1[ubicacion] //en "medop ias"
    <<"' no esta  contenido en \"medop ias\" y se encontro en: "<<ubicacion;

    // encuentra ';' en la ubicación 17
    ubicacion=cadena1.find_first_not_of("12medop ias");//aqui cambia de caracter porque ya encuentra el numero 1 y 2, pero al seguir no encuentra el ";"
    cout<<"\n\n(find_first_not_of) '"<<cadena1[ubicacion]
    <<"' no esta contenido en \"12medop ias\" y se encontro en: "<<ubicacion<<endl;

    // busca los caracteres que no estén en cadena1 y como no encuentra algo que falte, devuelve el numero que indica que no existe algo que no halla:-1
    ubicacion=cadena1.find_first_not_of("mediodia es 12 pm; medianoche no es." );
    cout<<"\n(find_first_not_of)\"mediodia es 12 pm; medianoche no es.\" devuelve: "<<ubicacion<<endl;
    */

    /*
    // el compilador concatena todas las partes en una cadena
    string cadena1( "Los valores en cualquier subarbol izquierdo"
    "\nson menos que el valor en el"
    "\nnodo padre y los valores en"
    "\ncualquier subarbol derecho son mayores"
    "\nque el valor en el nodo padre" );

    cout << "Cadena original:\n" << cadena1 << endl << endl;

    // elimina todos los caracteres de (e incluyendo a) la ubicación 72
    // hasta el final de cadena1
    cadena1.erase( 72 );

    // imprime una nueva cadena
    cout << "Cadena original despues de erase:\n" << cadena1
    << "\n\nDespues del primer reemplazo:\n";

    int unsigned posicion = cadena1.find( " " ); // busca el primer espacio

    // reemplaza todos los espacios con un punto
    while ( posicion != string::npos ) //  string::npos es cuando no halla lo que quería
    {
    cadena1.replace( posicion, 1, "." ); //replace es reemplazar (la posicion que quiere reemp., cuantos caracteres quiere reemp desde ahí, el reemplazo)
    posicion = cadena1.find( " ", posicion + 1 ); // itera la posicion para delante
    } // fin de while

    cout << cadena1 << "\n\nDespues del segundo reemplazo:\n";

    posicion = cadena1.find( "." ); // busca el primer periodo

    // reemplaza todos los puntos con dos signos de punto y coma
    // NOTA: esto sobrescribirá los caracteres
    while ( posicion != string::npos )
    {
    cadena1.replace( posicion, 2, "xxxxx;;yyy", 5, 2 );
    posicion = cadena1.find( ".", posicion + 1 );
    } // fin de while

    cout << cadena1 << endl;

    */

    //INSERCION DE CARACTERES EM UN OBJETO STRING

    //
    string cadena1( "CADENAS" ); // constructor de string con char* arg
    const char *ptr1 = 0; // inicializa *ptr1
    int longitud = cadena1.length();
    char *ptr2 = new char[ longitud + 1 ]; // incluyendo el carácter nulo67 // copia caracteres de cadena1 a la memoria asignada
    cadena1.copy( ptr2, longitud, 0 ); // copia cadena1 a ptr2 char*
    ptr2[ longitud ] = '\0'; // agrega el terminador nulo

    cout << "el objeto string cadena1 es " << cadena1
    << "\ncadena1 convertida a una cadena estilo C es "
    << cadena1.c_str() << "\nptr1 es ";

    // Asigna al apuntador ptr1 el valor const char * devuelto por
    // la función data(). NOTA: ésta es una asignación potencialmente
    // peligrosa. Si se modifica cadena1, el apuntador ptr1 se
    // puede hacer inválido.
    ptr1 = cadena1.data();

    // imprime cada carácter usando un apuntador
    for ( int i = 0; i < longitud; i++ )
    {
        cout << *( ptr1 + i ); // usa aritmética de apuntadores
    }

    cout << "\nptr2 es " << ptr2 << endl;
    delete [] ptr2; // reclama la memoria asignada en forma dinámica

}

