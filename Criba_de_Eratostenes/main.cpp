#include <iostream>

using namespace std;


int main()
{
    long long unsigned n,i,j,r,s;
    cin>>n;
    bool * noPrimo = new bool [n/2]();//ninguno es primo

    cout<< 2 <<" , "<< 3 <<" , ";

    for (i = 5, r = 2; i <= n; i += r, r = 6 - r) {//i avanza (5, 7, 11, 13, 17 ...) +2,+4,+2,+4,...para no tomar los valores multiplos de 2 y 3.

        if (!noPrimo [i / 3]) {

            cout<< i << " , ";

            for (j = i * i, s = r; j < n; j +=(s * i), s = 6 - s)
                noPrimo [j / 3] = true;
        }
    }
    return 0;
}
