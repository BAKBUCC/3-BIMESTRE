#include "Afin.h"

string Abc_mayus_minus("abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.");
string Abc_min("abcdefghijklmnopqrstuvwxyz");
string Abc_clase("ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890");

int main()
{
	typedef Afin A;

	string m,c,d;
	int clave_a, clave_b;
//	getline(cin, m);
//
//	A emisor(Abc_clase);
//
//	c = emisor.Cifrar(m);

	getline(cin,c);
	cin>>clave_a;
	cin>>clave_b;

	A receptor(Abc_clase, clave_a, clave_b);

	d = receptor.Descifrar(c);
	cout << d << endl;


	return 0;
}
