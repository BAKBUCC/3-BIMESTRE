#ifndef AFIN_H
#define AFIN_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include "Tools.h"

using namespace std;

class Afin
{
public:
	Afin(string);
	Afin(string,int,int);
	string Cifrar(string);
	string Descifrar(string);
	string Alfabeto;
	int a, b;
private:
	void GenerarClaves();
	Tools t;
	int inv_a, j, pos, mod, tamanho; //claves
	string new_Mensaje;
	string::iterator i;
};


#endif // AFIN_H
