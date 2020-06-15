#ifndef TOOLS_H
#define TOOLS_H

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <bitset>
#include <NTL/ZZ.h>
#include <NTL/vector.h>
#include <random>

using namespace std;
using namespace NTL;

class Tools
{
public:
	int modulo(int a, int n);
	ZZ modulo(ZZ a, ZZ n);
	int MCD(int x, int y);
	ZZ MCD(ZZ x, ZZ y);
	int suma(int, int);
	int resta(int, int);
	int multiplicacion(int, int);
	typedef int(*pf)(int, int);
	int ejecuta(int a, pf func, int b, int n);
	int XmodN_op_YmodN_todo_modN(int x, pf funcion, int y, int n);
	int inversa_mult_de_a_en_Zn(int n, int a);
	ZZ inversa_mult_de_a_en_Zn(ZZ n, ZZ a);
	void print_AlgoritmoExtendido_Euclides(int a, int b);
	int Print_mcd(int a, int b);
	void Print_Inversas_Add(int conjuntoZ);
	void Print_Inversas_Mult(int conjuntoZ);
	long long Num_Aleatorio(long long maxi);
	ZZ pow(ZZ base, ZZ exp);
	ZZ pow_base_exp__modulo_mod(ZZ base, ZZ exp, ZZ mod);
	void Generar_num_Primos_hasta_n_en_vector_v(long long n, Vec<ZZ>& v);
};

#endif // TOOLS_H
