#include <iostream>

using namespace std;

int Algoritmo_1(int a, int b, int i)
{
    cout<<"\nVuelta "<<i+1<<endl;
    cout<<"a: "<<a;
    cout<<"\tb: "<<b<<endl;
    int *r=new int;
    *r=a%b;
    cout<<"residuo: "<<a<<" % "<<b<<" : "<<*r<<endl;

    if(*r==0)
    {
        cout<<"residuo : 0"<<endl;
        cout<<"(final) retornamos como mcd a b("<<b<<")"<<endl;
        return b;
    }
    else
    {
        cout<<"residuo diferente de 0"<<endl;
        cout<<"a = "<<b<<" (b)"<<endl;
        a=b;
        cout<<"b = "<<*r<<" (residuo)"<<endl;
        b=*r;
    }
    delete r;
    i++;
    return Algoritmo_1(a,b,i);
}

int Algoritmo_2(int a, int b, int i)
{
    cout<<"\nVuelta "<<i+1<<endl;
    cout<<"a: "<<a;
    cout<<"\tb: "<<b<<endl;

    int *r=new int;
    *r=a%b;
    cout<<"residuo: "<<a<<" % "<<b<<" : "<<*r<<endl;

    if(*r==0)
    {
        cout<<"residuo : 0"<<endl;
        cout<<"(final) retornamos como mcd a b("<<b<<")"<<endl;
        return b;
    }
    if(*r>b/2)
    {
        cout<<"el residuo ("<<*r<<") es mayor que la mitad de b ("<<(b/2)<<")"<<endl;
        cout<<"por lo tanto: el residuo = b ("<<b<<") - residuo ("<<*r<<") = "<<b-*r<<endl;
        *r=b-*r;
    }

    cout<<"a = "<<b<<" (b)"<<endl;
    a=b;
    cout<<"b = "<<*r<<" (residuo)"<<endl;
    b=*r;
    i++;
    delete r;
    return Algoritmo_2(a,b,i);
}

int Algoritmo_3(int unsigned a, int unsigned b, int i)
{
    cout<<"\nVuelta "<<i+1<<endl;
    cout<<"a: "<<a;
    cout<<"\tb: "<<b<<endl;
    if (b==0)
    {
        cout<<"b = 0"<<endl;
        cout<<"(final) retornamos como mcd: a("<<a<<")"<<endl;
        return a;
    }
    cout<<"retornamos a como b ("<<b<<")"<<endl;
    cout<<"b como a%b ("<<a%b<<")"<<endl;
    i++;
    return Algoritmo_3(b,a%b,i);
}

int Algoritmo_4(int unsigned a, int unsigned b, int i)
{
    cout<<"\nVuelta "<<i+1<<endl;
    cout<<"a: "<<a;
    cout<<"\tb: "<<b<<endl;
    if(a<0)
    {
        cout<<"a=|a|("<<-a<<")"<<endl;
        a=-a;
    }
    if(b<0)
    {
        cout<<"b=|b|("<<-b<<")"<<endl;
        b=-b;
    }
    if(b>a)
    {
        cout<<"como b("<<b<<") > a("<<a<<")"<<endl;
        cout<<"retornamos a como b("<<b<<") y b como a(("<<a<<")"<<endl;
        return Algoritmo_4(b,a,i);
    }
    else if(b==0)
    {
        cout<<"b=0, por lo que ahora el mcd: a("<<a<<")"<<endl;
        return a;
    }
    else if(a%2==0 && b%2==0)
    {
        cout<<"si a("<<a<<") y b("<<b<<") son pares"<<endl;
        cout<<"entonces retornamos \"a\" como a/2("<<a/2<<") y \"b\" como b/2("<<b/2<<")"<<endl;
        cout<<"y lo que nos retorne lo multiplicamos por 2"<<endl;
        return 2*Algoritmo_4(a/2,b/2,i);
    }
    else if(a%2==0 && b%2==1)
    {
        cout<<"si a("<<a<<") es par y b("<<b<<") es impar"<<endl;
        cout<<"entonces retornamos \"a\" como a/2("<<a/2<<") y \"b\""<<endl;
        return Algoritmo_4(a/2,b,i);
    }
    else if(a%2==1 && b%2==0)
    {
        cout<<"si a("<<a<<") es impar y b("<<b<<") es par"<<endl;
        cout<<"entonces retornamos \"a\" y \"b\" como b/2("<<b/2<<")"<<endl;
        return Algoritmo_4(a,b/2,i);
    }
    else
    {
        int *y=new int;
        *y=b;
        if(a<0)
        {
            cout<<"a=|a|("<<-a<<")"<<endl;
            a=-a;
        }
        if(b<0)
        {
            cout<<"b=|b|("<<-b<<")"<<endl;
            b=-b;
        }
        cout<<"retornamos \"a\" como (|a|-|b|)/2->("<<(a-b)/2<<") y el valor original de b("<<*y<<")"<<endl;
        return Algoritmo_4((a-b)/2,*y,i);
        delete y;
    }
}

int Algoritmo_5(int unsigned x, int unsigned y, int i)
{
    i++;
    cout<<"\nVuelta "<<i<<endl;
    cout<<"x: "<<x;
    cout<<"\ty: "<<y<<endl;
    int *g= new int;
    *g=1;
    cout<<"creamos una nueva variable \"g\": "<<*g<<endl;
    while(x%2==0 && y%2==0)
    {
        i++;
        cout<<"\nVuelta "<<i<<endl;
        cout<<"mientras que \"x\"("<<x<<") y \"y\"("<<y<<") son pares"<<endl;
        cout<<"dividimos a \"x\" y \"y\" entre 2 : "<<x/2<<" y "<<y/2<<endl;
        cout<<"y multiplicamos a g por 2: "<<(*g)*2<<endl;
        x=x/2;
        y=y/2;
        (*g)=(*g)*2;
    }
    while(x!=0)
    {
        i++;
        cout<<"\nVuelta "<<i<<endl;
        cout<<"\"x\"("<<x<<") es diferente de 0"<<endl;
        while(x%2==0)
        {
            cout<<"mientras que \"x\"("<<x<<") es par"<<endl;
            cout<<"dividimos a \"x\" entre 2 : "<<x/2<<endl;
            x=x/2;
        }
        while(y%2==0)
        {
            cout<<"mientras que \"y\"("<<y<<") es par"<<endl;
            cout<<"dividimos a \"y\" entre 2 : "<<y/2<<endl;
            y=y/2;
        }

        int *t=new int;
        cout<<"creamos una nueva variable \"t\""<<endl;
        if(x<y)
        {
            cout<<"si \"x\"("<<x<<") < \"y\"("<<y<<") entonces \"t\" es (-(x-y))/2: "<<(-(x-y))/2<<endl;
            (*t)=(-(x-y))/2;
        }
        else
        {
            cout<<"si \"x\"("<<x<<") > \"y\"("<<y<<") entonces \"t\" es (x-y)/2: "<<(x-y)/2<<endl;
            (*t)=(x-y)/2;
        }

        if(x>=y)
        {
            cout<<"si \"x\"("<<x<<") >= \"y\"("<<y<<") entonces \"x\" es \"t\" ("<<*t<<")"<<endl;
            x=(*t);
        }
        else
        {
            cout<<"si \"x\"("<<x<<") < \"y\"("<<y<<") entonces \"y\" es \"t\" ("<<*t<<")"<<endl;
            y=(*t);
        }
        delete t;
    }
    cout<<"retornamos como cmd :  \"g\"("<<*g<<") por \"y\"("<<y<<")"<<endl;
    return ((*g)* y);
    delete g;
}

int Algoritmo_6(int a, int b, int i)
{
    while(a!=b)
    {
        i++;
        cout<<"\nVuelta "<<i<<endl;
        cout<<"a: "<<a;
        cout<<"\tb: "<<b<<endl;
        cout<<"mientras que \"a\"("<<a<<") es diferente que \"b\"("<<b<<")"<<endl;
        if(a>b)
        {
            cout<<"si \"a\"("<<a<<") > \"b\"("<<b<<")"<<endl;
            cout<<"a \"a\" se le resta \"b\"("<<b<<") y el nuevo valor de \"a\" sera "<<a-b<<endl;
            a-=b;
        }
        else
        {
            cout<<"si \"a\"("<<a<<") <= \"b\"("<<b<<")"<<endl;
            cout<<"a \"b\" se le resta \"a\"("<<a<<") y el nuevo valor de \"b\" sera "<<b-a<<endl;
            b-=a;
        }
        i++;
    }
    cout<<"el cmd será \"a\"("<<a<<")"<<endl;
    return a;
}

int main()
{
    int a=412;
    int b=260;
    int i=0;
    cout<<"ALGORITMO 1"<<endl;
    cout<<"-----------"<<endl;
    cout<<"mcd de "<<a<<" y "<<b<<" : "<<Algoritmo_1(a,b,i)<<endl;
    cout<<"\n\nALGORITMO 2"<<endl;
    cout<<"-----------"<<endl;
    cout<<"mcd de "<<a<<" y "<<b<<" : "<<Algoritmo_2(a,b,i)<<endl;
    cout<<"\n\nALGORITMO 3"<<endl;
    cout<<"-----------"<<endl;
    cout<<"mcd de "<<a<<" y "<<b<<" : "<<Algoritmo_3(a,b,i)<<endl;
    cout<<"\n\nALGORITMO 4"<<endl;
    cout<<"-----------"<<endl;
    cout<<"mcd de "<<a<<" y "<<b<<" : "<<Algoritmo_4(a,b,i)<<endl;
    cout<<"\n\nALGORITMO 5"<<endl;
    cout<<"-----------"<<endl;
    cout<<"mcd de "<<a<<" y "<<b<<" : "<<Algoritmo_5(a,b,i)<<endl;
    cout<<"\n\nALGORITMO 6"<<endl;
    cout<<"-----------"<<endl;
    cout<<"mcd de "<<a<<" y "<<b<<" : "<<Algoritmo_6(a,b,i)<<endl;
}
