#include <iostream>

using namespace std;

void AlgoritmoExtendido_Euclides(int a, int b)
{
    int r1=a,r2=b;
    int s1=1,s2=0;
    int t1=0,t2=1;
    int q,r,s,t;
    int mcd_a_b;

    while(r2>0)
    {
        q=r1/r2;

        r=r1-(q*r2);
        r1=r2;r2=r;

        s=s1-(q*s2);
        s1=s2;s2=s;

        t=t1-(q*t2);
        t1=t2;t2=t;
    }
    mcd_a_b=r1;s=s1;t=t1;
    cout<<"mcd(a,b): "<<mcd_a_b<<"="<<a<<"(x) + "<<b<<"(y)"<<endl;
    cout<<"x: "<<s<<endl;
    cout<<"y: "<<t<<endl;
}

int inversa_mult_de_b_en_Za(int a, int b)
{
    int r1=a,r2=b;
    int s1=1,s2=0;
    int t1=0,t2=1;
    int q,r,s,t;
    int mcd_a_b;

    while(r2>0)
    {
        q=r1/r2;

        r=r1-(q*r2);
        r1=r2;r2=r;

        s=s1-(q*s2);
        s1=s2;s2=s;

        t=t1-(q*t2);
        t1=t2;t2=t;
    }
    mcd_a_b=r1;s=s1;t=t1;
    return t;
}

int modulo(int a, int n)
{
    if(n<0)
    {
        cout << "n es menor a 0" << endl;
        return 0;
    }
    int q;
    q = a / n;
    int r;
    r = a - (q * n);
    if (r < 0)
    {
        q--;
        r = a - (q * n);
    }
    return r;
}

int main()
{
    int a,b;//a=144,b=89;
    cout<<"a:";
    cin>>a;
    cout<<"\nb:";
    cin>>b;

    if(a<b)
    {
        swap(a,b);
    }
    AlgoritmoExtendido_Euclides(a,b);
    cout<<"inversa de "<<b<<" en Z_"<<a<<": ";
    cout<<modulo(inversa_mult_de_b_en_Za(a,b),a)<<endl;
    cout<<modulo(85573,1260);
    return 0;
}
